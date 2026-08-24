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
	0x02,	// iProduct  "ProtoZOA mixed6-x2"
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
	0x94,	// Total LengthLSB
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
	0x02,	// iInterface - "ProtoZOA mixed6-x2"
	
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
	0x10,	// iJack - "Legacy"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x12,	// bJackID (string = "Legacy")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "Legacy")
	0x01,	// baSourcePin
	0x10,	// iJack - "Legacy"
	
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
	0x02,	// iInterface - "ProtoZOA mixed6-x2"
	
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
	0x0C,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x08,	// bNumGrpTrmBlock
	0x01,	// baAssoGrpTrmBlkID
	0x02,	// baAssoGrpTrmBlkID
	0x03,	// baAssoGrpTrmBlkID
	0x04,	// baAssoGrpTrmBlkID
	0x07,	// baAssoGrpTrmBlkID
	0x08,	// baAssoGrpTrmBlkID
	0x09,	// baAssoGrpTrmBlkID
	0x0A,	// baAssoGrpTrmBlkID
	
  // EP Descriptor - Endpoint - MIDI IN
	0x07,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x81,	// bEndpointAddress (IN)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x0C,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x08,	// bNumGrpTrmBlock
	0x01,	// baAssoGrpTrmBlkID
	0x02,	// baAssoGrpTrmBlkID
	0x05,	// baAssoGrpTrmBlkID
	0x06,	// baAssoGrpTrmBlkID
	0x07,	// baAssoGrpTrmBlkID
	0x08,	// baAssoGrpTrmBlkID
	0x0B,	// baAssoGrpTrmBlkID
	0x0C	// baAssoGrpTrmBlkID
};
uint8_t const gtb0[] = {
	0x05,	// HeaderLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x01,	// bDescriptorSubtype = GR_TRM_BLOCK_HEADER
	0xA1,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x01,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x00,	// First Group
	0x01,	// nNumGroupTrm
	0x04,	// iBlockItem - "G1M2Bi"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x02,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x01,	// First Group
	0x01,	// nNumGroupTrm
	0x05,	// iBlockItem - "G2M2Bi"
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
	0x06,	// iBlockItem - "G3M2Uniin"
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
	0x07,	// iBlockItem - "G4M2Uniin"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x05,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x04,	// First Group
	0x01,	// nNumGroupTrm
	0x08,	// iBlockItem - "G5M2Uniout"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x06,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x05,	// First Group
	0x01,	// nNumGroupTrm
	0x09,	// iBlockItem - "G6M2Uniout"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x07,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x06,	// First Group
	0x01,	// nNumGroupTrm
	0x0A,	// iBlockItem - "G7M1Bi"
	0x02,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x08,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x07,	// First Group
	0x01,	// nNumGroupTrm
	0x0B,	// iBlockItem - "G8M1Bi"
	0x02,	// bMIDIProtocol
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
	0x0C,	// iBlockItem - "G9M1Uniin"
	0x02,	// bMIDIProtocol
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
	0x0D,	// iBlockItem - "G10M1Uniin"
	0x02,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0B,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0A,	// First Group
	0x01,	// nNumGroupTrm
	0x0E,	// iBlockItem - "G11M1Uniout"
	0x02,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0C,	// bGrpTrmBlkID
	0x02,	// bidirectional
	0x0B,	// First Group
	0x01,	// nNumGroupTrm
	0x0F,	// iBlockItem - "G12M1Uniout"
	0x02,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00	// wMaxOutputBandwidthMSB
};
uint8_t const gtbLengths[] = {161};
uint8_t const epInterface[] = {1};
uint8_t const *group_descr[] = {gtb0};
char const* string_desc_arr [] = {
	"", //0
	"AmeNote", //1
	"ProtoZOA mixed6-x2", //2
	"GTBREPRO00000001", //3
	"G1M2Bi", //4
	"G2M2Bi", //5
	"G3M2Uniin", //6
	"G4M2Uniin", //7
	"G5M2Uniout", //8
	"G6M2Uniout", //9
	"G7M1Bi", //10
	"G8M1Bi", //11
	"G9M1Uniin", //12
	"G10M1Uniin", //13
	"G11M1Uniout", //14
	"G12M1Uniout", //15
	"Legacy", //16
};
uint8_t const string_desc_arr_length = 17;