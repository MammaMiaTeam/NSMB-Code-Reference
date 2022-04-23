#pragma once
#include "nitro_if.h"


class BlendColor
{

	using rgb_t = struct { u16 r, g, b; };

public:

	rgb_t color;
	rgb_t target;
	rgb_t difference;

	// 020e91a0
	BlendColor();

	// D0: 020E9170
	// D1: 020E9190
	virtual ~BlendColor();


	// 020E9120
	u16 blendChannel(u16& channel, u16 target, u16 amount);

	// 020E9018
	bool blend(GXRgb target, u32 factor);


};
NTR_SIZE_GUARD(BlendColor, 0x18);
