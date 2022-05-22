#pragma once
#include "nitro_if.h"


class Random
{
public:

	NTR_INLINE Random() : Random(1) {}

	// 02044308
	Random(u32 seed);

	// 02006EE4
	~Random();

	// 020442B0
	u32 update();

	// 020442DC
	static u32 generateSeed();


	u32 value;

};
