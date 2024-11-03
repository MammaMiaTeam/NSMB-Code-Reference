#pragma once

#include "nsmb_nitro.hpp"

enum {
	MBP_STATE_STOP,
	MBP_STATE_IDLE,
	MBP_STATE_ENTRY,
	MBP_STATE_DATASENDING,
	MBP_STATE_REBOOTING,
	MBP_STATE_COMPLETE,
	MBP_STATE_CANCEL,
	MBP_STATE_ERROR
};

struct MBPChildInfo {

	MBUserInfo userInfo;
	u8 macAddress[6];

	union {
		u16 playerNo;
		u8 data[2];
	};

};
