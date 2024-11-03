#pragma once

#include "nsmb_nitro.hpp"

struct StageScreen {

	u16 id;
	u16 screenID;
	u16 paletteID;
	u16 parallaxInfoX;
	u16 parallaxInfoY;
	u16 scrollSpeedX;
	u16 scrollSpeedY;
	u16 verticalOffset;
	u16 unused10;
	u16 unused12;

};
NTR_SIZE_GUARD(StageScreen, 0x14);
