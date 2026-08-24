#!/usr/bin/env python3
"""Composite device: one MIDI2.0 bidirectional 1-group interface + one CDC
serial interface -- the classic "MIDI + CDC" composite pattern, as a sanity
check that composite (different-class) devices work fine on this same build,
distinct from the same-class multi-interface case that macOS only partially
supports."""
import json, sys

out_path = sys.argv[1]

config = {
    "prefix": "",
    "CDC": 1,
    "CDCName": "ProtoZOA Debug",
    "idVendor": "0xCafe",
    "idProduct": "0x4002",
    "manufacturer": "AmeNote",
    "manufacturerId": "0x7E0000",
    "version": "0x00010000",
    "product": "ProtoZOA midi-cdc-heartbeat",
    "serialNumber": "GTBREPRO00000003",
    "power": 50,
    "endpoints": [
        {
            "name": "ProtoZOA midi-cdc-heartbeat Midi",
            "MIDI1Itf": [
                {"in": True, "out": True, "name": "Legacy"}
            ],
            "defaultGTBProtocol": 2,
            "blocks": [
                {"name": "MidiBlock", "in": True, "out": True, "firstGroup": 1, "numOfGroups": 1, "protocol": 2, "wMaxInputBandwidth": 0, "wMaxOutputBandwidth": 0}
            ]
        }
    ]
}

with open(out_path, "w") as f:
    json.dump(config, f, indent=2)
print(f"wrote {out_path}")
