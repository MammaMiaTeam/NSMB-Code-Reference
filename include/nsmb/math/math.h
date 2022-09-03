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
class Vec3s;

namespace Math {

	template<class T>
	NTR_INLINE T tick(T& value) {
		return value ? --value : value;
	}

	template<> s32 Math::tick(s32& value);
	template<> u16 Math::tick(u16& value);
	template<> s16 Math::tick(s16& value);
	template<> u8 Math::tick(u8& value);
	template<> s8 Math::tick(s8& value);

	template<class T>
	NTR_INLINE bool stepFx(T& value, T target, T step) {

		if (!step)
			return value == target;

		if (target < value)
			step = -step;

		value += step;

		if ((value - target) * step >= 0) {
			value = target;
			return true;
		}

		return false;

	}

	template<> bool stepFx(fx16& value, fx16 target, fx16 step);
	template<> bool stepFx(fx32& value, fx32 target, fx32 step);

	template<class T>
	NTR_INLINE bool step(T& value, T target, T step) {

		if (!step)
			return value == target;

		if (target < value)
			step = -step;

		value += step;

		if ((value - target) * step >= 0) {
			value = target;
			return true;
		}

		return false;

	}

	template<> bool step(s32& value, s32 target, s32 step);
	template<> bool step(s16& value, s16 target, s16 step);
	template<> bool step(s8& value, s8 target, s8 step);

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


	consteval s16 crad(fx32 r) {
		return (fx64(r) * FX64_CONST(0x10000)) / 0x6487ED5;
	}
	consteval s32 cdeg(long double d) {

		if (d > 0)
			while (d >= 360.0f) d -= 360.0f;
		else
			while (d < 0.0f) d += 360.0f;

		return s32((d * 0x10000) / 360);

	}

	constexpr s16 rad(fx32 r) {
		return (fx64(r) * FX64_CONST(0x10000)) / 0x6487ED5;
	}
	constexpr s16 deg(s32 d) {

		if (d > 0)
			while (d >= 360) d -= 360;
		else
			while (d < 0) d += 360;

		return s16(s32((d * 0x10000) / 360));

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


	inline fx16 sin(int idx) {
		return FX_SinIdx(u32(idx) & 0xFFFF);
	}

	inline fx16 cos(int idx) {
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

	inline fx32 sqrt(fx32 p) {
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

	template<class A, class B>
	constexpr auto max(A a, B b) {
		return a > b ? a : b;
	}

	template<class A, class B>
	constexpr auto min(A a, B b) {
		return a < b ? a : b;
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

}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"

consteval s32 operator""rad(long double r) {

	constexpr long double twopi = 6.28318530718;

	if (r > 0)
		while (r >= twopi) r -= twopi;
	else
		while (r < 0.0f) r += twopi;

	return s32(s32((r * 0x10000) / twopi));

}

consteval s32 operator""deg(long double d) {

	if (d > 0)
		while (d >= 360.0f) d -= 360.0f;
	else
		while (d < 0.0f) d += 360.0f;

	return s32((d * 0x10000) / 360);

}

consteval s32 operator""deg(unsigned long long d) {

	if (d > 0)
		while (d >= 360.0f) d -= 360.0f;
	else
		while (d < 0.0f) d += 360.0f;

	return s32((d * 0x10000) / 360);

}

#pragma GCC diagnostic pop

