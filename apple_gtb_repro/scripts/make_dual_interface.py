#!/usr/bin/env python3
"""Build a usbMIDI2DescriptorBuilder config.json with TWO separate USB MIDI
Functions (two IAD+AudioControl+MIDIStreaming blocks), each declaring a
single MIDI2.0 bidirectional 1-group GTB. Tests whether AppleMIDIUSBDriver
handles a genuine dual-MIDIStreaming-interface composite device, and
requires the tusb_ump umpd_control_xfer_cb multi-instance routing fix.
"""
import json, sys

out_path, label = sys.argv[1], sys.argv[2]

def make_endpoint(idx):
    return {
        "name": f"ProtoZOA {label} Itf{idx}"[:98],
        "MIDI1Itf": [
            {"in": True, "out": True, "name": f"Legacy{idx}"}
        ],
        "defaultGTBProtocol": 2,
        "blocks": [
            {"name": f"Itf{idx}Bi", "in": True, "out": True, "firstGroup": 1, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0}
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
    "product": f"ProtoZOA {label}"[:98],
    "serialNumber": "GTBREPRO00000001",
    "power": 50,
    "endpoints": [make_endpoint(1), make_endpoint(2)]
}

with open(out_path, "w") as f:
    json.dump(config, f, indent=2)
print(f"wrote {out_path}: 2 endpoints (USB MIDI Functions), 1 bidirectional MIDI2.0 GTB (1 group) each")
