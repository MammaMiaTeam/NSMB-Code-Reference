#pragma once

#include "nsmb_nitro.hpp"
#include "nsmb/math/rectangle.hpp"
#include "nsmb/math/math.hpp"

class StageZone
{
public:
	u16 x;
	u16 y;
	u16 width;
	u16 height;
	u8 id;
	u8 unk9;
	u8 unkA;
	u8 unkB;

	// 0x0201EEF8
	static StageZone* get(u8 id, Rectangle<fx32>* outRect);
};
