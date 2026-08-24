#!/usr/bin/env python3
"""Dual-interface repro, pure classic USB MIDI 1.0 -- no MIDI2.0 Alt-Setting 1,
no GTBs, no UMP anything (blocks=[] omits Alt-Setting 1 entirely in the
generator). Interface A: 1 embedded IN jack + 1 embedded OUT jack. Interface
B: 2 embedded IN jacks + 2 embedded OUT jacks. Every jack individually named.
Tests whether macOS's same-class-multi-interface limitation (confirmed for
MIDI2.0/UMP) also applies to plain, decades-old MIDI 1.0 class interfaces.
"""
import json, sys

out_path = sys.argv[1]

def make_endpoint(tag, n_in, n_out):
    jacks = []
    for i in range(1, n_in + 1):
        jacks.append({"in": True, "out": False, "name": f"{tag}-In{i}"})
    for i in range(1, n_out + 1):
        jacks.append({"in": False, "out": True, "name": f"{tag}-Out{i}"})
    return {
        "name": f"ProtoZOA-{tag}",
        "MIDI1Itf": jacks,
        "blocks": []
    }

config = {
    "prefix": "",
    "CDC": 0,
    "idVendor": "0xCafe",
    "idProduct": "0x4004",
    "manufacturer": "AmeNote",
    "manufacturerId": "0x7E0000",
    "version": "0x00010000",
    "product": "ProtoZOA dual-midi1-1x1-2x2",
    "serialNumber": "GTBREPRO00000004",
    "power": 50,
    "endpoints": [make_endpoint("IfaceA", 1, 1), make_endpoint("IfaceB", 2, 2)]
}

with open(out_path, "w") as f:
    json.dump(config, f, indent=2)
print(f"wrote {out_path}")
