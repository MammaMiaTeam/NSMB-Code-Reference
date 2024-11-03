#pragma once

#include "nsmb_nitro.hpp"

struct StageObject {

	u16 id;
	u16 x;
	u16 y;
	u8 events[2];
	u32 settings;

};
NTR_SIZE_GUARD(StageObject, 0xC);
