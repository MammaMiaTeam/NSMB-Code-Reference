#pragma once
#include "nitro_if.h"


class AnimatedTiles
{
public:

	AnimatedTiles();

	virtual ~AnimatedTiles();

	// 020e27d4
	static bool update();

	// 0212944c
	static u8 questionBlockFrame;

	// 0212943c
	static u8 brickFrame;

	// 02129438
	static u8 coinFrame;
};
NTR_SIZE_GUARD(AnimatedTiles, 0x4);
