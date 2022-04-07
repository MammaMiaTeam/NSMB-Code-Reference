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
	sym BlendColor() __body

	// D0: 020e9170
	// D1: 020e9190
	sym virtual ~BlendColor() __body


	// 020e9120
	sym u16 blendChannel(u16& channel, u16 target, u16 amount) { __ret }

	// 020e9018
	sym bool blend(GXRgb target, u32 factor) { __ret }


};
NTR_SIZE_GUARD(BlendColor, 0x18);
