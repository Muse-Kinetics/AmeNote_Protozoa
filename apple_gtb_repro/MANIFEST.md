# GTB Repro Artifact Manifest — AppleMIDIUSBDriver Investigation

For each firmware image below: does it enumerate at all in macOS/CoreMIDI, do individual GTB
block names show up distinctly in `sendsysex -l`, — for GTBs spanning more than one Group —
does macOS differentiate/number the per-group port entries within that block or show the same
name repeated once per group, and does the GTB's declared `bMIDIProtocol` (MIDI1.0 vs MIDI2.0)
have any bearing on any of the above.

All descriptors generated via the official MIDI Association tool
(`midi2-dev/usbMIDI2DescriptorBuilder`, `buildTinyUSBDescriptors()`), never hand-rolled.
Flashed via SWD using a halt-at-`main()`-before-`tusb_init()` methodology (device confirmed
genuinely off the USB bus during the CoreMIDI cache-clear step) — see `protozoa-gtb-repro.md`
§4 in the mimic_hub repo for the full methodology writeup. Hardware: AmeNote ProtoZOA
(RP2040 + TinyUSB), independent of mimic_hub's own LPC55S16 + NXP USB stack.

**At a glance: 37 artifacts (33 single-interface GTB-count sweep + 4 multi-Function
same-class-interface tests, §9).** Of the 33: 23 enumerate cleanly, 10 crash MIDIServer with the identical
`__stack_chk_fail`/`SIGABRT` signature. **The crash correlates with exactly one variable across
every artifact tested: total block count (any type — unidirectional or bidirectional, any
`bMIDIProtocol`) ≥20.** *Correction: an earlier version of this summary stated the variable as
"total **unidirectional** block count ≥20" — that was wrong, caught by inspecting `mixed-m1m2`
and `mixed-uni-bi-8-8-8` closely: both crash with only 16 unidirectional blocks (well under 20)
but 24 **total** blocks (16 unidirectional + 8 bidirectional). The true threshold is total block
count regardless of composition — verified against all 33 artifacts with zero exceptions (see
the raw per-artifact table in §8).* IN/OUT skew, block-type mix, `bMIDIProtocol`, and multi-group
spanning all have zero *additional* effect once total count is accounted for.

Legend: ✅ yes · ❌ no · — not applicable · 💥 crashes MIDIServer (`__stack_chk_fail`/`SIGABRT`)

## 1. Unidirectional pairs (one IN-only + one OUT-only block per group)

| Artifact | Shape | Total blocks | Enumerates? | Individual names shown? |
|---|---|---|---|---|
| `uni-pairs-09` | 9 groups | 18 | ✅ | ✅ — 9 distinct (`Group1`..`Group9`) |
| `uni-pairs-10` | 10 groups | 20 | 💥 crashes | — |
| `uni-pairs-16` | 16 groups ("16×16 unidirectional") | 32 | 💥 crashes | — |

## 2. Asymmetric IN/OUT splits (pure unidirectional blocks, no bidirectional)

| Artifact | Shape | Total blocks | Enumerates? | Individual names shown? |
|---|---|---|---|---|
| `asym-04in-06out` | 4 IN + 6 OUT | 10 | ✅ | ✅ — distinct (`GroupNIn`/`GroupNOut`) |
| `asym-16in-02out` | 16 IN + 2 OUT | 18 | ✅ | ✅ — distinct |
| `asym-16in-03out` | 16 IN + 3 OUT | 19 | ✅ | ✅ — distinct |
| `asym-16in-04out` | 16 IN + 4 OUT | 20 | 💥 crashes | — |
| `asym-04in-16out` | 4 IN + 16 OUT | 20 | 💥 crashes | — |
| `asym-08in-16out` | 8 IN + 16 OUT | 24 | 💥 crashes | — |
| `asym-16in-08out` | 16 IN + 8 OUT | 24 | 💥 crashes | — |
| `asym-12in-16out` | 12 IN + 16 OUT | 28 | 💥 crashes | — |
| `asym-16in-12out` | 16 IN + 12 OUT | 28 | 💥 crashes | — |

**Conclusion (§1+§2, pure-unidirectional configs only):** within this subset, the crash trigger
tracks total block count, threshold exactly between 19 (works) and 20 (crashes). No
per-direction skew effect — confirmed across 6 different skew ratios at/around the boundary,
and 4 more well above it. **Caveat, resolved in §4/§7**: since every config here is 100%
unidirectional, this data alone can't distinguish "total unidirectional block count" from "total
block count of any type" — §4's mixed-type configs (16 unidirectional + 8 bidirectional = 24
total, still crashes) resolve this: it's total count of any type, not unidirectional count
specifically. See the manifest's "at a glance" summary for the corrected statement.

## 3. Bidirectional single-group blocks (one block per group, matched IN+OUT)

| Artifact | Shape | Protocol | Total blocks | Enumerates? | Individual names shown? |
|---|---|---|---|---|---|
| `bidi-single-02` | 2 groups | MIDI2.0 (`bMIDIProtocol=0x11`) | 2 | ✅ | ✅ — 2 distinct |
| `bidi-single-08` | 8 groups | MIDI2.0 | 8 | ✅ | ✅ — 8 distinct |
| `bidi-single-16` | 16 groups ("16×16 bidirectional") | MIDI2.0 | 16 (32 Group Terminals) | ✅ | ✅ — 16 distinct |
| `bidi-single-m1-01` | 1 group | **MIDI1.0** (`bMIDIProtocol=0x02`) | 1 | ✅ | ✅ — 1 |
| `bidi-single-m1-02` | 2 groups | **MIDI1.0** | 2 | ✅ | ✅ — 2 distinct |
| `bidi-single-m1-04` | 4 groups | **MIDI1.0** | 4 | ✅ | ✅ — 4 distinct |
| `bidi-single-m1-08` | 8 groups | **MIDI1.0** | 8 | ✅ | ✅ — 8 distinct |
| `bidi-single-m1-16` | 16 groups | **MIDI1.0** | 16 (32 Group Terminals) | ✅ | ✅ — 16 distinct |

**Conclusion:** never crashes, regardless of count — up to 16 blocks / 32 Group Terminals,
more than the unidirectional case's crashing 20-Group-Terminal configuration. The bug is
specific to many-*unidirectional*-block layouts, not simply "many blocks" or "many Group
Terminals." **The `bidi-single-m1-*` series closes a specific gap**: `mixed-m1m2` (§4) was
the only prior artifact with any bidirectional MIDI1.0 blocks, and it crashed — but that
crash tracked total block count (24), not protocol, leaving it unconfirmed whether a
*working* (low-count) all-MIDI1.0 bidirectional descriptor behaves the same as the MIDI2.0
`bidi-single-*` series. It does, exactly, up to 16/16 — `bMIDIProtocol` has no bearing on
enumeration or naming behavior for bidirectional single-group blocks. Every `bidi-single-m1-*`
device also correctly exposes the native UMP "MIDI 2.0" endpoint alongside the MIDI1.0-tagged
GTB ports — the raw UMP stream access point is present regardless of the GTB's own
declared protocol.

## 4. Mixed block types in one descriptor

| Artifact | Shape | Total blocks | Enumerates? | Individual names shown? |
|---|---|---|---|---|
| `mixed-uni-bi-8-8-8` | 8 bidirectional + 8 IN-only + 8 OUT-only | 24 | 💥 crashes | — |
| `mixed-m1m2` | 4 bidi MIDI2.0 + 4 bidi MIDI1.0 + 4 uni-pairs MIDI2.0 (8 blocks) + 4 uni-pairs MIDI1.0 (8 blocks) | 24 | 💥 crashes | — |

**Conclusion:** the crash is driven by total block count alone (24 in both cases here), not by
block type or `bMIDIProtocol` mix — consistent with §1/§2. Mixing bidirectional blocks in does
not "dilute" or protect against the crash; it's the raw block count in the descriptor that
matters, regardless of composition.

## 5. Non-compliant: zero GTB blocks declared

| Artifact | Shape | Enumerates? | Individual names shown? |
|---|---|---|---|
| `no-gtb` | Alt-1 (MIDI2.0/UMP) declared, zero GTB blocks | ✅ (MIDI 1.0 only) | — (no MIDI2.0/UMP port constructed at all; only the Alt-0 "Legacy" MIDI 1.0 port appears) |

**Conclusion:** does not crash or hang. CoreMIDI simply does not build a MIDI 2.0/UMP entity
when there are no GTBs to build one from, falling back cleanly to Alt-0 MIDI 1.0. Real
empirical data for the non-compliant case Torrey Walker's Contribution doc discusses without
confirming what real macOS actually does.

## 6. GTBs spanning multiple groups (the per-group-naming question)

All four bidirectional, contiguous, non-overlapping across all 16 groups (spec-compliant GTBS).

| Artifact | Block layout | Enumerates? | Individual **block** names shown? | Per-group differentiation within a block? |
|---|---|---|---|---|
| `multigroup-4-2-2-8` | B1=4 groups, B2=2, B3=2, B4=8 | ✅ | ✅ — 4 distinct (`Block1`..`Block4`) | ❌ — each block's name repeats identically once per group it spans (e.g. `Block4` appears 8 times, byte-identical) |
| `multigroup-8-8` | B1=8 groups, B2=8 groups | ✅ | ✅ — 2 distinct | ❌ — same repeat pattern |
| `multigroup-2x8` | B1..B8, each 2 groups | ✅ | ✅ — 8 distinct | ❌ — each pair repeats identically |
| `multigroup-15-1` | B1=15 groups, B2=1 group | ✅ | ✅ — 2 distinct | ❌ — `Block1` repeats 15 times identically |

**Conclusion:** confirms the structural finding from the original mimic_hub investigation
(`decisions.md` gotcha #20, USB MIDI 2.0 spec Table 5-6): GTB naming (`iBlockItem`) is
per-**block**, not per-Group-Terminal. macOS/CoreMIDI does not add any numeric suffix or other
differentiation to distinguish the repeated ports within a single multi-group block — a block
spanning N groups produces N *identically-named* ports in `sendsysex -l`/CoreMIDI's classic
`MIDIEndpointRef` enumeration, with no way for `rtmidi`-based tooling to tell them apart by
name alone. This holds regardless of how many groups a block spans (2 through 15) or how many
blocks are in the descriptor (2 through 8).

## 7. Fine-grained protocol/type mixes at low block counts

Purpose-built to probe the composition-independence claim (§4) at trivial scale, with every
combination of protocol × type present in a single small descriptor. All bidirectional-heavy;
none approach the ≥20-block crash threshold.

| Artifact | Shape | Total blocks | Enumerates? | Individual names shown? |
|---|---|---|---|---|
| `mixed6-x1` | 1 each: M2-bi, M2-IN, M2-OUT, M1-bi, M1-IN, M1-OUT (1 group each) | 6 | ✅ | ✅ — 6 distinct |
| `mixed6-x2` | Same 6 categories, ×2 each | 12 | ✅ | ✅ — 12 distinct |
| `mixed-bi-1g-x2` | 2× M2-bi + 2× M1-bi, 1 group each | 4 | ✅ | ✅ — 4 distinct |
| `mixed-bi-2g-x1` | 1× M2-bi + 1× M1-bi, 2 groups each | 2 | ✅ | ✅ — 2 distinct (each repeats once per group, per §6) |
| `mixed-bi-2g-x2` | 2× M2-bi + 2× M1-bi, 2 groups each | 4 | ✅ | ✅ — 4 distinct |
| `mixed-bi-8g-x1` | 1× M2-bi + 1× M1-bi, 8 groups each (fills all 16) | 2 | ✅ | ✅ — 2 distinct |

**Conclusion:** every combination of protocol (M1/M2) × type (bidirectional/IN-only/OUT-only) ×
group-span, at low total block counts, enumerates correctly with proper per-block naming and
correct IN/OUT-to-host-port-direction mapping (an OUT-only GTB, i.e. device→host, correctly
appears as a host MIDI *Input*; an IN-only GTB correctly appears as a host MIDI *Output*). No
combination tested produces any anomaly. Reinforces §4's finding with much finer-grained
coverage: composition simply doesn't matter below the block-count threshold.

## 8. Full verification: total block count vs. crash, all 33 artifacts

Computed directly from each artifact's generator config (not hand-tallied), sorted by total
block count, to make the "total count ≥20 ⇒ crash, else works" rule auditable at a glance:

```
total | uni | bidi | result | artifact
  1   |  0  |  1   | works  | bidi-single-m1-01, no-gtb
  2   |  0  |  2   | works  | bidi-single-02, bidi-single-m1-02, multigroup-15-1, multigroup-8-8,
                              mixed-bi-2g-x1, mixed-bi-8g-x1
  4   |  0  |  4   | works  | bidi-single-m1-04, multigroup-4-2-2-8, mixed-bi-1g-x2, mixed-bi-2g-x2
  6   |  4  |  2   | works  | mixed6-x1
  8   |  0  |  8   | works  | bidi-single-08, bidi-single-m1-08, multigroup-2x8
 10   | 10  |  0   | works  | asym-04in-06out
 12   |  8  |  4   | works  | mixed6-x2
 16   |  0  | 16   | works  | bidi-single-16, bidi-single-m1-16
 18   | 18  |  0   | works  | asym-16in-02out, uni-pairs-09
 19   | 19  |  0   | works  | asym-16in-03out
 20   | 20  |  0   | CRASH  | asym-04in-16out, asym-16in-04out, uni-pairs-10
 24   | 24  |  0   | CRASH  | asym-08in-16out, asym-16in-08out
 24   | 16  |  8   | CRASH  | mixed-m1m2, mixed-uni-bi-8-8-8
 28   | 28  |  0   | CRASH  | asym-12in-16out, asym-16in-12out
 32   | 32  |  0   | CRASH  | uni-pairs-16
```

Every `works` row has total ≤19; every `CRASH` row has total ≥20; **zero exceptions**. The
`uni`/`bidi` split columns show composition varies freely on both sides of the boundary with no
effect — most tellingly the two 24-total rows (24-uni-0-bidi vs. 16-uni-8-bidi), which crash
identically despite an 8-block difference in unidirectional count.

## 9. Multiple USB MIDI Functions on one device (same-class multi-interface)

A separate question from §1-8's single-interface GTB-count crash: does macOS support a
composite device with *two independent MIDIStreaming interfaces* (two `IAD`+`AudioControl`+
`MIDIStreaming` Functions, each its own GTB set/endpoints), as opposed to one interface with
many GTB blocks? Motivated by USB MIDI 2.0 spec §4's "Operational Model" language ("the USB
MIDI function exposes a single MIDIStreaming interface") and prior guidance seen in
contributions/forum discussion against multiple UMP Endpoints on one USB device — for the USB
transport specifically, a UMP Endpoint maps 1:1 to a MIDIStreaming interface's Alt-Setting 1,
so "avoid multiple UMP Endpoints" and "avoid multiple MIDIStreaming interfaces" describe the
same constraint from two vocabulary angles.

Two real `tusb_ump` driver bugs (§10) were found and fixed along the way — both are generic,
protocol-independent driver correctness bugs (interface-instance routing, descriptor-length
accounting), not artifacts of any of the descriptor shapes below. All four artifacts here
reflect firmware with both fixes applied.

| Artifact | Shape | Result |
|---|---|---|
| `dual-itf-m2-bidi-1g` | 2 MIDIStreaming interfaces, each 1 bidirectional MIDI2.0 1-group GTB (`Itf1Bi`/`Itf2Bi`) | Enumerates, no crash. Only **one** interface (itf 3, `Itf2Bi`) negotiated to Alt-Setting 1 (MIDI2.0); the other (itf 1) silently stayed at Alt-Setting 0, no error logged, no port exposed for it at all. Confirmed via live firmware state (`_umpd_itf[].ump_interface_selected`) as well as CoreMIDI. |
| `dual-itf-m2-bidi-1g-uniq` | Same shape, but every string made fully unique per Function — GTB block name, legacy MIDI1 port name, MIDIStreaming interface name, **and** the IAD `iFunction`/AudioControl `iInterface` strings, previously hardcoded to `0` (unset) in `usbMIDI2DescriptorBuilder`'s `buildTinyUSBDescriptors()` for every device it has ever generated — patched to wire these up (`buildUSBDescriptors.js`, forked to `Muse-Kinetics/usbMIDI2DescriptorBuilder`) specifically to test this | Identical result pattern: only **one** interface negotiated (this time itf 1, `AlphaBlock`; itf 3, `BetaBlock`, silently skipped) — which interface wins is not consistent between runs. Rules out naming/string-collision as the cause. |
| `midi-cdc-heartbeat` | Control case: one MIDIStreaming interface (1 bidirectional MIDI2.0 1-group GTB) + one CDC-ACM serial interface — a genuine composite device, but **different classes** | Enumerates cleanly, both interfaces fully functional — verified via a live "hello world N" heartbeat over the CDC port, incrementing once per second, plus normal single-interface MIDI2.0 enumeration. No negotiation ambiguity, because CDC and MIDI are handled by entirely separate class drivers that never compete for the same interface. |
| `dual-midi1-1x1-2x2` | 2 MIDIStreaming interfaces, **classic USB MIDI 1.0 only** — no Alt-Setting 1, no GTBs, no UMP anything (`blocks: []` in the generator config, which omits Alt-Setting 1's descriptor block entirely). Interface A: 1 embedded IN jack + 1 embedded OUT jack (`IfaceA-In1`/`IfaceA-Out1`). Interface B: 2 in + 2 out (`IfaceB-In1/2`, `IfaceB-Out1/2`) | Same limitation, and more starkly: only Interface A appears in CoreMIDI (`numEntities: 1`, `src: IfaceA-Out1`, `dst: IfaceA-In1`). Interface B is completely absent — not even a generic fallback entity (there's no MIDI2.0/UMP concept to fall back to in pure MIDI1.0). Decisive: rules out any MIDI2.0/UMP-specific explanation. |

**Conclusion:** macOS's USB MIDI driver stack — both the legacy MIDI1.0 class driver and
`AppleMIDIUSBDriver`'s MIDI2.0 path — only ever attaches to **one** MIDIStreaming interface per
composite USB device, independent of protocol version (MIDI1.0 vs MIDI2.0), interface/GTB/IAD
naming, or string uniqueness. The low-level enumerator (`usbaudiod`) correctly sees and creates
a `boxUID` for *both* interfaces every time (confirmed via `log show`); the limitation is
specific to the higher CoreMIDI driver-attachment layer, not descriptor parsing. Composite
devices combining a MIDIStreaming interface with a *different-class* interface (CDC, HID, mass
storage, etc.) are unaffected — `midi-cdc-heartbeat` above confirms that path works cleanly, as
expected, since different-class interfaces are claimed by entirely separate class drivers that
never have to arbitrate over the same interface.

**Practical implication:** the only architecture that reliably exposes multiple independent
MIDI streams from one product on macOS today is either (a) one MIDIStreaming interface with
multiple GTB blocks (§1-8's subject, works up to the ~19-block ceiling), or (b) genuinely
separate USB devices (e.g. behind a real or virtual hub, each with its own Device Descriptor) —
not multiple MIDIStreaming interfaces on one composite device.

## 10. Driver bugs found and fixed during this investigation

Found incidentally while building §9's repro, not part of the original GTB-crash
investigation — both are generic, protocol-independent correctness bugs in third-party driver
code, fixed and submitted upstream separately from this research branch.

- **`tusb_ump` — `umpd_open()` silently swallowing subsequent USB MIDI Functions.** When a
  MIDIStreaming interface declares Alternate Setting 1 (MIDI2.0), `umpd_open()` detected it but
  skipped past it with `drv_len = max_len` ("nothing left to parse in the whole configuration
  descriptor") instead of walking its actual descriptor block. Only correct when the device has
  exactly one USB MIDI Function (`CFG_TUD_UMP == 1`) — with a second Function's `IAD`/interfaces
  following in the same configuration descriptor, this silently swallowed them: TinyUSB's core
  driver-dispatch loop never called `umpd_open()` again for instance 1+, so that Function's
  endpoints were never opened and its `itf_num` was never registered.
- **`tusb_ump` — `umpd_control_xfer_cb()` resolving the wrong UMP instance.** Interface-addressed
  control requests (`SET_INTERFACE`, the GTB `GET_DESCRIPTOR` request) carry the target
  interface number in the request's `wIndex`. This function instead indexed `_umpd_itf[rhport]`
  — `rhport` is the USB controller/root-hub-port number, not an interface instance index.
  Harmless with `CFG_TUD_UMP == 1`; with more instances, always resolved to instance 0
  regardless of which interface the host actually addressed.
  Both fixed on `Muse-Kinetics/tusb_ump` branch `fix-control-xfer-multi-instance`, submitted
  upstream to `midi2-dev/tusb_ump`.
- **`usbMIDI2DescriptorBuilder` — IAD `iFunction`/AudioControl `iInterface` hardcoded to 0.**
  `buildUSBDescriptors.js`'s `buildTinyUSBDescriptors()` never wired these string fields up for
  any device it has ever generated. Fixed to use each endpoint's `name` field (`Muse-Kinetics/
  usbMIDI2DescriptorBuilder`), used to build the `-uniq` naming variant in §9.
- **`AmeNote_Protozoa` — `FreeRTOSConfig.h` never defined `configNUMBER_OF_CORES`.** Only the
  older, pre-merge-SMP-branch name `configNUM_CORES` was set; the vendored FreeRTOS-Kernel SMP
  port and RP2040 port both check `configNUMBER_OF_CORES`, which silently defaulted to 1. This
  codebase has been running single-core the entire time despite clearly intending dual-core
  (`multicore_launch_core1` call and "on both cores" printf already present in `main.c`). Fixing
  the name reactivates genuine dual-core execution — `configUSE_PASSIVE_IDLE_HOOK` and
  `configUSE_CORE_AFFINITY` also had to be defined, both newly-required once real SMP is active.
  **Caveat:** only verified running (not just compiling) on the `USB_MIDI_ECHO` target used for
  this repro; the other 7 targets sharing this header only confirmed as still compiling, not
  flashed/verified on real dual-core. This also reactivates a known, still-unpatched upstream
  TinyUSB RP2040-port race condition (`hw_endpoint_lock_update()` is a documented no-op —
  `rp2040_usb.h`; see upstream PR #2474, open since Feb 2024) under genuine cross-core
  parallelism for the first time in this codebase's history — not hit during this repro's
  testing, but a real risk worth flagging rather than silently shipping. Submitted upstream to
  `midi2-dev/AmeNote_Protozoa` with this caveat noted in the PR description.

## Cross-reference

Full investigation narrative, methodology, and strategic implications for mimic_hub:
`mimic_hub` repo, `.buddy-project/protozoa-gtb-repro.md` and `.buddy-project/decisions.md`
gotchas #22-#25.

Reproducing these artifacts: `apple_gtb_repro/scripts/` holds the config generators
(`make_config.py`, `make_dual_interface.py`, `make_dual_interface_uniq.py`, `make_midi_cdc.py`,
`make_dual_midi1.py`) and the Node wrapper (`gen_descriptors.js`) around the official
`usbMIDI2DescriptorBuilder` tool. The §9/§10 artifacts additionally require
`Muse-Kinetics/usbMIDI2DescriptorBuilder`'s `iFunction`/`iInterface` fix and
`Muse-Kinetics/tusb_ump`'s two driver fixes (pinned via this branch's `.gitmodules` override —
see note at top of that file).
