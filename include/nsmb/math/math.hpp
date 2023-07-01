#pragma once
#include "nsmb_nitro.hpp"
#include "nsmb/extra/fixedpoint.hpp"


struct FxRect { // TODO Proper class in its own file
	fx32 x;
	fx32 y;
	fx32 halfWidth;
	fx32 halfHeight;
};

class Vec3;
class Vec2;
class Vec3s;

namespace Math { // TODO Global cleanup

	template<CC::Integer I>
	NTR_INLINE I tick(I& value) {
		return value ? --value : value;
	}

	template<> s32 Math::tick(s32& value);
	template<> u16 Math::tick(u16& value);
	template<> s16 Math::tick(s16& value);
	template<> u8 Math::tick(u8& value);
	template<> s8 Math::tick(s8& value);

	template<CC::Integer I>
	NTR_INLINE bool stepFx(I& value, I target, I step) {

		if (!step) {
			return value == target;
		}

		if (target < value) {
			step = -step;
		}

		value += step;

		if ((value - target) * step >= 0) {
			value = target;
			return true;
		}

		return false;

	}

	template<> bool stepFx(fx16& value, fx16 target, fx16 step);
	template<> bool stepFx(fx32& value, fx32 target, fx32 step);

	template<CC::Integer I>
	NTR_INLINE bool step(I& value, I target, I step) {

		if (!step) {
			return value == target;
		}

		if (target < value) {
			step = -step;
		}

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

		if (d > 0) {
			while (d >= 360.0f) { d -= 360.0f; }
		} else {
			while (d < 0.0f) { d += 360.0f; }
		}

		return s32((d * 0x10000) / 360);

	}

	NTR_INLINE constexpr s16 rad(fx32 r) {
		return (fx64(r) * FX64_CONST(0x10000)) / 0x6487ED5;
	}

	NTR_INLINE constexpr s16 deg(s32 d) {

		if (d > 0) {
			while (d >= 360) { d -= 360; }
		} else {
			while (d < 0) { d += 360; }
		}

		return s16(s32((d * 0x10000) / 360));

	}

	template<CC::Integer I>
	NTR_INLINE constexpr void swap(I& a, I& b) {
		I tmp = a;
		a = b;
		b = tmp;
	}


	NTR_INLINE fx16 sin(int idx) {
		return FX_SinIdx(u32(idx) & 0xFFFF);
	}

	NTR_INLINE fx16 cos(int idx) {
		return FX_CosIdx(u32(idx) & 0xFFFF);
	}

	NTR_INLINE constexpr fx32 mul(fx32 a, fx32 b) {
		return fx32((s64(a) * b + Fx32::Half) >> Fx32::Shift);
	}

	NTR_INLINE constexpr fx64 mul64(fx32 a, fx32 b) {
		return (s64(a) * s64(b) + Fx64::Half) >> Fx64::Shift;
	}

	NTR_INLINE constexpr fx32 mul32x64c(fx32 a, fx64c b) {
		return (s64(a) * s64(b) + Fx64c::Half) >> Fx64c::Shift;
	}

	NTR_INLINE constexpr fx32 div(fx32 n, fx32 d) {

		if consteval {
			return s32(s64(n << Fx32::Shift) / d);
		} else {
			return FX_Div(n, d);
		}

	}

	NTR_INLINE constexpr fx64c div64c(fx32 n, fx32 d) {

		if consteval {
			return (s64(n) << Fx64c::Shift) / d;
		} else {
			return FX_DivFx64c(n, d);
		}

	}

	NTR_INLINE constexpr fx32 inv(fx32 d) {

		if consteval {
			return Math::div(Fx32::One, d);
		} else {
			return FX_Inv(d);
		}

	}

	NTR_INLINE constexpr fx64c inv64c(fx32 d) {
		return div64c(Fx32::One, d);
	}

	NTR_INLINE fx32 sqrt(fx32 p) {
		return FX_Sqrt(p);
	}

	NTR_INLINE constexpr fx32 lerpFx(fx32 start, fx32 end, fx32 factor) {
		return mul(end - start, factor) + start;
	}

	template<class A, class B>
	NTR_INLINE constexpr auto lerpInt(A start, B end, fx32 factor) {
		fx32 a = start * Fx32::One;
		fx32 b = end * Fx32::One;
		return FX_Whole(lerpFx(a, b, factor));
	}

	template<CC::IntegerBased A, CC::IntegerBased B>
	NTR_INLINE constexpr auto max(A a, B b) {
		return a > b ? a : b;
	}

	template<CC::IntegerBased A, CC::IntegerBased B>
	NTR_INLINE constexpr auto min(A a, B b) {
		return a < b ? a : b;
	}

	template<CC::IntegerBased I>
	NTR_INLINE constexpr I abs(I a) {
		return (a < 0) ? -a : a;
	}

	template<CC::IntegerBased A, CC::IntegerBased B, CC::IntegerBased C>
	NTR_INLINE constexpr auto clamp(A a, B min, C max) {
		return (a < min) ? min : ((a > max) ? max : a);
	}

	constexpr fx32 smoothstep(fx32 start, fx32 end, fx32 step) {

		step = clamp(step, 0, 1.0fx);

		step = mul(mul(mul(-2.0fx, step), step), step) + mul(mul(3.0fx, step), step);

		return mul(end, step) + mul(start, (1.0fx - step));

	}

}

PP_DIAGNOSTIC_PUSH()
PP_DIAGNOSTIC_IGNORE("-Wliteral-suffix")

consteval s32 operator""rad(long double r) {

	constexpr long double TwoPi = 6.28318530718;

	if (r > 0) {
		while (r >= TwoPi) { r -= TwoPi; }
	} else {
		while (r < 0.0f) { r += TwoPi; }
	}

	return s32(s32((r * 0x10000) / TwoPi));

}

consteval s32 operator""deg(long double d) {
	return Math::cdeg(d);
}

consteval s32 operator""deg(unsigned long long d) {
	return Math::cdeg(d);
}

PP_DIAGNOSTIC_POP()
