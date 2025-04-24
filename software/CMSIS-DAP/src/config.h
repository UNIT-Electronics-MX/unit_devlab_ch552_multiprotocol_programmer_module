// ===================================================================================
// User Configurations for CH552 DAPLink
// ===================================================================================
// Cocket Nova DapLink by UNIT electronics
#pragma once

// Pin definitions
#define PIN_LED             P11       // pin connected to LED, active low
#define PIN_SWD             P15      // pin connected to SWDIO/TMS via 100R resistor
#define PIN_SWK             P16       // pin connected to SWCLK/TCK via 100R resistor
#define PIN_RST             P17       // pin connected to nRESET
#define PIN_TDO             P14       // pin connected to TDO via 100R resistor
#define PIN_TDI             P32       // pin connected to TDI via 100R resistor
#define PIN_TRST            P34       // pin connected to nTRST
#define PIN_RXD             P30       // pin connected to RXD via 470R resistor
#define PIN_TXD             P31       // pin connected to TXT via 470R resistor

// USB device descriptor
#define USB_VENDOR_ID       0x1A86    // VID
#define USB_PRODUCT_ID      0x8011    // PID
#define USB_DEVICE_VERSION  0x0100    // v1.0 (BCD-format)

// USB configuration descriptor
#define USB_MAX_POWER_mA    500       // max power in mA 

// USB descriptor strings
#define MANUFACTURER_STR    'C','o','c','k','e','t',' ','N','o','v','a'
#define PRODUCT_STR         'C','o','c','k','e','t',' ','N','o','v','a',' ', 'C','M','S','I','S','-','D','A','P'
#define SERIAL_STR          'C','H','5','5','2'
#define INTERFACE_STR_1     'C','D','C',' ','V','C','P'
#define INTERFACE_STR_2     'H','I','D',' ','D','a','t','a'
