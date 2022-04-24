#pragma once
#include "nitro_if.h"
#include "math.h"


class ArcFunction
{
public:

	// C2: 0200AC90
	ArcFunction();
	// D2: 0200AC80
	~ArcFunction();

	// 0200ABC4
	void init(const Vec3& target, const Vec3& current, fx32 range, s32 duration);

	// 0200AB24
	bool process(Vec3& position);


	Vec3 target;
	fx32 factor;
	fx32 range;
	fx32 value;
	fx32 stepX;
	fx32 stepY;
	s32 duration;
	s32 current;

};
NTR_SIZE_GUARD(ArcFunction, 0x2C);
