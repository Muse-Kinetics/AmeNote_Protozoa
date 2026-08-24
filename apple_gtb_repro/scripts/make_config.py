#!/usr/bin/env python3
"""Build a usbMIDI2DescriptorBuilder config.json for one GTB repro variant.
Usage: make_config.py <out.json> <variant-label> <mode> [args...]

Modes:
  uni-pairs <numGroups>
  bidi-single <numGroups>
  asym <numIn> <numOut>
  no-gtb
  mixed-uni-bi <numBidi> <numIn> <numOut>
      numBidi bidirectional single-group blocks (groups 1..numBidi) +
      numIn IN-only blocks (groups 1..numIn, reused range) +
      numOut OUT-only blocks (groups 1..numOut, reused range)
  mixed-m1m2
      Fixed shape: 4 bidi MIDI2.0 (groups 1-4) + 4 bidi MIDI1.0 (groups 5-8)
      + 4 uni pairs MIDI2.0 (groups 9-12, 8 blocks) + 4 uni pairs MIDI1.0
      (groups 13-16, 8 blocks). 24 blocks total, spans all 16 groups once each.
  multi-group <size1> <size2> ...
      Sequential, contiguous, non-overlapping bidirectional blocks B1..BN,
      each spanning <sizeI> groups. Sum of sizes must be <= 16.
  bidi-single-m1 <numGroups>
      Same as bidi-single but forces bMIDIProtocol=1 (MIDI1.0, 0x02) on every
      block instead of the config-level default (MIDI2.0). No MIDI2.0 blocks.
"""
import json, sys

out_path, label, mode = sys.argv[1], sys.argv[2], sys.argv[3]
args = sys.argv[4:]

blocks = []
if mode == "uni-pairs":
    n = int(args[0])
    for g in range(1, n+1):
        blocks.append({"name": f"Group{g}", "in": True,  "out": False, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
        blocks.append({"name": f"Group{g}", "in": False, "out": True,  "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "bidi-single":
    n = int(args[0])
    for g in range(1, n+1):
        blocks.append({"name": f"Group{g}", "in": True, "out": True, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "asym":
    numIn, numOut = int(args[0]), int(args[1])
    for g in range(1, numIn+1):
        blocks.append({"name": f"Group{g}In", "in": True, "out": False, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(1, numOut+1):
        blocks.append({"name": f"Group{g}Out", "in": False, "out": True, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "no-gtb":
    blocks = []
elif mode == "mixed-uni-bi":
    numBidi, numIn, numOut = int(args[0]), int(args[1]), int(args[2])
    for g in range(1, numBidi+1):
        blocks.append({"name": f"Group{g}Bidi", "in": True, "out": True, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(1, numIn+1):
        blocks.append({"name": f"Group{g}In", "in": True, "out": False, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(1, numOut+1):
        blocks.append({"name": f"Group{g}Out", "in": False, "out": True, "firstGroup": g, "numOfGroups": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "mixed-m1m2":
    for g in range(1, 5):
        blocks.append({"name": f"Group{g}BidiM2", "in": True, "out": True, "firstGroup": g, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(5, 9):
        blocks.append({"name": f"Group{g}BidiM1", "in": True, "out": True, "firstGroup": g, "numOfGroups": 1, "protocol": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(9, 13):
        blocks.append({"name": f"Group{g}M2In", "in": True, "out": False, "firstGroup": g, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
        blocks.append({"name": f"Group{g}M2Out", "in": False, "out": True, "firstGroup": g, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
    for g in range(13, 17):
        blocks.append({"name": f"Group{g}M1In", "in": True, "out": False, "firstGroup": g, "numOfGroups": 1, "protocol": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
        blocks.append({"name": f"Group{g}M1Out", "in": False, "out": True, "firstGroup": g, "numOfGroups": 1, "protocol": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "multi-group":
    sizes = [int(a) for a in args]
    assert sum(sizes) <= 16, f"sizes sum to {sum(sizes)}, must be <= 16"
    g = 1
    for idx, size in enumerate(sizes, start=1):
        blocks.append({"name": f"Block{idx}", "in": True, "out": True, "firstGroup": g, "numOfGroups": size, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
        g += size
elif mode == "bidi-single-m1":
    n = int(args[0])
    for g in range(1, n+1):
        blocks.append({"name": f"Group{g}", "in": True, "out": True, "firstGroup": g, "numOfGroups": 1, "protocol": 1, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
elif mode == "custom":
    # Tokens like "m2-bi-1g:1" = protocol(m1|m2)-type(bi|uniin|uniout)-spanGg:count
    # Blocks are placed sequentially, contiguous, non-overlapping, starting at group 1.
    import re
    g = 1
    for tok in args:
        m = re.match(r'^(m1|m2)-(bi|uniin|uniout)-(\d+)g:(\d+)$', tok)
        assert m, f"bad token {tok!r}, expected e.g. m2-bi-1g:1"
        proto_s, typ, span_s, count_s = m.groups()
        proto = 1 if proto_s == "m1" else 2
        span = int(span_s)
        count = int(count_s)
        in_, out_ = {"bi": (True, True), "uniin": (True, False), "uniout": (False, True)}[typ]
        for _ in range(count):
            name = f"G{g}{proto_s.upper()}{typ.capitalize()}"
            blocks.append({"name": name, "in": in_, "out": out_, "firstGroup": g, "numOfGroups": span, "protocol": proto, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0})
            g += span
    assert g - 1 <= 16, f"needs {g-1} groups, only 16 available"
else:
    raise SystemExit(f"unknown mode {mode}")

config = {
    "prefix": "",
    "CDC": 0,
    "idVendor": "0xCafe",
    "idProduct": "0x4001",
    "manufacturer": "AmeNote",
    "manufacturerId": "0x7E0000",
    "version": "0x00010000",
    "product": f"ProtoZOA {label}"[:98],
    "serialNumber": "GTBREPRO00000001",
    "power": 50,
    "endpoints": [
        {
            "name": f"ProtoZOA {label}"[:98],
            "MIDI1Itf": [
                {"in": True, "out": True, "name": "Legacy"}
            ],
            "defaultGTBProtocol": 2,
            "blocks": blocks
        }
    ]
}

with open(out_path, "w") as f:
    json.dump(config, f, indent=2)
print(f"wrote {out_path}: mode={mode} args={args} -> {len(blocks)} blocks")
