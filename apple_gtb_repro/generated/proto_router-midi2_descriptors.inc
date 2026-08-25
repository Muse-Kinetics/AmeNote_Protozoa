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
	0x11,	// idProductLSB
	0x40,	// idProductMSB
	0x00,	// bcdDeviceLSB
	0x01,	// bcdDeviceMSB
	0x01,	// iManufacturer  "AmeNote"
	0x02,	// iProduct  "proto_router"
	0x03,	// iSerialNumber - "GTBREPRO00000011"
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
	0x7D,	// Total LengthLSB
	0x01,	// Total LengthMSB
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
	0x02,	// iFunction - "proto_router"
	
  // Interface - Audio Control
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x00,	// bInterfaceNumber
	0x00,	// bAlternateSetting
	0x00,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x01,	// bInterfaceSubClass = AUDIO_CONTROL
	0x00,	// bInterfaceProtocol
	0x02,	// iInterface - "proto_router"
	
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
	0x02,	// iInterface - "proto_router"
	
  // Audio MS Descriptor - CS Interface - MS Header
	0x07,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x01,	// bDescriptorSubtype = MS_HEADER
	0x00,	// bcdMSCLSB
	0x01,	// bcdMSCMSB
	0xE5,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x01,	// bJackID (string = "P01")
	0x04,	// iJack - "P01"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x12,	// bJackID (string = "P01")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P01")
	0x01,	// baSourcePin
	0x04,	// iJack - "P01"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x05,	// bJackID (string = "P02")
	0x05,	// iJack - "P02"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x16,	// bJackID (string = "P02")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P02")
	0x01,	// baSourcePin
	0x05,	// iJack - "P02"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x09,	// bJackID (string = "P03")
	0x06,	// iJack - "P03"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x1A,	// bJackID (string = "P03")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P03")
	0x01,	// baSourcePin
	0x06,	// iJack - "P03"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x0D,	// bJackID (string = "P04")
	0x07,	// iJack - "P04"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x1E,	// bJackID (string = "P04")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P04")
	0x01,	// baSourcePin
	0x07,	// iJack - "P04"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x11,	// bJackID (string = "P05")
	0x08,	// iJack - "P05"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x22,	// bJackID (string = "P05")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P05")
	0x01,	// baSourcePin
	0x08,	// iJack - "P05"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x15,	// bJackID (string = "P06")
	0x09,	// iJack - "P06"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x26,	// bJackID (string = "P06")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P06")
	0x01,	// baSourcePin
	0x09,	// iJack - "P06"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x19,	// bJackID (string = "P07")
	0x0A,	// iJack - "P07"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x2A,	// bJackID (string = "P07")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P07")
	0x01,	// baSourcePin
	0x0A,	// iJack - "P07"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x1D,	// bJackID (string = "P08")
	0x0B,	// iJack - "P08"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x2E,	// bJackID (string = "P08")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P08")
	0x01,	// baSourcePin
	0x0B,	// iJack - "P08"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x21,	// bJackID (string = "P09")
	0x0C,	// iJack - "P09"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x32,	// bJackID (string = "P09")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P09")
	0x01,	// baSourcePin
	0x0C,	// iJack - "P09"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x25,	// bJackID (string = "P10")
	0x0D,	// iJack - "P10"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x36,	// bJackID (string = "P10")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P10")
	0x01,	// baSourcePin
	0x0D,	// iJack - "P10"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x29,	// bJackID (string = "P11")
	0x0E,	// iJack - "P11"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x3A,	// bJackID (string = "P11")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P11")
	0x01,	// baSourcePin
	0x0E,	// iJack - "P11"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x2D,	// bJackID (string = "P12")
	0x0F,	// iJack - "P12"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x3E,	// bJackID (string = "P12")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P12")
	0x01,	// baSourcePin
	0x0F,	// iJack - "P12"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x31,	// bJackID (string = "P13")
	0x10,	// iJack - "P13"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x42,	// bJackID (string = "P13")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "P13")
	0x01,	// baSourcePin
	0x10,	// iJack - "P13"
	
  // Audio MS Descriptor - CS Interface - MIDI IN Jack (EMB) (Main In)
	0x06,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x02,	// bDescriptorSubtype = MIDI_IN_JACK
	0x01,	// bJackType = EMBEDDED
	0x35,	// bJackID (string = "Hub Control")
	0x11,	// iJack - "Hub Control"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x46,	// bJackID (string = "Hub Control")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "Hub Control")
	0x01,	// baSourcePin
	0x11,	// iJack - "Hub Control"
	
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
	0x12,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x01,	// bDescriptorSubtype = MS_GENERAL
	0x0E,	// bNumEmbMIDJack
	0x01,	// Jack Id - Embedded MIDI in (string="P01")
	0x05,	// Jack Id - Embedded MIDI in (string="P02")
	0x09,	// Jack Id - Embedded MIDI in (string="P03")
	0x0D,	// Jack Id - Embedded MIDI in (string="P04")
	0x11,	// Jack Id - Embedded MIDI in (string="P05")
	0x15,	// Jack Id - Embedded MIDI in (string="P06")
	0x19,	// Jack Id - Embedded MIDI in (string="P07")
	0x1D,	// Jack Id - Embedded MIDI in (string="P08")
	0x21,	// Jack Id - Embedded MIDI in (string="P09")
	0x25,	// Jack Id - Embedded MIDI in (string="P10")
	0x29,	// Jack Id - Embedded MIDI in (string="P11")
	0x2D,	// Jack Id - Embedded MIDI in (string="P12")
	0x31,	// Jack Id - Embedded MIDI in (string="P13")
	0x35,	// Jack Id - Embedded MIDI in (string="Hub Control")
	
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
	0x12,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x01,	// bDescriptorSubtype = MS_GENERAL
	0x0E,	// bNumEmbMIDJack
	0x12,	// Jack Id - Embedded MIDI Out (string = "P01")
	0x16,	// Jack Id - Embedded MIDI Out (string = "P02")
	0x1A,	// Jack Id - Embedded MIDI Out (string = "P03")
	0x1E,	// Jack Id - Embedded MIDI Out (string = "P04")
	0x22,	// Jack Id - Embedded MIDI Out (string = "P05")
	0x26,	// Jack Id - Embedded MIDI Out (string = "P06")
	0x2A,	// Jack Id - Embedded MIDI Out (string = "P07")
	0x2E,	// Jack Id - Embedded MIDI Out (string = "P08")
	0x32,	// Jack Id - Embedded MIDI Out (string = "P09")
	0x36,	// Jack Id - Embedded MIDI Out (string = "P10")
	0x3A,	// Jack Id - Embedded MIDI Out (string = "P11")
	0x3E,	// Jack Id - Embedded MIDI Out (string = "P12")
	0x42,	// Jack Id - Embedded MIDI Out (string = "P13")
	0x46,	// Jack Id - Embedded MIDI Out (string = "Hub Control")
	
  // Interface - MIDIStreaming - Alternate Setting #1
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x01,	// bInterfaceNumber
	0x01,	// bAlternateSetting
	0x02,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x03,	// bInterfaceSubClass = MIDISTREAMING
	0x00,	//  bInterfaceProtocol
	0x02,	// iInterface - "proto_router"
	
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
	0x12,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x0E,	// bNumGrpTrmBlock
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
	0x0D,	// baAssoGrpTrmBlkID
	0x0E,	// baAssoGrpTrmBlkID
	
  // EP Descriptor - Endpoint - MIDI IN
	0x07,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x81,	// bEndpointAddress (IN)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x12,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x0E,	// bNumGrpTrmBlock
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
	0x0D,	// baAssoGrpTrmBlkID
	0x0E	// baAssoGrpTrmBlkID
};
uint8_t const gtb0[] = {
	0x05,	// HeaderLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x01,	// bDescriptorSubtype = GR_TRM_BLOCK_HEADER
	0xBB,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x01,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x00,	// First Group
	0x01,	// nNumGroupTrm
	0x04,	// iBlockItem - "P01"
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
	0x05,	// iBlockItem - "P02"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x03,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x02,	// First Group
	0x01,	// nNumGroupTrm
	0x06,	// iBlockItem - "P03"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x04,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x03,	// First Group
	0x01,	// nNumGroupTrm
	0x07,	// iBlockItem - "P04"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x05,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x04,	// First Group
	0x01,	// nNumGroupTrm
	0x08,	// iBlockItem - "P05"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x06,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x05,	// First Group
	0x01,	// nNumGroupTrm
	0x09,	// iBlockItem - "P06"
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
	0x0A,	// iBlockItem - "P07"
	0x11,	// bMIDIProtocol
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
	0x0B,	// iBlockItem - "P08"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x09,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x08,	// First Group
	0x01,	// nNumGroupTrm
	0x0C,	// iBlockItem - "P09"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0A,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x09,	// First Group
	0x01,	// nNumGroupTrm
	0x0D,	// iBlockItem - "P10"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0B,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x0A,	// First Group
	0x01,	// nNumGroupTrm
	0x0E,	// iBlockItem - "P11"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0C,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x0B,	// First Group
	0x01,	// nNumGroupTrm
	0x0F,	// iBlockItem - "P12"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0D,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x0C,	// First Group
	0x01,	// nNumGroupTrm
	0x10,	// iBlockItem - "P13"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00,	// wMaxOutputBandwidthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x0E,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x0D,	// First Group
	0x01,	// nNumGroupTrm
	0x11,	// iBlockItem - "Hub Control"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00	// wMaxOutputBandwidthMSB
};
uint8_t const gtbLengths[] = {187};
uint8_t const epInterface[] = {1};
uint8_t const *group_descr[] = {gtb0};
char const* string_desc_arr [] = {
	"", //0
	"AmeNote", //1
	"proto_router", //2
	"GTBREPRO00000011", //3
	"P01", //4
	"P02", //5
	"P03", //6
	"P04", //7
	"P05", //8
	"P06", //9
	"P07", //10
	"P08", //11
	"P09", //12
	"P10", //13
	"P11", //14
	"P12", //15
	"P13", //16
	"Hub Control", //17
};
uint8_t const string_desc_arr_length = 18;