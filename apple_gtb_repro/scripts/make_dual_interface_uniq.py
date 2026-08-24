#!/usr/bin/env python3
"""Dual-interface repro variant with every possible string made distinct per
Function -- interface name, IAD iFunction/Audio-Control iInterface (now wired
up in buildUSBDescriptors.js, previously hardcoded to 0/unset), legacy MIDI1
port name, and GTB block name. Top-level product/manufacturer/serial cannot
differ per Function (one physical USB device = one Device Descriptor), so a
fresh serial number is used to avoid any stale macOS-side identity caching
against the previous dual-itf-m2-bidi-1g artifact.
"""
import json, sys

out_path = sys.argv[1]

def make_endpoint(tag):
    return {
        "name": f"ProtoZOA-{tag}",
        "MIDI1Itf": [
            {"in": True, "out": True, "name": f"{tag}Legacy"}
        ],
        "defaultGTBProtocol": 2,
        "blocks": [
            {"name": f"{tag}Block", "in": True, "out": True, "firstGroup": 1, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0}
        ]
    }

config = {
    "prefix": "",
    "CDC": 0,
    "idVendor": "0xCafe",
    "idProduct": "0x4001",
    "manufacturer": "AmeNote",
    "manufacturerId": "0x7E0000",
    "version": "0x00010000",
    "product": "ProtoZOA dual-itf-m2-bidi-1g-uniq",
    "serialNumber": "GTBREPRO00000002",
    "power": 50,
    "endpoints": [make_endpoint("Alpha"), make_endpoint("Beta")]
}

with open(out_path, "w") as f:
    json.dump(config, f, indent=2)
print(f"wrote {out_path}")
