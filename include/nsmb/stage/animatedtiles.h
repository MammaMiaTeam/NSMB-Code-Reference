#pragma once
#include "nitro_if.h"


// vtable at 0212675C (ov10)
class AnimatedTiles
{
public:

	// 020E2978
	AnimatedTiles();

	// D0: 020E2948
	// D1: 020E2968
	virtual ~AnimatedTiles();

	// 020E27D4
	static bool update();

	// 02129438
	static u8 coinFrame;

	// 0212943C
	static u8 brickFrame;

	// 02129440
	static u8 brickTimer;

	// 02129444
	static u8 coinTimer;

	// 02129448
	static u8 questionBlockTimer;

	// 0212944C
	static u8 questionBlockFrame;

	// 0212945C
	// Used by StarCoin and VSBattleStar
	static Vec3s coinRotation;

	// 02129474
	// Used by SpinBlock
	static Vec3s questionBlockRotation;

};
NTR_SIZE_GUARD(AnimatedTiles, 0x4);
