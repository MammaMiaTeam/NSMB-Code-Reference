#ifndef NSMB_MATH_INCLUDED
#define NSMB_MATH_INCLUDED

#include "nitro_if.h"

namespace Math
{
	s32 sqrt64(u32 lo, u32 hi);

	inline s32 sqrt64(s64 val) {
		return sqrt64((u32)val, (u32)val >> 32);
	}
}

#endif	// NSMB_MATH_INCLUDED
