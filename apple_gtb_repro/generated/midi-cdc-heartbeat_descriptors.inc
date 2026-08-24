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
	0x02,	// idProductLSB
	0x40,	// idProductMSB
	0x00,	// bcdDeviceLSB
	0x01,	// bcdDeviceMSB
	0x01,	// iManufacturer  "AmeNote"
	0x02,	// iProduct  "ProtoZOA midi-cdc-heartbeat"
	0x03,	// iSerialNumber - "GTBREPRO00000003"
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
	0xC8,	// Total LengthLSB
	0x00,	// Total LengthMSB
	0x04,	// bNumInterfaces
	0x01,	// bConfigurationValue
	0x00,	// iConfiguration
	0x80,	// bmAttributes
	0x19,	// bMaxPower (50mA)
	
  // ---------------------------
	
  // Interface Associate
	0x08,	
	0x0B,	// TUSB_DESC_INTERFACE_ASSOCIATION
	0x00,	// ITF_NUM_CDC
	0x02,	
	0x02,	// TUSB_CLASS_CDC
	0x02,	// CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL
	0x00,	// CDC_COMM_PROTOCOL_NONE
	0x00,	
	
  // CDC Control Interface
	0x09,	
	0x04,	// TUSB_DESC_INTERFACE
	0x00,	// Interface number
	0x00,	
	0x01,	
	0x02,	// TUSB_CLASS_CDC
	0x02,	// CDC_COMM_SUBCLASS_ABSTRACT_CONTROL_MODEL
	0x00,	// CDC_COMM_PROTOCOL_NONE
	0x04,	// String Index - "ProtoZOA Debug 1"
	
  // CDC Header
	0x05,	
	0x24,	// TUSB_DESC_CS_INTERFACE
	0x00,	// CDC_FUNC_DESC_HEADER
	0x20,	// LSB
	0x01,	// MSB
	
  // CDC Call
	0x05,	
	0x24,	// TUSB_DESC_CS_INTERFACE
	0x01,	// CDC_FUNC_DESC_CALL_MANAGEMENT
	0x00,	
	0x01,	// Interface Number
	
  // CDC ACM: support line request
	0x04,	
	0x24,	// TUSB_DESC_CS_INTERFACE
	0x02,	// CDC_FUNC_DESC_ABSTRACT_CONTROL_MANAGEMENT
	0x06,	
	
  // CDC Union
	0x05,	
	0x24,	// TUSB_DESC_CS_INTERFACE
	0x06,	// CDC_FUNC_DESC_UNION
	0x00,	// ITF_NUM_CDC
	0x01,	// ITF_NUM_CDC + 1
	
  // Endpoint Notification
	0x07,	
	0x05,	// TUSB_DESC_ENDPOINT
	0x81,	// EPNUM_CDC_NOTIF
	0x03,	// TUSB_XFER_INTERRUPT
	0x40,	// _ep_notif_sizeLSB
	0x00,	// _ep_notif_sizeMSB
	0x10,	
	
  // CDC Data Interface
	0x09,	
	0x04,	// TUSB_DESC_INTERFACE
	0x01,	// Interface Number
	0x00,	
	0x02,	
	0x0A,	// TUSB_CLASS_CDC_DATA
	0x00,	
	0x00,	
	0x00,	
	
  // Endpoint Out
	0x07,	
	0x05,	// TUSB_DESC_ENDPOINT
	0x02,	// EPNUM_CDC_OUT
	0x02,	// TUSB_XFER_BULK
	0x40,	// epSizeLSB
	0x00,	// epSizeMSB
	0x00,	
	
  // Endpoint In
	0x07,	
	0x05,	// TUSB_DESC_ENDPOINT
	0x82,	// EPNUM_CDC_IN
	0x02,	// TUSB_XFER_BULK
	0x40,	// epSizeLSB
	0x00,	// epSizeMSB
	0x00,	
	
  // ---------------------------
	
  // Interface Association Descriptor
	0x08,	// bLength
	0x0B,	// bDescriptorType
	0x02,	// bFirstInterface
	0x02,	// bInterfaceCount
	0x01,	// bFunctionClass
	0x03,	// bFunctionSubClass
	0x00,	// bFunctionProtocol
	0x06,	// iFunction - "ProtoZOA midi-cdc-heartbeat Midi"
	
  // Interface - Audio Control
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x02,	// bInterfaceNumber
	0x00,	// bAlternateSetting
	0x00,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x01,	// bInterfaceSubClass = AUDIO_CONTROL
	0x00,	// bInterfaceProtocol
	0x06,	// iInterface - "ProtoZOA midi-cdc-heartbeat Midi"
	
  // Audio AC Descriptor - Header
	0x09,	// bLength
	0x24,	// bDescriptorType = CS_INTERFACE
	0x01,	// bDescriptorSubtype = HEADER
	0x00,	// bcdACD0
	0x01,	// bcdACD1
	0x09,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	0x01,	// bInCollection
	0x03,	// baInterfaceNr(1)
	
  // Interface - MIDIStreaming - Alternate Setting #0
	0x09,	// bLength
	0x04,	// bDescriptorType = INTERFACE
	0x03,	// bInterfaceNumber
	0x00,	// bAlternateSetting
	0x02,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x03,	// bInterfaceSubClass = MIDISTREAMING
	0x00,	// bInterfaceProtocol
	0x06,	// iInterface - "ProtoZOA midi-cdc-heartbeat Midi"
	
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
	0x07,	// iJack - "Legacy"
	
  // Audio MS Descriptor - CS Interface - MIDI OUT Jack (EMB) (Main Out)
	0x09,	// bLength
	0x24,	// bDescriptorType
	0x03,	// bDescriptorSubtype
	0x01,	// bJackType
	0x12,	// bJackID (string = "Legacy")
	0x01,	// Number of Input Pins of this Jack
	0x00,	// baSourceID (string = "Legacy")
	0x01,	// baSourcePin
	0x07,	// iJack - "Legacy"
	
  // EP Descriptor - Endpoint - MIDI OUT
	0x09,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x03,	// bEndpointAddress (OUT)
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
	0x83,	// bEndpointAddress (IN)
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
	0x03,	// bInterfaceNumber
	0x01,	// bAlternateSetting
	0x02,	// bNumEndpoints
	0x01,	// bInterfaceClass = AUDIO
	0x03,	// bInterfaceSubClass = MIDISTREAMING
	0x00,	//  bInterfaceProtocol
	0x06,	// iInterface - "ProtoZOA midi-cdc-heartbeat Midi"
	
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
	0x03,	// bEndpointAddress (OUT)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x05,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x01,	// bNumGrpTrmBlock
	0x01,	// baAssoGrpTrmBlkID
	
  // EP Descriptor - Endpoint - MIDI IN
	0x07,	// bLength
	0x05,	// bDescriptorType = ENDPOINT
	0x83,	// bEndpointAddress (IN)
	0x02,	// bmAttributes
	0x40,	// wMaxPacketSizeLSB
	0x00,	// wMaxPacketSizeMSB
	0x00,	// bInterval
	
  // Audio MS Descriptor - CS Endpoint - MS General 2.0
	0x05,	// bLength
	0x25,	// bDescriptorType = CS_ENDPOINT
	0x02,	// bDescriptorSubtype = MS_GENERAL_2_0
	0x01,	// bNumGrpTrmBlock
	0x01	// baAssoGrpTrmBlkID
};
uint8_t const gtb0[] = {
	0x05,	// HeaderLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x01,	// bDescriptorSubtype = GR_TRM_BLOCK_HEADER
	0x12,	// wTotalLengthLSB
	0x00,	// wTotalLengthMSB
	0x0D,	// bLength
	0x26,	// bDescriptorType = CS_GR_TRM_BLOCK
	0x02,	// bDescriptorSubtype = GR_TRM_BLOCK
	0x01,	// bGrpTrmBlkID
	0x00,	// bidirectional
	0x00,	// First Group
	0x01,	// nNumGroupTrm
	0x05,	// iBlockItem - "MidiBlock"
	0x11,	// bMIDIProtocol
	0x00,	// wMaxInputBandwidthLSB
	0x00,	// wMaxInputBandwidthMSB
	0x00,	// wMaxOutputBandwidthLSB
	0x00	// wMaxOutputBandwidthMSB
};
uint8_t const gtbLengths[] = {18};
uint8_t const epInterface[] = {3};
uint8_t const *group_descr[] = {gtb0};
char const* string_desc_arr [] = {
	"", //0
	"AmeNote", //1
	"ProtoZOA midi-cdc-heartbeat", //2
	"GTBREPRO00000003", //3
	"ProtoZOA Debug 1", //4
	"MidiBlock", //5
	"ProtoZOA midi-cdc-heartbeat Midi", //6
	"Legacy", //7
};
uint8_t const string_desc_arr_length = 8;