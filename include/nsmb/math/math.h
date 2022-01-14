#pragma once
#include "nitro_if.h"
#include "extra/fx.hpp"


struct FxRect {
	fx32 x;
	fx32 y;
	fx32 halfWidth;
	fx32 halfHeight;
};

class Vec3;
class Vec2;


namespace Math {

	//u32:02043380
	//u16:02043398
	//s16:020433b0
	//u8:020433c8
	//s8:020433e0
	u32 timerTick(u32* timer);
	u16 timerTick(u16* timer);
	s16 timerTick(s16* timer);
	u8  timerTick(u8* timer);
	s8  timerTick(s8* timer);

	//020433f8
	//02043464
	//020434d8
	//s16:0204354c
	//020435a8

	//lerp:02043604
	void lerp(s16& start, s16 end, s16 ratio, s16 maxStep);

	//02043674
	s16 lerp(s16& start, s16 end, s16 ratio, s16 maxStep, s16 minStep);

	//02043750
	bool inRange(s32 x, s32 a, s32 b);

	//02043790
	s16 distance(s16 a, s16 b);

	//020437a4
	//020437f4

	//020848e4
	extern fx16 atan2Table[1025];

	//02043b6c
	fx16 atan2(fx32 y, fx32 x);

	//0208b668
	extern u32 frameCounter;

	//0208b66c
	extern u32 unusedCounter;

	//02043d10
	void resetFrameCounters();

	//02043d30
	fx16 angle(const Vec3& a, const Vec3& b);//X and Z

	//2D:02043d5c
	bool lerp(Vec2& start, const Vec2& end, fx32 step);

	//3D:02043e30
	bool lerp(Vec3& start, const Vec3& end, fx32 step);

	//02043f10
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep);

	//02043fe0
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//02044120
	void lerp(Vec3& start, const Vec3& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//020437a4 this is *not* a lerp
	void lerpFx32(fx32& start, fx32 end, fx32 ratio, fx32 maxStep);

	//02044280 (sub?)
	//void subtract();

	//020442b0
	u32 nextRandom(u32& value);

	//020442dc
	u32 generateSeed();


	constexpr s16 fromRadians(fx32 r) {
		return (r * FX32_CONST(0x10000)) / FX64C_TWOPI;
	}
	constexpr s16 fromDegrees(int d) {
		while (d >= 360) d -= 360;
		while (d < 0) d += 360;
		return static_cast<s16>((d * 0x10000) / 360);
	}

	template<typename T>
	constexpr void swap(T& a, T& b) {
		T tmp = a;
		a = b;
		b = tmp;
	}


#define ToFx16(x)		FX16_CONST(x)
#define ToFx32(x)		FX32_CONST(x)
#define ToFx64(x)		FX64_CONST(x)
#define ToFx64c(x)		FX64C_CONST(x)

#define IntToFx32(x)	((x) << 12)

#define Fx32ToF32(x)	((x) / (float)FX32_ONE)
#define Fx32ToInt(x)	FX_Whole(x)

#define ToAngle(x)		(((x) * 0x10000) / 360)


	__inline fx16 sin(int idx) {
		return FX_SinIdx(u32(idx) & 0xFFFF);
	}
	__inline fx16 cos(int idx) {
		return FX_CosIdx(u32(idx) & 0xFFFF);
	}
	constexpr fx32 mul(fx32 a, fx32 b) {
		return ((fx32)(((s64)(a)*b + FX32_HALF) >> FX32_SHIFT));
	}
	constexpr fx32 div(fx32 n, fx32 d) {
		if_consteval {
			return (s32)(((s64)(n << 12)) / (d));
		}
		else {
			return FX_Div(n, d);
		}
	}
	constexpr fx32 inv(fx32 d) {
		if_consteval {
			return div(FX32_ONE, d);
		}
		else {
			return FX_Inv(d);
		}
	}
	__inline fx32 sqrt(fx32 p) {
		return FX_Sqrt(p);
	}

	constexpr fx32 lerpFx(fx32 start, fx32 end, fx32 factor) {
		return mul(end - start, factor) + start;
	}
	template<class A, class B>
	constexpr auto lerpInt(A start, B end, fx32 factor) {
		fx32 a = start * FX32_ONE;
		fx32 b = end * FX32_ONE;
		return FX_Whole(lerpFx(a, b, factor));
	}
	
	constexpr fx32 abs(fx32 a) {
		return (a < 0) ? -a : a;
	}
	
	constexpr fx32 clamp(fx32 a, fx32 min, fx32 max) {
        return a < min ? min : (a > max ? max : a);
    }

	constexpr fx32 smoothstep(fx32 start, fx32 end, fx32 step)
	{
		step = clamp(step, 0, 1.0fx);
        step = mul(mul(mul(-2.0fx, step), step), step) + mul(mul(3.0fx, step), step);
        return mul(end, step) + mul(start, (1.0fx - step));
	}

	__inline s32 getRangedValue(s32 value, s32 max) {
		return value % max;
	}

	__inline s32 getRangedValue(s32 value, s32 min, s32 max) {
		return (value % (max - min)) + min;
	}

#define IMPL_RANDOM(function) \
	__inline s32 getRandom(s32 max) { return Math::getRangedValue((function)(), max); } \
	__inline s32 getRandom(s32 min, s32 max) { return Math::getRangedValue((function)(), min, max); }

	//02044308 wtf

}
