uint8_t const desc_device[] = {
	0x12,	// bLength
	0x01,	// bDescriptorType = TUSB_DESC_DEVICE
	0x00,	// bcdUSBLSB
	0x02,	// bcdUSBMSB
	0xEF,	// bDeviceClass = TUSB_CLASS_MISC
	0x02,	// bDeviceSubClass = TUSB_CLASS_MISC
	0x01,	// bDeviceProtocol = MISC_PROTOCOL_IAD
	0x40,	// bMaxPacketSize0
	0xFE,	// idVendorLSB
	0xCA,	// idVendorMSB
	0x01,	// idProductLSB
	0x40,	// idProductMSB
	0x00,	// bcdDeviceLSB
	0x01,	// bcdDeviceMSB
	0x01,	// iManufacturer  "AmeNote"
	0x02,	// iProduct  "ProtoZOA asym-12in-16out"
	0x03,	// iSerialNumber - "GTBREPRO00000001"
	0x01	// bNumConfigurations
};

uint8_t const desc_device_qualifier[] = {
	0x0A,	// bLength
	0x06,	// bDescriptorType = TUSB_DESC_DEVICE_QUALIFIER
	0x00,	// bcdUSBLSB
	0x02,	// bcdUSBMSB
	0xEF,	// bDeviceClass = TUSB_CLASS_MISC
	0x02,	// bDeviceSubClass = TUSB_CLASS_MISC
	0x01,	// bDeviceProtocol = MISC_PROTOCOL_IAD
	0x40,	// bMaxPacketSize0
	0x01,	// bNumConfigurations
	0x00	// bReserved
};

uint8_t const desc_fs_configuration[] = {
	0x09,	// bLength
	0x02,	// bDescriptorType = CONFIGURATION
	0xA0,	// Total LengthLSB
	0x00,	// Total LengthMSB
	0x02,	// bNumInterfaces
	0x01,	// bConfigurationValue
	0x00,	// iConfiguration
	0x80,	// bmAttributes
	0x19,	// bMaxPower (50mA)
	
  // ---------------------------
	
  // Interface Association Descriptor
	0x08,	// bLength
	0x0B,	// bDescriptorType
	0x00,	// bFirstInterface
	0x02,	// bInterfaceCount
	0x01,	// bFunctionClass
	0x03,	// bFunctionSubClass
	0x00,	// bFunctionProtocol
	0x00,	// iFunction
	
  // Interface - Audio Control
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x00,	// bInterfaceNumber
	0x00,	// bAlternateSetting
	0x00,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x01,	// bInterfaceSubClass = AUDIO_CONTROL
	0x00,	// bInterfaceProtocol
	0x00,	// iInterface
	
  // Audio AC Descriptor - Header
	0x09,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x01,	// bDescriptorSubtype = HEADER
	0x00,	// bcdACD0
	0x01,	// bcdACD1
	0x09,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	0x01,	// bInCollection
	0x01,	// baInterfaceNr(1)
	
  // Interface - MIDIStreaming - Alternate Setting #0
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x01,	// bInterfaceNumber
	0x00,	// bAlternateSetting
	0x02,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x03,	// bInterfaceSubClass = MIDISTREAMING
	0x00,	// bInterfaceProtocol
	0x02,	// iInterface - "ProtoZOA asym-12in-16out"
	
  // Audio MS Descriptor - CS Interface - MS Header
	0x07,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x01,	// bDescriptorSubtype = MS_HEADER
	0x00,	// bcdMSCLSB
	0x01,	// bcdMSCMSB
	0x2F,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x01,	// bJackID (string = "Legacy")
	0x20,	// iJack - "Legacy"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x12,	// bJackID (string = "Legacy")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "Legacy")
	0x01,	// baSourcePin
	0x20,	// iJack - "Legacy"
	
  // EP Descriptor - Endpoint - MIDI OUT
	0x09,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x01,	// bEndpointAddress (OUT)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	0x00,	// bRefresh
	0x00,	// bSynchAddress
	
  // Audio MS Descriptor - CS Endpoint - EP General
	0x05,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x01,	// bDescriptorSubtype = MS_GENERAL
	0x01,	// bNumEmbMIDJack
	0x01,	// Jack Id - Embedded MIDI in (string="Legacy")
	
  // EP Descriptor - Endpoint - MIDI IN
	0x09,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x81,	// bEndpointAddress (IN)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	0x00,	// bRefresh
	0x00,	// bSynchAddress
	
  // Audio MS Descriptor - CS Endpoint - MS General
	0x05,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x01,	// bDescriptorSubtype = MS_GENERAL
	0x01,	// bNumEmbMIDJack
	0x12,	// Jack Id - Embedded MIDI Out (string = "Legacy")
	
  // Interface - MIDIStreaming - Alternate Setting #1
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x01,	// bInterfaceNumber
	0x01,	// bAlternateSetting
	0x02,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x03,	// bInterfaceSubClass = MIDISTREAMING
	0x00,	//  bInterfaceProtocol
	0x02,	// iInterface - "ProtoZOA asym-12in-16out"
	
  // Audio MS Descriptor - CS Interface - MS Header
	0x07,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x01,	// bDescriptorSubtype = MS_HEADER
	0x00,	// bcdMSC_LSB
	0x02,	// bcdMSC_MSB
	0x07,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	
  // EP Descriptor - Endpoint - MIDI OUT
	0x07,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x01,	// bEndpointAddress (OUT)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x10,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x0C,	// bNumGrpTrmBlock
	0x01,	// baAssoGrpTrmBlkID
	0x02,	// baAssoGrpTrmBlkID
	0x03,	// baAssoGrpTrmBlkID
	0x04,	// baAssoGrpTrmBlkID
	0x05,	// baAssoGrpTrmBlkID
	0x06,	// baAssoGrpTrmBlkID
	0x07,	// baAssoGrpTrmBlkID
	0x08,	// baAssoGrpTrmBlkID
	0x09,	// baAssoGrpTrmBlkID
	0x0A,	// baAssoGrpTrmBlkID
	0x0B,	// baAssoGrpTrmBlkID
	0x0C,	// baAssoGrpTrmBlkID
	
  // EP Descriptor - Endpoint - MIDI IN
	0x07,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x81,	// bEndpointAddress (IN)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x14,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x10,	// bNumGrpTrmBlock
	0x0D,	// baAssoGrpTrmBlkID
	0x0E,	// baAssoGrpTrmBlkID
	0x0F,	// baAssoGrpTrmBlkID
	0x10,	// baAssoGrpTrmBlkID
	0x11,	// baAssoGrpTrmBlkID
	0x12,	// baAssoGrpTrmBlkID
	0x13,	// baAssoGrpTrmBlkID
	0x14,	// baAssoGrpTrmBlkID
	0x15,	// baAssoGrpTrmBlkID
	0x16,	// baAssoGrpTrmBlkID
	0x17,	// baAssoGrpTrmBlkID
	0x18,	// baAssoGrpTrmBlkID
	0x19,	// baAssoGrpTrmBlkID
	0x1A,	// baAssoGrpTrmBlkID
	0x1B,	// baAssoGrpTrmBlkID
	0x1C	// baAssoGrpTrmBlkID
};
uint8_t const gtb0[] = {
	0x05,	// HeaderLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x01,	// bDescriptorSubtype = GR_TRM_BLOCK_HEADER
	0x71,	// wTotalLengthLSB
	0x01,	// wTotalLengthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x01,	// bGrpTrmBlkID
	0x01,	// in
	0x00,	// First Group
	0x01,	// nNumGroupTrm
	0x04,	// iBlockItem - "Group1In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x02,	// bGrpTrmBlkID
	0x01,	// in
	0x01,	// First Group
	0x01,	// nNumGroupTrm
	0x05,	// iBlockItem - "Group2In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x03,	// bGrpTrmBlkID
	0x01,	// in
	0x02,	// First Group
	0x01,	// nNumGroupTrm
	0x06,	// iBlockItem - "Group3In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x04,	// bGrpTrmBlkID
	0x01,	// in
	0x03,	// First Group
	0x01,	// nNumGroupTrm
	0x07,	// iBlockItem - "Group4In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x05,	// bGrpTrmBlkID
	0x01,	// in
	0x04,	// First Group
	0x01,	// nNumGroupTrm
	0x08,	// iBlockItem - "Group5In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x06,	// bGrpTrmBlkID
	0x01,	// in
	0x05,	// First Group
	0x01,	// nNumGroupTrm
	0x09,	// iBlockItem - "Group6In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x07,	// bGrpTrmBlkID
	0x01,	// in
	0x06,	// First Group
	0x01,	// nNumGroupTrm
	0x0A,	// iBlockItem - "Group7In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x08,	// bGrpTrmBlkID
	0x01,	// in
	0x07,	// First Group
	0x01,	// nNumGroupTrm
	0x0B,	// iBlockItem - "Group8In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x09,	// bGrpTrmBlkID
	0x01,	// in
	0x08,	// First Group
	0x01,	// nNumGroupTrm
	0x0C,	// iBlockItem - "Group9In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0A,	// bGrpTrmBlkID
	0x01,	// in
	0x09,	// First Group
	0x01,	// nNumGroupTrm
	0x0D,	// iBlockItem - "Group10In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0B,	// bGrpTrmBlkID
	0x01,	// in
	0x0A,	// First Group
	0x01,	// nNumGroupTrm
	0x0E,	// iBlockItem - "Group11In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0C,	// bGrpTrmBlkID
	0x01,	// in
	0x0B,	// First Group
	0x01,	// nNumGroupTrm
	0x0F,	// iBlockItem - "Group12In"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0D,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x00,	// First Group
	0x01,	// nNumGroupTrm
	0x10,	// iBlockItem - "Group1Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0E,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x01,	// First Group
	0x01,	// nNumGroupTrm
	0x11,	// iBlockItem - "Group2Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0F,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x02,	// First Group
	0x01,	// nNumGroupTrm
	0x12,	// iBlockItem - "Group3Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x10,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x03,	// First Group
	0x01,	// nNumGroupTrm
	0x13,	// iBlockItem - "Group4Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x11,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x04,	// First Group
	0x01,	// nNumGroupTrm
	0x14,	// iBlockItem - "Group5Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x12,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x05,	// First Group
	0x01,	// nNumGroupTrm
	0x15,	// iBlockItem - "Group6Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x13,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x06,	// First Group
	0x01,	// nNumGroupTrm
	0x16,	// iBlockItem - "Group7Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x14,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x07,	// First Group
	0x01,	// nNumGroupTrm
	0x17,	// iBlockItem - "Group8Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x15,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x08,	// First Group
	0x01,	// nNumGroupTrm
	0x18,	// iBlockItem - "Group9Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x16,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x09,	// First Group
	0x01,	// nNumGroupTrm
	0x19,	// iBlockItem - "Group10Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x17,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0A,	// First Group
	0x01,	// nNumGroupTrm
	0x1A,	// iBlockItem - "Group11Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x18,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0B,	// First Group
	0x01,	// nNumGroupTrm
	0x1B,	// iBlockItem - "Group12Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x19,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0C,	// First Group
	0x01,	// nNumGroupTrm
	0x1C,	// iBlockItem - "Group13Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x1A,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0D,	// First Group
	0x01,	// nNumGroupTrm
	0x1D,	// iBlockItem - "Group14Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x1B,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0E,	// First Group
	0x01,	// nNumGroupTrm
	0x1E,	// iBlockItem - "Group15Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x1C,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0F,	// First Group
	0x01,	// nNumGroupTrm
	0x1F,	// iBlockItem - "Group16Out"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00	// wMaxOutputBandwidthMSB
};
uint8_t const gtbLengths[] = {369};
uint8_t const epInterface[] = {1};
uint8_t const *group_descr[] = {gtb0};
char const* string_desc_arr [] = {
	"", //0
	"AmeNote", //1
	"ProtoZOA asym-12in-16out", //2
	"GTBREPRO00000001", //3
	"Group1In", //4
	"Group2In", //5
	"Group3In", //6
	"Group4In", //7
	"Group5In", //8
	"Group6In", //9
	"Group7In", //10
	"Group8In", //11
	"Group9In", //12
	"Group10In", //13
	"Group11In", //14
	"Group12In", //15
	"Group1Out", //16
	"Group2Out", //17
	"Group3Out", //18
	"Group4Out", //19
	"Group5Out", //20
	"Group6Out", //21
	"Group7Out", //22
	"Group8Out", //23
	"Group9Out", //24
	"Group10Out", //25
	"Group11Out", //26
	"Group12Out", //27
	"Group13Out", //28
	"Group14Out", //29
	"Group15Out", //30
	"Group16Out", //31
	"Legacy", //32
};
uint8_t const string_desc_arr_length = 33;