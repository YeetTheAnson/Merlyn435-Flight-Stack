/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU        AT32F435G

#define BOARD_NAME           MERLYN435
#define MANUFACTURER_ID      ANSON

// ---- CLOCK ----
#define SYSTEM_HSE_MHZ       8

// ---- INTERNAL COMPONENTS ----
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_MPU6500

#define USE_BARO
#define USE_BARO_BMP388

#define USE_MAX7456

#define USE_FLASH
#define USE_FLASH_W25Q128FV

// ---- PIN MAPPING ----
#define LED0_PIN             PA8
#define BEEPER_PIN           PC15
#define BEEPER_INVERTED

// ---- ADC ----
#define USE_ADC
#define ADC_VBAT_PIN         PA0
#define ADC_CURR_PIN         PA1
#define ADC_INSTANCE         ADC1
#define ADC1_DMA_OPT         11

// ---- MOTORS ----
#define MOTOR1_PIN           PB6
#define MOTOR2_PIN           PB7
#define MOTOR3_PIN           PB0
#define MOTOR4_PIN           PB1

// ---- UARTS ----
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3
#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11
#define UART5_TX_PIN         PB9
#define UART5_RX_PIN         PB8
#define UART7_TX_PIN         PB4
#define UART7_RX_PIN         PB3

// ---- I2C (External + BMP388) ----
#define I2C2_SCL_PIN         PH2
#define I2C2_SDA_PIN         PH3

// ---- SPI1 (MPU6500) ----
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

// ---- SPI2 (Flash & OSD) ----
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

// ---- CHIP SELECTS ----
#define GYRO_1_CS_PIN        PA4
#define MAX7456_SPI_CS_PIN   PB12
#define FLASH_CS_PIN         PC13

// ---- HARDWARE INSTANCES ----
#define GYRO_1_SPI_INSTANCE  SPI1
#define FLASH_SPI_INSTANCE   SPI2
#define MAX7456_SPI_INSTANCE SPI2
#define BARO_I2C_INSTANCE    I2CDEV_2
#define MAG_I2C_INSTANCE     I2CDEV_2

// ---- TIMER MAPPING ----
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB6, 1,  0) \
    TIMER_PIN_MAP( 1, PB7, 1,  1) \
    TIMER_PIN_MAP( 2, PB0, 2,  2) \
    TIMER_PIN_MAP( 3, PB1, 2,  3)

// ---- DEFAULTS ----
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
#define DEFAULT_DSHOT_BURST             DSHOT_DMAR_AUTO

// Setting default ports for your layout logic
#define SERIALRX_UART                   SERIAL_PORT_USART2