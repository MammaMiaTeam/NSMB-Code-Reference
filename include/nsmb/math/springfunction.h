#pragma once
#include "nitro_if.h"
#include "math.h"


class SpringFunction
{
public:

	inline SpringFunction() {}

	// 0201DBCC
	void create(fx32 force, fx32 attenuation, fx32 origin, fx32 forceMax);

	// 0201DA70
	fx32 processSpring(fx32 pivot, bool restart = false);

	// 0201DA28
	fx32 processExponentialSmooth(fx32 start, fx32 end, fx32 factor, fx32 max, fx32 min);


	fx32 value;
	fx32 pivot;
	fx32 forceStep;
	fx32 forceMax;
	fx32 attenuationStep;
	fx32 force;
	fx32 attenuation;
	u16 springTimer;
	bool apexReached;
	bool stopped;

};
NTR_SIZE_GUARD(SpringFunction, 0x20);
