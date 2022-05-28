#pragma once
#include "nitro_if.h"


class BlendColor
{

	using rgb_t = struct {

		u16 r, g, b;

		constexpr u16 packed() const {
			return GX_RGB(r >> 8, g >> 8, b >> 8);
		}

		constexpr void set(u8 r, u8 g, u8 b) {
			this->r = u16(r) << 8;
			this->g = u16(g) << 8;
			this->b = u16(b) << 8;
		}

	};

public:

	rgb_t color;
	rgb_t target;
	rgb_t difference;

	// 020E91A0
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
