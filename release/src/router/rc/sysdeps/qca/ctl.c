#include <rc.h>
#include <stdio.h>
#include <qca.h>
#include <asm/byteorder.h>
#include <shared.h>
#include "flash_mtd.h"

#define EEPROM_2G_CTL_OFFSET	0x136
#define EEPROM_2G_CTL_SIZE	108
#define EEPROM_5G_CTL_OFFSET	0x610
#define EEPROM_5G_CTL_SIZE	308

#define MAX_COUNTRY_LIST_SIZE	10

typedef struct {
	unsigned char ctl[EEPROM_2G_CTL_SIZE];
	char *country_list[MAX_COUNTRY_LIST_SIZE];
} table_2;

typedef struct {
	unsigned char ctl[EEPROM_5G_CTL_SIZE];
	char *country_list[MAX_COUNTRY_LIST_SIZE];
} table_5;

#if defined(RTAC55U) // CTL table comes from RF
table_2 ctl_2g_table[]=
{
	{
		{
		0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32,
		0x35, 0x37, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75,
		0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c
		},
		//// country list
		{ "DB", NULL }
	},
	{
		{
		0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32,
		0x35, 0x37, 0x70, 0x75, 0xa2, 0xb8, 0x70, 0x75, 0xa2, 0xb8, 0x70, 0x75, 0xa2, 0xb8, 0x70, 0x75, 0xa2, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75,
		0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x23, 0x68, 0x26, 0x7c, 0x22, 0x6a, 0x20, 0x7c, 0x22, 0x6a, 0x1f, 0x7c, 0x18, 0x63,
		0x1c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c
		},
		//// country list
		{ "US", "CA", "TW", NULL }
	},
	{
		{
		0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32,
		0x35, 0x37, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75,
		0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x1e, 0x5e, 0x1e, 0x7c, 0x1e, 0x5e, 0x1e, 0x7c, 0x1e, 0x5e, 0x1e, 0x7c, 0x1e, 0x5e,
		0x1e, 0x5e
		},
		//// country list
		{ "SG", NULL }
	},
	{
		{
		0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32,
		0x35, 0x37, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75,
		0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x15, 0x55, 0x16, 0x7c, 0x15, 0x54, 0x14, 0x7c, 0x18, 0x57, 0x17, 0x7c, 0x17, 0x56,
		0x16, 0x5e,
		},
		//// country list
		{ "CN", NULL }
	},
	{
		{
		0x11, 0x12, 0x15, 0x17, 0x41, 0x42, 0x45, 0x47, 0x31, 0x32,
		0x35, 0x37, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75,
		0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x70, 0x75, 0xac, 0xb8, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x1c, 0x5c, 0x1b, 0x7c, 0x1c, 0x5d, 0x1c, 0x7c, 0x1c, 0x5c, 0x1d, 0x7c, 0x1c, 0x5d,
		0x1c, 0x7c,
		},
		//// country list
		{ "HU", NULL }
	},
};

table_5 ctl_5g_table[]=
{
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c
		},
		//// country list
		{ "DB", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x28, 0x70, 0x30, 0x7c, 0x3c, 0x2f, 0x6f, 0x2e, 0x27, 0x70, 0x30, 0x7c,
		0x3c, 0x2f, 0x6f, 0x2e, 0x1f, 0x6e, 0x3c, 0x7c, 0x3c, 0x3c, 0x2e, 0x2e, 0x1d, 0x3c, 0x3c, 0x3c, 0x3c, 0x2e, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c
		},
		//// country list
		{ "US", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x15, 0x56, 0x16, 0x7c, 0x3c, 0x2f, 0x6f, 0x2e, 0x17, 0x56, 0x17, 0x7c,
		0x3c, 0x2f, 0x6f, 0x2e, 0x19, 0x59, 0x3c, 0x7c, 0x3c, 0x3c, 0x2e, 0x2e, 0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x2e, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c
		},
		//// country list
		{ "CA", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x60, 0x62, 0x68, 0x6c, 0xb4, 0xbd, 0xc1, 0xcd, 0x60, 0x62, 0x68, 0x6c, 0xb4, 0xbd, 0xc1, 0xcd, 0x66, 0x68, 0x6c, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x66, 0x76, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x17, 0x56, 0x16, 0x7c, 0x3c, 0x2f, 0x6f, 0x2e, 0x16, 0x56, 0x16, 0x7c,
		0x3c, 0x2f, 0x6f, 0x2e, 0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x2e, 0x2e, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x2e, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c
		},
		//// country list
		{ "TW", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x1e, 0x5e, 0x1e, 0x7c, 0x3c, 0x2c, 0x6c, 0x2c, 0x1e, 0x5e, 0x1e, 0x7c,
		0x3c, 0x2c, 0x6c, 0x2c, 0x1e, 0x5e, 0x3c, 0x7c, 0x3c, 0x3c, 0x2c, 0x2c, 0x1e, 0x3c, 0x3c, 0x3c, 0x3c, 0x2c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c
		},
		//// country list
		{ "SG", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x26, 0x66, 0x27, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x26, 0x66, 0x27, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x26, 0x26, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x24, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c,
		},
		//// country list
		{ "CN", NULL }
	},
	{
		{
		0x10, 0x16, 0x18, 0x19, 0x1b, 0x1d, 0x40, 0x46, 0x48, 0x49, 0x4b, 0x4d, 0x30, 0x36, 0x38, 0x39,
		0x3b, 0x3d, 0x00, 0x00, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4c, 0x50, 0x58, 0x5c, 0xb4, 0xbd, 0xc1, 0xcd, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4c, 0x58, 0x5c, 0x68,
		0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66, 0x8e, 0x96, 0xa6, 0xae, 0x52, 0x62, 0x92, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x58, 0x5c, 0x68, 0x8c, 0x90, 0xb0, 0xb4, 0x4e, 0x56, 0x5e, 0x66,
		0x8e, 0x96, 0xa6, 0xae, 0x4c, 0x50, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4c, 0x5c, 0x68, 0x8c, 0xb4, 0xb8, 0xbd, 0xc1, 0x4e, 0x56, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x52, 0x62, 0x92, 0xa2,
		0xb2, 0xc3, 0x00, 0x00, 0x4c, 0x5c, 0x60, 0x8c, 0xb4, 0xb8, 0xbd, 0xcd, 0x4e, 0x5e, 0x66, 0x8e, 0xae, 0xb6, 0xbf, 0xc7, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
		0x00, 0x00, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x3c, 0x3c, 0x1e, 0x5e, 0x1e, 0x7c, 0x3c, 0x3c, 0x3c, 0x7c, 0x1f, 0x5f, 0x1f, 0x7c,
		0x3c, 0x3c, 0x7c, 0x7c, 0x1e, 0x1e, 0x5e, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1e, 0x1e, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x7c, 0x3c, 0x7c, 0x7c, 0x3c, 0x3c, 0x7c, 0x3c, 0x7c, 0x3c, 0x3c, 0x7c,
		0x3c, 0x3c, 0x3c, 0x3c,
		},
		//// country list
		{ "HU", NULL }
	},
};
#else
table_2 ctl_2g_table[]=
{
	{
		.country_list = { NULL },
	}
};

table_5 ctl_5g_table[]=
{
	{
		.country_list = { NULL },
	}
};
#endif

static void ctl_update(char *country, int band)
{
	int region_count,i,j;
	char *eeprom_ptr=NULL;
	if (band==2) {
		region_count=ARRAY_SIZE(ctl_2g_table);
		for (i=0;i<region_count;i++) {
			for (j=0;ctl_2g_table[i].country_list[j]!=NULL;j++) {
				if (strcmp(country,ctl_2g_table[i].country_list[j])==0) {
					eeprom_ptr=ctl_2g_table[i].ctl;
					break;
				}
			}
			if (eeprom_ptr)
				break;
		}
		if (eeprom_ptr) { // found the matching country
			FWrite(eeprom_ptr, OFFSET_MAC_ADDR_2G-QCA9557_EEPROM_MAC_OFFSET+EEPROM_2G_CTL_OFFSET, EEPROM_2G_CTL_SIZE);
		}
	}
	else {
		region_count=ARRAY_SIZE(ctl_5g_table);
		for (i=0;i<region_count;i++) {
			for (j=0;ctl_5g_table[i].country_list[j]!=NULL;j++) {
				if (strcmp(country,ctl_5g_table[i].country_list[j])==0) {
					eeprom_ptr=ctl_5g_table[i].ctl;
					break;
				}
			}
			if (eeprom_ptr)
				break;
		}
		if (eeprom_ptr) { // found the matching country
			unsigned char eeprom[QC98XX_EEPROM_SIZE_LARGEST];
			if (FRead(eeprom, OFFSET_MAC_ADDR-QC98XX_EEPROM_MAC_OFFSET, QC98XX_EEPROM_SIZE_LARGEST) < 0)
				dbg("EEPROM 5G: Out of scope\n");
			else {
				//1. check original checksum first
				if (qc98xx_verify_checksum(eeprom))
					dbg("[%s]Invalid 5G eeprom\n",__func__);
				else { // update & compute new checksum

					unsigned short *p_half;
					unsigned short cur_sum;

					cur_sum = 0;
					// clear original checksum
					*((unsigned short *)eeprom + 1) = __cpu_to_le16(cur_sum);
					// update new ctl
					memcpy(eeprom+EEPROM_5G_CTL_OFFSET,eeprom_ptr,EEPROM_5G_CTL_SIZE);
					// compute new sum
					p_half = (unsigned short *)&eeprom[0];
					for (i = 0; i < (QC98XX_EEPROM_SIZE_LARGEST/2); i++) 
						cur_sum ^= __le16_to_cpu(p_half[i]);
					cur_sum ^= 0xFFFF; // invert
					// update new sum
					*((unsigned short *)eeprom + 1) = __cpu_to_le16(cur_sum);
					//if (qc98xx_verify_checksum(eeprom)==0)
					FWrite(eeprom, OFFSET_MAC_ADDR-QC98XX_EEPROM_MAC_OFFSET, QC98XX_EEPROM_SIZE_LARGEST);
				}
			}
		}

	}
}

void setCTL(char *CC)
{
	ctl_update(CC, 2);
	ctl_update(CC, 5);
}
