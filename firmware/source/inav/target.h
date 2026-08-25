#pragma once

#define TARGET_BOARD_IDENTIFIER "MERL"
#define USBD_PRODUCT_STRING     "MERLYN435"

// ---- IO PORTS ----
#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTH         0xffff

// ---- PIN MAPPING ----
#define LED0                    PA8
#define LED0_INVERTED
#define BEEPER                  PC15
#define BEEPER_INVERTED

// ---- SPI 1 (IMU) ----
#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7
#define SPI1_NSS_PIN            PA4
#define USE_IMU_MPU6500
#define IMU_MPU6500_ALIGN       CW0_DEG
#define MPU6500_SPI_BUS         BUS_SPI1
#define MPU6500_CS_PIN          SPI1_NSS_PIN

#define USE_IMU_LSM6DXX
#define IMU_LSM6DXX_ALIGN       CW0_DEG
#define LSM6DXX_SPI_BUS         BUS_SPI1
#define LSM6DXX_CS_PIN          SPI1_NSS_PIN

// ---- SPI 2 (OSD & FLASH) ----
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15
#define SPI2_NSS_PIN            PB12

#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI2
#define MAX7456_CS_PIN          PB12

#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_SPI_BUS          BUS_SPI2
#define M25P16_CS_PIN           PC13

// ---- I2C (Baro) ----
#define USE_I2C
#define USE_I2C_DEVICE_2
#define I2C2_SCL                PH2
#define I2C2_SDA                PH3

#define DEFAULT_I2C_BUS         BUS_I2C2
#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C2
#define USE_BARO_BMP388

// ---- ADC ----
#define USE_ADC
#define ADC_INSTANCE                ADC1
#define ADC1_DMA_STREAM             DMA2_CHANNEL1
#define ADC_CHANNEL_1_PIN           PA0
#define ADC_CHANNEL_2_PIN           PA1
#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2

// ---- USB ----
#define USE_VCP
#define USE_USB_DETECT

// ---- UARTS ----
#define USE_UART1
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define USE_UART3
#define UART3_TX_PIN            PB10
#define UART3_RX_PIN            PB11

#define USE_UART5
#define UART5_TX_PIN            PB9
#define UART5_RX_PIN            PB8

#define USE_UART7
#define UART7_TX_PIN            PB4
#define UART7_RX_PIN            PB3

#define SERIAL_PORT_COUNT       5
#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_USART2

// ---- DEFAULTS & EXTENDED FEATURES ----
#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_VBAT | FEATURE_CURRENT_METER)
#define MAX_PWM_OUTPUT_PORTS    4
#define USE_DSHOT
#define USE_ESC_SENSOR          
#define USE_CRASH_FLIP          
#define USE_RPM_FILTER