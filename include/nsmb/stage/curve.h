#pragma once
#include "nsmb/math/vector.h"


namespace Curve {
	
	// 020F4734
	fx32 combineProduct(fx32 x1, fx32 x2, fx32 x3, fx64 a, fx64 b, fx64 c);

	// 020F47A4
	fx64 parabolaLeft(fx32 value);

	// 020F47BC
	fx64 parabolaDown(fx32 value);

	// 020F47E4
	fx64 parabolaRight(fx32 value);

	// 020F4800
	Vec2* bendPoints(const Vec2* start, const Vec2* end, Vec2* out, u32 count, fx32 distance);

	// 020F4894
	Vec2* samplePoints(const Vec2* pt1, const Vec2* pt2, const Vec2* pt3, Vec2* out, u32 count, fx32 distance);

}
