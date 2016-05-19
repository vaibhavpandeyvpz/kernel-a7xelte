/*
 * dbmd2-va-regmap.h  --  DBMD2 VA register mapping
 *
 * Copyright (C) 2014 DSP Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _DBMD2_VA_REGMAP_H
#define _DBMD2_VA_REGMAP_H

/* DBMD2 commands and values */
#define DBMD2_VA_SYNC_POLLING				0x80000000
#define DBMD2_VA_CMD_MASK				0x80000000

#define DBMD2_VA_SET_POWER_STATE_SLEEP			0x80170001

#define DBMD2_VA_GET_FW_VER				0x80000000
#define DBMD2_VA_OPR_MODE				0x80010000
#define DBMD2_VA_TG_THERSHOLD				0x80020000
#define DBMD2_VA_VERIFICATION_THRESHOLD			0x80030000
#define DBMD2_VA_GAIN_SHIFT_VALUE			0x80040000
#define DBMD2_VA_IO_PORT_ADDR_LO			0x80050000
#define DBMD2_VA_IO_PORT_ADDR_HI			0x80060000
#define DBMD2_VA_IO_PORT_VALUE_LO			0x80070000
#define DBMD2_VA_IO_PORT_VALUE_HI			0x80080000
#define DBMD2_VA_AUDIO_BUFFER_SIZE			0x80090000
#define DBMD2_VA_NUM_OF_SMP_IN_BUF			0x800A0000
#define DBMD2_VA_LAST_MAX_SMP_VALUE			0x800B0000
#define DBMD2_VA_LAST_DETECT_WORD_NUM			0x800C0000
#define DBMD2_VA_DETECT_TRIGER_LEVEL			0x800D0000
#define DBMD2_VA_DETECT_VERIFICATION_LEVEL		0x800E0000
#define DBMD2_VA_LOAD_NEW_ACUSTIC_MODEL			0x800F0000
#define DBMD2_VA_UART_SPEED				0x80170000
#define DBMD2_VA_CLK_CFG				0x80100000
#define DBMD2_VA_UART_XON				0x80110000
#define DBMD2_VA_AUDIO_BUFFER_CONVERSION		0x80120000
#define DBMD2_VA_AUDIO_HISTORY				0x80120000
#define DBMD2_VA_UART_XOFF				0x80130000
#define DBMD2_VA_LAST_DURATION				0x80140000
#define DBMD2_VA_LAST_ERROR				0x80150000
#define DBMD2_VA_MIC_GAIN				0x80160000
#define DBMD2_VA_SWITCH_TO_BOOT				0x80180015
#define DBMD2_VA_FW_ID					0x80190000
#define DBMD2_VA_HPF_ENABLE				0x801A0000
#define DBMD2_VA_MASTER_CLK_FREQ			0x801B0000
#define DBMD2_VA_I2C_ADDR				0x801D0000
#define DBMD2_VA_I2C_WRITE				0x801E0000
#define DBMD2_VA_I2C_READ				0x801F0000
#define DBMD2_VA_READ_AUDIO_BUFFER			0x80200000
#define DBMD2_VA_POST_DETECTION_CLK_CFG			0x80210000

#define DBMD2_VA_UART_DELAY				0x80220000
#define DBMD2_VA_UART_FIFO_SIZE				0x80230000
#define DBMD2_VA_MICROPHONE1_CONFIGURATION		0x80240000
#define DBMD2_VA_MICROPHONE2_CONFIGURATION		0x80250000

#define DBMD2_VA_SET_D2PARAM_ADDR			0x801C0000
#define DBMD2_VA_GET_D2PARAM				0x80270000
#define DBMD2_VA_SET_D2PARAM				0x80260000

#define DBMD2_VA_RECOGNITION_MODE			0x80400000

#define DBD2_D2PARAM_WORDID             0x54
#define DBD2_D2PARAM_ALTWORDID          0x55

#define DBMD2_READ_CHECKSUM				0x805A0E00
#define DBMD2_FIRMWARE_BOOT				0x805A0B00

#endif