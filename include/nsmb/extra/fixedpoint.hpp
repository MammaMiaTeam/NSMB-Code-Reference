#pragma once

#include "meta.hpp"
#include "preprocessor.hpp"
#include "bits.hpp"

#include <compare>
#include <algorithm>


template<CC::SignedInteger I, SizeT Fract>
	requires (Fract < Bits::bitCount<I>() && Fract != 0)
class FixedPoint;


namespace CC {

	namespace Detail {

		template<class T>
		struct IsFixed {
			static constexpr bool Value = false;
		};

		template<CC::SignedInteger I, SizeT Fract>
		struct IsFixed<FixedPoint<I, Fract>> {
			static constexpr bool Value = true;
		};

	}

	template<class T>
	concept Fixed = Detail::IsFixed<T>::Value;

	template<class T, SizeT Fract>
	concept FractFixed = Fixed<T> && (T::Shift == Fract);

	template<class T>
	concept IntegerBased = Fixed<T> || Integer<T>;

}

using Fx16 = FixedPoint<s16, 12>;
using Fx32 = FixedPoint<s32, 12>;
using Fx64 = FixedPoint<s64, 12>;
using Fx64c = FixedPoint<s64, 32>;


template<CC::SignedInteger I, SizeT Fract>
	requires (Fract < Bits::bitCount<I>() && Fract != 0)
class FixedPoint {

public:

	using IntegerT = I;

	struct SplitResult {
		I integer;
		I fractional;
	};

	static constexpr bool IsFx32 = CC::Equal<FixedPoint, Fx32>;

	static constexpr SizeT FractionBits = Fract;
	static constexpr SizeT Shift = Fract;

	static constexpr FixedPoint Min = FixedPoint(-1);
	static constexpr FixedPoint Max = FixedPoint(Bits::ones<I>(Bits::bitCount<I>() - 1));

	static constexpr FixedPoint One = FixedPoint(1ULL << Shift);
	static constexpr FixedPoint Half = One / 2;


	constexpr FixedPoint() : i(0) {}

	template<CC::Integral J>
	constexpr explicit FixedPoint(J j) : i(j) {}

	template<CC::Float F>
	consteval FixedPoint(F f) : i(One.raw() * f + F(0.5)) {} // TODO Avoid dupe with set

	template<CC::Fixed F>
	constexpr explicit FixedPoint(F x) : i(0) { set(x); }


	template<CC::Integer J>
	constexpr FixedPoint& add(J x) {
		i += x;
		return *this;
	}

	template<CC::Fixed F>
	constexpr FixedPoint& add(F x) {
		i += FixedPoint<I, Fract>(x).i;
		return *this;
	}

	template<CC::Integer J>
	constexpr FixedPoint& subtract(J x) {
		i -= x;
		return *this;
	}

	template<CC::Fixed F>
	constexpr FixedPoint& subtract(F x) {
		i -= FixedPoint<I, Fract>(x).i;
		return *this;
	}

	template<CC::Integer J>
	constexpr FixedPoint& multiply(J x) {
		i *= x;
		return *this;
	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	NTR_INLINE constexpr FixedPoint& multiply(F x) {

		bool constants = __builtin_constant_p(x) && __builtin_constant_p(i);

		if (constants || std::is_constant_evaluated()) {
			return multiplyInternal(x);
		} else if constexpr (IsFx32 && F::IsFx32) {
			i = FX_Mul(i, x.raw());
			return *this;
		} else {
			return multiplyInternal(x);
		}

	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	constexpr FixedPoint& multiplyInternal(F x) {

		using X = TT::MaxType<I, typename F::IntegerT>;
		using K = TT::BiggerIntegerClamp<X>;

		K k = K(x.i) * i;
		k += K(1) << (Fract + F::Shift - 1);
		k >>= F::Shift;

		i = k;

		return *this;

	}

	template<CC::Integer J>
	constexpr FixedPoint& divide(J x) {
		i /= x;
		return *this;
	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	NTR_INLINE constexpr FixedPoint& divide(F x) {

		bool constants = __builtin_constant_p(x) && __builtin_constant_p(i);

		if (constants || std::is_constant_evaluated()) {
			return divideInternal(x);
		} else if constexpr (IsFx32 && F::IsFx32) {
			i = FX_Div(i, x.raw());
			return *this;
		} else {
			return divideInternal(x);
		}

	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	constexpr FixedPoint& divideInternal(F x) {

		using X = TT::MaxType<I, typename F::IntegerT>;
		using K = TT::BiggerIntegerClamp<X>;

		K k = K(i) << F::Shift;
		i = k / x.i;

		return *this;

	}

	template<CC::Integer J>
	constexpr FixedPoint& mod(J x) {
		i %= x;
		return *this;
	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	NTR_INLINE constexpr FixedPoint& mod(F x) {

		bool constants = __builtin_constant_p(x) && __builtin_constant_p(i);

		if (constants || std::is_constant_evaluated()) {
			return modInternal(x);
		} else if constexpr (IsFx32 && F::IsFx32) {
			i = FX_Mod(i, x.raw());
			return *this;
		} else {
			return modInternal(x);
		}

	}

	template<CC::Fixed F> requires(Shift < 32 || F::Shift < 32)
	constexpr FixedPoint& modInternal(F x) {

		using X = TT::MaxType<I, typename F::IntegerT>;
		using K = TT::BiggerIntegerClamp<X>;

		K k = K(i) << F::Shift;
		i = k % x.i;

		return *this;

	}

	constexpr FixedPoint& shiftLeft(SizeT n) {
		i <<= n;
		return *this;
	}

	constexpr FixedPoint& shiftRight(SizeT n) {
		i >>= n;
		return *this;
	}


	template<CC::Integer J>
	constexpr FixedPoint& bitAnd(J x) {
		i &= x;
		return *this;
	}

	template<CC::Integer J>
	constexpr FixedPoint& bitOr(J x) {
		i |= x;
		return *this;
	}

	template<CC::Integer J>
	constexpr FixedPoint& bitXor(J x) {
		i ^= x;
		return *this;
	}


	constexpr FixedPoint& bitAnd(FixedPoint x) {
		return bitAnd(x.i);
	}

	constexpr FixedPoint& bitOr(FixedPoint x) {
		return bitOr(x.i);
	}

	constexpr FixedPoint& bitXor(FixedPoint x) {
		return bitXor(x.i);
	}


	constexpr FixedPoint complement() const {
		return FixedPoint(~i);
	}

	constexpr FixedPoint abs() const {
		return FixedPoint((i < 0) ? -i : i);
	}

	constexpr FixedPoint negate() const {
		return FixedPoint(-i);
	}


	template<CC::Integer J>
	constexpr FixedPoint& operator=(J x) {
		set(x);
		return *this;
	}

	template<CC::Float F>
	consteval FixedPoint& operator=(F f) {
		set(f);
		return *this;
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator=(F x) {
		set(x);
		return *this;
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator+=(J x) {
		return add(x);
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator+=(F x) {
		return add(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator-=(J x) {
		return subtract(x);
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator-=(F x) {
		return subtract(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator*=(J x) {
		return multiply(x);
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator*=(F x) {
		return multiply(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator/=(J x) {
		return divide(x);
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator/=(F x) {
		return divide(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator%=(J x) {
		return mod(x);
	}

	template<CC::Fixed F>
	constexpr FixedPoint& operator%=(F x) {
		return mod(x);
	}

	constexpr FixedPoint operator-() const {
		return negate();
	}

	constexpr FixedPoint& operator<<=(SizeT n) {
		return shiftLeft(n);
	}

	constexpr FixedPoint& operator>>=(SizeT n) {
		return shiftRight(n);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator&=(J x) {
		return bitAnd(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator|=(J x) {
		return bitOr(x);
	}

	template<CC::Integer J>
	constexpr FixedPoint& operator^=(J x) {
		return bitXor(x);
	}

	constexpr FixedPoint operator~() const {
		return ~i;
	}


	template<CC::Integer J>
	constexpr void set(J x) {
		*this = fromRaw(x);
	}

	template<CC::Float F>
	consteval void set(F f) {
		*this = fromFloat(f);
	}

	template<CC::Fixed F>
	constexpr void set(F f) {
		*this = fromFixed(f);
	}


	constexpr I raw() const {
		return i;
	}

	constexpr I trunc() const {
		return i >> Shift + isNegative();
	}

	constexpr I whole() const {
		return trunc();
	}

	constexpr I round() const {
		return (i + Half) >> Shift;
	}

	constexpr I fract() const {
		return Bits::mask(i, 0, Shift);
	}

	constexpr FixedPoint floor() const {
		return FixedPoint(whole() << Shift);
	}

	constexpr FixedPoint ceil() const {
		return floor() + One;
	}


	constexpr SplitResult split() const {
		return { trunc(), fract() };
	}

	constexpr bool isNegative() const {
		return i >> (Bits::bitCount<I>() - 1);
	}


	template<CC::Integer J>
	constexpr J toInteger() const {
		return trunc();
	}

	template<CC::Float F>
	constexpr F toFloat() const {
		auto [a, b] = split();
		return F(a) + F(b) / (I(1) << Shift);
	}


	constexpr operator I() const {
		return raw();
	}


	template<CC::Float F>
	static consteval FixedPoint fromFloat(F f) {
		return FixedPoint(One.raw() * f + F(0.5));
	}

	static constexpr FixedPoint fromInteger(I i) {
		return FixedPoint(i << Shift);
	}

	template<CC::Fixed F>
	static constexpr FixedPoint fromFixed(F f) {

		if constexpr (Fract == F::Shift) {
			return FixedPoint(f.i);
		} else if constexpr (Fract > F::Shift) {
			return FixedPoint(I(f.i) << (Fract - F::Shift));
		} else {
			f += typename F::IntegerT(1) << (F::Shift - Fract - 1);
			return FixedPoint(I(f.i) >> (F::Shift - Fract));
		}

	}

	static constexpr FixedPoint fromRaw(I i) {
		return FixedPoint(i);
	}

	static constexpr FixedPoint cast(I i) {
		return fromInteger(i);
	}


	template<CC::Arithmetic A>
	NTR_INLINE constexpr auto operator<=>(A x) const {
		return *this <=> FixedPoint(x);
	}

	template<CC::Fixed F>
	NTR_INLINE constexpr auto operator<=>(F x) const {

		using J = typename F::IntegerT;
		using X = TT::MaxType<I, J>;

		if constexpr (Fract == F::Shift) {

			return i <=> x.i;

		} else if constexpr (Fract > F::Shift && TT::HasBiggerInteger<J>) {

			return i <=> TT::BiggerInteger<J>(x.i) << (Fract - F::Shift);

		} else if constexpr (Fract < F::Shift && TT::HasBiggerInteger<I>) {

			return TT::BiggerInteger<I>(i) << (F::Shift - Fract) <=> x.i;

		} else {

			if (trunc() != x.trunc()) {
				return trunc() <=> x.trunc();
			}

			I a = fract();
			J b = x.fract();

			if constexpr (Fract == F::Shift) {

				return a <=> b;

			} else if constexpr (Fract > F::Shift) {

				return a <=> I(b) << (Fract - F::Shift);

			} else {

				return J(a) << (F::Shift - Fract) <=> b;

			}

		}

	}

private:

	template<CC::SignedInteger J, SizeT F>
		requires (F < Bits::bitCount<J>() && F != 0)
	friend class FixedPoint;

	I i;

};
NTR_SIZE_GUARD(Fx16, sizeof(typename Fx16::IntegerT));
NTR_SIZE_GUARD(Fx32, sizeof(typename Fx32::IntegerT));
NTR_SIZE_GUARD(Fx64, sizeof(typename Fx64::IntegerT));
NTR_SIZE_GUARD(Fx64c, sizeof(typename Fx64c::IntegerT));


template<CC::Fixed F, CC::Integer J>
constexpr F operator+(F a, J b) {
	return a.add(b);
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator+(J a, F b) {
	return b.add(a);
}

template<CC::SignedInteger I, CC::SignedInteger J, SizeT F, SizeT G, class X = FixedPoint<TT::MaxType<I, J>, std::max(F, G)>>
constexpr X operator+(FixedPoint<I, F> a, FixedPoint<J, G> b) {
	return X(a).add(X(b));
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator-(F a, J b) {
	return a.subtract(b);
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator-(J a, F b) {
	return b.negate().add(a);
}

template<CC::SignedInteger I, CC::SignedInteger J, SizeT F, SizeT G, class X = FixedPoint<TT::MaxType<I, J>, std::max(F, G)>>
constexpr X operator-(FixedPoint<I, F> a, FixedPoint<J, G> b) {
	return X(a).subtract(X(b));
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator*(F a, J b) {
	return a.multiply(b);
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator*(J a, F b) {
	return b.multiply(a);
}

template<CC::SignedInteger I, CC::SignedInteger J, SizeT F, SizeT G, class X = FixedPoint<TT::MaxType<I, J>, std::max(F, G)>> requires(F < 32 || G < 32)
constexpr X operator*(FixedPoint<I, F> a, FixedPoint<J, G> b) {
	return X(a).multiply(X(b));
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator/(F a, J b) {
	return a.divide(b);
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator/(J a, F b) {
	return F(a).divide(b);
}

template<CC::SignedInteger I, CC::SignedInteger J, SizeT F, SizeT G, class X = FixedPoint<TT::MaxType<I, J>, std::max(F, G)>> requires(F < 32 || G < 32)
constexpr X operator/(FixedPoint<I, F> a, FixedPoint<J, G> b) {
	return X(a).divide(X(b));
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator%(F a, J b) {
	return a.mod(b);
}

template<CC::Fixed F, CC::Integer J>
constexpr F operator%(J a, F b) {
	return F(a).mod(b);
}

template<CC::SignedInteger I, CC::SignedInteger J, SizeT F, SizeT G, class X = FixedPoint<TT::MaxType<I, J>, std::max(F, G)>> requires(F < 32 || G < 32)
constexpr X operator%(FixedPoint<I, F> a, FixedPoint<J, G> b) {
	return X(a).mod(X(b));
}



template<CC::Fixed F, class U> requires (CC::Integer<U> || CC::Equal<U, F>)
constexpr F operator&(F a, U b) {
	return a.bitAnd(b);
}

template<CC::Fixed F, CC::Integer T>
constexpr F operator&(T a, F b) {
	return b.bitAnd(a);
}

template<CC::Fixed F, class U> requires (CC::Integer<U> || CC::Equal<U, F>)
constexpr F operator|(F a, U b) {
	return a.bitOr(b);
}

template<CC::Fixed F, CC::Integer T>
constexpr F operator|(T a, F b) {
	return b.bitOr(a);
}

template<CC::Fixed F, class U> requires (CC::Integer<U> || CC::Equal<U, F>)
constexpr F operator^(F a, U b) {
	return a.bitXor(b);
}

template<CC::Fixed F, CC::Integer T>
constexpr F operator^(T a, F b) {
	return b.bitXor(a);
}


PP_DIAGNOSTIC_PUSH()
PP_DIAGNOSTIC_IGNORE("-Wliteral-suffix")

consteval Fx16 operator""fxs(long double value)	{
	return Fx16(value);
}

consteval Fx32 operator""fx(long double value) {
	return Fx32(value);
}

consteval Fx64 operator""fxl(long double value)	{
	return Fx64(value);
}

consteval Fx64c operator""fxlc(long double value) {
	return Fx64c(value);
}

PP_DIAGNOSTIC_POP()
