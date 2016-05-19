#ifndef __S6E3AA2_A3XE_PARAM_H__
#define __S6E3AA2_A3XE_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e3aa2_a3xe.h"

#define GAMMA_CMD_CNT		ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET)
#define ACL_CMD_CNT		ARRAY_SIZE(SEQ_ACL_OFF)
#define OPR_CMD_CNT		ARRAY_SIZE(SEQ_OPR_ACL_OFF)
#define ELVSS_CMD_CNT		ARRAY_SIZE(SEQ_ELVSS_SET)
#define AID_CMD_CNT		ARRAY_SIZE(SEQ_AID_SETTING)
#define HBM_CMD_CNT		ARRAY_SIZE(SEQ_HBM_OFF)

#define LDI_REG_ELVSS		0xB5
#define LDI_REG_COORDINATE	0xA1
#define LDI_REG_DATE		LDI_REG_COORDINATE
#define LDI_REG_ID		0x04
#define LDI_REG_CHIP_ID		0xD6
#define LDI_REG_MTP		0xC8
#define LDI_REG_HBM		0xB3
#define LDI_REG_RDDPM		0x0A
#define LDI_REG_RDDSM		0x0E
#define LDI_REG_ESDERR		0xEE

/* len is read length */
#define LDI_LEN_ELVSS		(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE	4
#define LDI_LEN_DATE		7
#define LDI_LEN_ID		3
#define LDI_LEN_CHIP_ID		5
#define LDI_LEN_MTP		35
#define LDI_LEN_HBM		31
#define LDI_LEN_RDDPM		1
#define LDI_LEN_RDDSM		1
#define LDI_LEN_ESDERR		1

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	10
#define LDI_OFFSET_AOR_2	11

#define LDI_OFFSET_ELVSS_1	2	/* B5h 2nd Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	3	/* B5h 3rd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	23	/* B5h 23th Para: ELVSS Temp Compensation */
#define LDI_OFFSET_ELVSS_4	30	/* B5h 30th Para: TSET Setting */

#define LDI_OFFSET_HBM		1
#define LDI_OFFSET_ACL		1

#define LDI_GPARA_DATE		4	/* 0xA1 5th para */
#define LDI_GPARA_HBM_ELVSS	23	/* 0xB5 24th para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00
};

static unsigned char SEQ_PCD_SET_DET_LOW[] = {
	0xCC,
	0x5C
};

static unsigned char SEQ_ERR_FG_SETTING[] = {
	0xED,
	0x44
};

static unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x00, 0x00
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB1,
	0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00,
	0x0C
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB5,
	0xA0,
	0x1C,	/* B5h 2nd Para: MPS_CON */
	0x44,	/* B5h 3rd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00,
	0x00,	/* B5h 23rd Para: ELVSS Temp Compensation */
	0x00,	/* B5h 24th Para: HBM Interpolation OTP */
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x19	/* B5h 30th Para: TSET Setting */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_HBM_OFF[] = {
	0x53,
	0x00
};

static unsigned char SEQ_HBM_ON[] = {
	0x53,
	0xC0
};

static unsigned char SEQ_OPR_ACL_OFF[] = {
	0xB4,
	0x40	/* 16 Frame Avg. at ACL Off */
};

static unsigned char SEQ_OPR_ACL_ON[] = {
	0xB4,
	0x50	/* 32 Frame Avg. at ACL On */
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 8% (Default) */
};

static const unsigned char SEQ_TSET_SETTING_1[] = {
	0xB0,
	0x1D
};

static const unsigned char SEQ_TSET_SETTING_2[] = {
	0xB5,
	0x19
};

enum {
	ACL_STATUS_0P,
	ACL_STATUS_8P,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_ACL_OFF,
	OPR_STATUS_ACL_ON,
	OPR_STATUS_MAX
};

enum {
	CAPS_OFF,
	CAPS_ON,
	CAPS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_20_DEGREE,	/* -20 < T <= 0 */
	TEMP_BELOW_MINUS_20_DEGREE,	/* T <= -20 */
	TEMP_MAX
};

enum {
	HBM_STATUS_OFF,
	HBM_STATUS_ON,
	HBM_STATUS_MAX
};

static unsigned char *HBM_TABLE[HBM_STATUS_MAX] = {SEQ_HBM_OFF, SEQ_HBM_ON};
static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_OPR_ACL_OFF, SEQ_OPR_ACL_ON};

static unsigned char elvss_mpscon_offset_data[IBRIGHTNESS_HBM_MAX][4] = {
	[IBRIGHTNESS_002NIT] = {0xB5, 0xA0, 0x0C, 0x46},
	[IBRIGHTNESS_003NIT] = {0xB5, 0xA0, 0x0C, 0x47},
	[IBRIGHTNESS_004NIT] = {0xB5, 0xA0, 0x0C, 0x48},
	[IBRIGHTNESS_005NIT] = {0xB5, 0xA0, 0x0C, 0x49},
	[IBRIGHTNESS_006NIT] = {0xB5, 0xA0, 0x0C, 0x4D},
	[IBRIGHTNESS_007NIT] = {0xB5, 0xA0, 0x0C, 0x4F},
	[IBRIGHTNESS_008NIT] = {0xB5, 0xA0, 0x0C, 0x50},
	[IBRIGHTNESS_009NIT] = {0xB5, 0xA0, 0x0C, 0x51},
	[IBRIGHTNESS_010NIT] = {0xB5, 0xA0, 0x0C, 0x51},
	[IBRIGHTNESS_011NIT] = {0xB5, 0xA0, 0x0C, 0x52},
	[IBRIGHTNESS_012NIT] = {0xB5, 0xA0, 0x0C, 0x52},
	[IBRIGHTNESS_013NIT] = {0xB5, 0xA0, 0x0C, 0x53},
	[IBRIGHTNESS_014NIT] = {0xB5, 0xA0, 0x0C, 0x53},
	[IBRIGHTNESS_015NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_016NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_017NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_019NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_020NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_021NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_022NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_024NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_025NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_027NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_029NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_030NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_032NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_034NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_037NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_039NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_041NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_044NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_047NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_050NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_053NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_056NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_060NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_064NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_068NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_072NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_077NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_082NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_087NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_093NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_098NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_105NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_111NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_119NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_126NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_134NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_143NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_152NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_162NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_172NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_183NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_195NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_207NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_220NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_234NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_249NIT] = {0xB5, 0xA0, 0x1C, 0x50},
	[IBRIGHTNESS_265NIT] = {0xB5, 0xA0, 0x1C, 0x50},
	[IBRIGHTNESS_282NIT] = {0xB5, 0xA0, 0x1C, 0x4F},
	[IBRIGHTNESS_300NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_316NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_333NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_350NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_357NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_365NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_372NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_380NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_387NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_395NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_403NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_412NIT] = {0xB5, 0xA0, 0x1C, 0x4A},
	[IBRIGHTNESS_420NIT] = {0xB5, 0xA0, 0x1C, 0x4A},
	[IBRIGHTNESS_443NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_465NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_488NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_510NIT] = {0xB5, 0xA0, 0x1C, 0x4F},
	[IBRIGHTNESS_533NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_555NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_578NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_600NIT] = {0xB5, 0xA0, 0x1C, 0x4A}
};

struct elvss_otp_info {
	unsigned int	nit;
	int not_otp[TEMP_MAX];
};

struct elvss_otp_info elvss_otp_data[IBRIGHTNESS_MAX] = {
	[IBRIGHTNESS_002NIT] = {2,	{0x10, 0x19, 0x1F}},
	[IBRIGHTNESS_003NIT] = {3,	{0x10, 0x18, 0x1E}},
	[IBRIGHTNESS_004NIT] = {4,	{0x10, 0x17, 0x1D}},
	[IBRIGHTNESS_005NIT] = {5,	{0x10, 0x17, 0x1C}},
	[IBRIGHTNESS_006NIT] = {6,	{0x11, 0x17, 0x18}},
	[IBRIGHTNESS_007NIT] = {7,	{0x13, 0x17, 0x1A}},
	[IBRIGHTNESS_008NIT] = {8,	{0x15, 0x18, 0x19}},
	[IBRIGHTNESS_009NIT] = {9,	{0x15, 0x17, 0x18}},
	[IBRIGHTNESS_010NIT] = {10,	{0x15, 0x17, 0x18}},
	[IBRIGHTNESS_011NIT] = {11,	{0x15, 0x16, 0x17}},
	[IBRIGHTNESS_012NIT] = {12,	{0x15, 0x16, 0x17}},
	[IBRIGHTNESS_013NIT] = {13,	{0x15, 0x15, 0x16}},
	[IBRIGHTNESS_014NIT] = {14,	{0x15, 0x15, 0x16}},
};

static unsigned char AOR_TABLE[256][AID_CMD_CNT] = {
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x0E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x01},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xFB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xE0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xD3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xCC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xBF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xB2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xAA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x9E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x90},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x7D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x71},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x63},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x59},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x50},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x42},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x3D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x30},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x1D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x0F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x06},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xFD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xE2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xDC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xCF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xB8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xAE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x9E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x8E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x71},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x69},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x61},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x51},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x41},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x36},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x2B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x20},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x0F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xFF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xEE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xCD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xBD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xAE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x9E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x8F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x70},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x61},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x51},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x42},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x32},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x18},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x01},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE7},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xED},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE7},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xFF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xEA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xE2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xCB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xB9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xAF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xA6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x9D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x94},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x85},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x7D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x75},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x6D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x66},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x5E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x55},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x4C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x43},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x39},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x30},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x27},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x1E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x14},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x0B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x02},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xF8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xEF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xE5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xD2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA7},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x96},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xC3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xBB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x94},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xC3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xBB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x94},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xC3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xBC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA7},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x99},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x92},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x93},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x98},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x91},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB7},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x9D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x97},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x91},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x95},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x97},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x91},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x84},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x7D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x77},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x70},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x6B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x67},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x62},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x5E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x57},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x50},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x49},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x42},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x3B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x34},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x2C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x25},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x19},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x12},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x21},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x13},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x18},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x12},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[] = {
	[0 ... 1] =		IBRIGHTNESS_002NIT,
	[2 ... 2] =		IBRIGHTNESS_003NIT,
	[3 ... 3] =		IBRIGHTNESS_004NIT,
	[4 ... 4] =		IBRIGHTNESS_005NIT,
	[5 ... 5] =		IBRIGHTNESS_006NIT,
	[6 ... 6] =		IBRIGHTNESS_007NIT,
	[7 ... 7] =		IBRIGHTNESS_008NIT,
	[8 ... 8] =		IBRIGHTNESS_009NIT,
	[9 ... 9] =		IBRIGHTNESS_010NIT,
	[10 ... 10] =		IBRIGHTNESS_011NIT,
	[11 ... 11] =		IBRIGHTNESS_012NIT,
	[12 ... 12] =		IBRIGHTNESS_013NIT,
	[13 ... 13] =		IBRIGHTNESS_014NIT,
	[14 ... 14] =		IBRIGHTNESS_015NIT,
	[15 ... 15] =		IBRIGHTNESS_016NIT,
	[16 ... 16] =		IBRIGHTNESS_017NIT,
	[17 ... 18] =		IBRIGHTNESS_019NIT,
	[19 ... 19] =		IBRIGHTNESS_020NIT,
	[20 ... 20] =		IBRIGHTNESS_021NIT,
	[21 ... 21] =		IBRIGHTNESS_022NIT,
	[22 ... 22] =		IBRIGHTNESS_024NIT,
	[23 ... 23] =		IBRIGHTNESS_025NIT,
	[24 ... 25] =		IBRIGHTNESS_027NIT,
	[26 ... 26] =		IBRIGHTNESS_029NIT,
	[27 ... 27] =		IBRIGHTNESS_030NIT,
	[28 ... 29] =		IBRIGHTNESS_032NIT,
	[30 ... 31] =		IBRIGHTNESS_034NIT,
	[32 ... 33] =		IBRIGHTNESS_037NIT,
	[34 ... 34] =		IBRIGHTNESS_039NIT,
	[35 ... 36] =		IBRIGHTNESS_041NIT,
	[37 ... 38] =		IBRIGHTNESS_044NIT,
	[39 ... 41] =		IBRIGHTNESS_047NIT,
	[42 ... 43] =		IBRIGHTNESS_050NIT,
	[44 ... 45] =		IBRIGHTNESS_053NIT,
	[46 ... 47] =		IBRIGHTNESS_056NIT,
	[48 ... 50] =		IBRIGHTNESS_060NIT,
	[51 ... 53] =		IBRIGHTNESS_064NIT,
	[54 ... 56] =		IBRIGHTNESS_068NIT,
	[57 ... 58] =		IBRIGHTNESS_072NIT,
	[59 ... 62] =		IBRIGHTNESS_077NIT,
	[63 ... 65] =		IBRIGHTNESS_082NIT,
	[66 ... 69] =		IBRIGHTNESS_087NIT,
	[70 ... 73] =		IBRIGHTNESS_093NIT,
	[74 ... 76] =		IBRIGHTNESS_098NIT,
	[77 ... 80] =		IBRIGHTNESS_105NIT,
	[81 ... 84] =		IBRIGHTNESS_111NIT,
	[85 ... 89] =		IBRIGHTNESS_119NIT,
	[90 ... 94] =		IBRIGHTNESS_126NIT,
	[95 ... 99] =		IBRIGHTNESS_134NIT,
	[100 ... 104] =		IBRIGHTNESS_143NIT,
	[105 ... 110] =		IBRIGHTNESS_152NIT,
	[111 ... 116] =		IBRIGHTNESS_162NIT,
	[117 ... 121] =		IBRIGHTNESS_172NIT,
	[122 ... 128] =		IBRIGHTNESS_183NIT,
	[129 ... 135] =		IBRIGHTNESS_195NIT,
	[136 ... 142] =		IBRIGHTNESS_207NIT,
	[143 ... 149] =		IBRIGHTNESS_220NIT,
	[150 ... 157] =		IBRIGHTNESS_234NIT,
	[158 ... 165] =		IBRIGHTNESS_249NIT,
	[166 ... 174] =		IBRIGHTNESS_265NIT,
	[175 ... 183] =		IBRIGHTNESS_282NIT,
	[184 ... 193] =		IBRIGHTNESS_300NIT,
	[194 ... 201] =		IBRIGHTNESS_316NIT,
	[202 ... 210] =		IBRIGHTNESS_333NIT,
	[211 ... 219] =		IBRIGHTNESS_350NIT,
	[220 ... 223] =		IBRIGHTNESS_357NIT,
	[224 ... 227] =		IBRIGHTNESS_365NIT,
	[228 ... 230] =		IBRIGHTNESS_372NIT,
	[231 ... 234] =		IBRIGHTNESS_380NIT,
	[235 ... 238] =		IBRIGHTNESS_387NIT,
	[239 ... 242] =		IBRIGHTNESS_395NIT,
	[243 ... 246] =		IBRIGHTNESS_403NIT,
	[247 ... 250] =		IBRIGHTNESS_412NIT,
	[251 ... 255] =		IBRIGHTNESS_420NIT,
	[256 ... 256] =		IBRIGHTNESS_443NIT,
	[257 ... 257] =		IBRIGHTNESS_465NIT,
	[258 ... 258] =		IBRIGHTNESS_488NIT,
	[259 ... 259] =		IBRIGHTNESS_510NIT,
	[260 ... 260] =		IBRIGHTNESS_533NIT,
	[261 ... 261] =		IBRIGHTNESS_555NIT,
	[262 ... 262] =		IBRIGHTNESS_578NIT,
	[263 ... 263] =		IBRIGHTNESS_600NIT
};

static unsigned int hbm_auto_brightness_table[] = {
	[0 ... 5] =	IBRIGHTNESS_420NIT,
	[6] =		IBRIGHTNESS_465NIT,
	[7] =		IBRIGHTNESS_488NIT,
	[8] =		IBRIGHTNESS_510NIT,
	[9] =		IBRIGHTNESS_533NIT,
	[10] =		IBRIGHTNESS_555NIT,
	[11] =		IBRIGHTNESS_578NIT,
	[12] =		IBRIGHTNESS_600NIT
};
#endif /* __S6E3AA2_A3XE_PARAM_H__ */
