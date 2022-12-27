#pragma once

#include <type_traits>

#include "nitro.h"

// TODO Rewrite the entire thing

#define USE_NITRO_NATIVES 1

extern void __die();

template<typename T>
consteval T __opfx_round(long double value)
{ return value + 0.5L; }

template<typename _FxInt, typename _Int, int _Shift>
class FxType
{
private:
	static_assert(std::is_same<_FxInt, _Int>::value);
	typedef std::make_unsigned<_Int>::type _UInt;

public:
	constexpr static _FxInt one = 1LL << _Shift;
	constexpr static _FxInt half = one / 2;
	constexpr static FxType epsilon = FxType(1);

	constexpr FxType() : m_value(0) {}
	constexpr explicit FxType(_FxInt value) : m_value(value) {}

	constexpr operator _FxInt() const { return m_value; }

	template<typename _RhsFxInt, typename _RhsInt, int _RhsShift>
	constexpr operator FxType<_RhsFxInt, _RhsInt, _RhsShift>()
	{
		s64 shifted = m_value;
		if (_Shift != _RhsShift)
		{
			if (_Shift > _RhsShift)
				shifted >>= _Shift - _RhsShift;
			else
				shifted <<= _RhsShift - _Shift;
		}
		return FxType<_RhsFxInt, _RhsInt, _RhsShift>(static_cast<_RhsInt>(shifted));
	}

	constexpr FxType& operator+(const FxType& rhs)
	{
		m_value += rhs.m_value;
		return *this;
	}

	constexpr FxType& operator-(const FxType& rhs)
	{
		m_value -= rhs.m_value;
		return *this;
	}

	constexpr FxType& operator*(const FxType& rhs)
	{
	#if USE_NITRO_NATIVES
		if (!std::is_constant_evaluated() && _Shift == 12 && std::is_same<_Int, s32>::value)
		{
			m_value = FX_Mul(m_value, rhs.m_value);
			return *this;
		}
	#endif

		m_value = static_cast<_FxInt>(static_cast<s64>(rhs.m_value) * m_value + rhs.half >> _Shift);
		return *this;
	}

	constexpr FxType& operator/(const FxType& rhs)
	{
	#if USE_NITRO_NATIVES
		if (!std::is_constant_evaluated() && _Shift == 12 && std::is_same<_Int, s32>::value)
		{
			m_value = FX_Div(m_value, rhs.m_value);
			return *this;
		}
	#endif

		unsigned int divLShift = (sizeof(s64) - sizeof(_Int)) * 8;
		unsigned int divRShift = divLShift - _Shift;

		s64 numer = static_cast<s64>(static_cast<u64>(m_value) << divLShift);
		_FxInt denom = rhs.m_value;

		s64 divResult = numer / denom;
		divResult += 1 << (divRShift - 1);
		divResult >>= divRShift;

		m_value = divResult;
		return *this;
	}

	constexpr FxType& operator+=(const FxType& rhs) { return (*this = *this + rhs); }
	constexpr FxType& operator-=(const FxType& rhs) { return (*this = *this - rhs); }
	constexpr FxType& operator*=(const FxType& rhs) { return (*this = *this * rhs); }
	constexpr FxType& operator/=(const FxType& rhs) { return (*this = *this / rhs); }

	constexpr FxType operator-() const {

		// non-consteval guard
		/*if (!std::is_constant_evaluated())
			__die();*/

		FxType f;
		f.m_value = -m_value;
		return f;
	}

	constexpr _Int whole() const { return m_value >> _Shift; }
	constexpr _FxInt floor() const { return whole() << _Shift; }
	constexpr _FxInt ceil() const { return floor() + one; }
	constexpr _Int round() const { return (m_value + half) >> _Shift; }

	constexpr static FxType cast(_Int value) { return FxType(value << _Shift); }

private:
	_FxInt m_value;
};

template<typename _FxInt, typename _Int, int _Shift>
class FxProxy
{
private:
	static_assert(std::is_same<_FxInt, _Int>::value);
	typedef std::make_unsigned<_Int>::type _UInt;

public:
	constexpr static _FxInt one = 1LL << _Shift;
	constexpr static _FxInt half = one / 2;
	constexpr static FxProxy epsilon = FxProxy(1);

	constexpr FxProxy() : m_value(0) {}
	constexpr explicit FxProxy(_FxInt value) : m_value(value) {}

	constexpr operator _FxInt() const { return m_value; }

	constexpr operator FxType<_FxInt, _Int, _Shift>() const {
		return FxType<_FxInt, _Int, _Shift>(m_value);
	}

	consteval FxProxy& operator+(const FxProxy& rhs)
	{
		m_value += rhs.m_value;
		return *this;
	}

	consteval FxProxy& operator-(const FxProxy& rhs)
	{
		m_value -= rhs.m_value;
		return *this;
	}

	consteval FxProxy& operator*(const FxProxy& rhs)
	{
		m_value = static_cast<_FxInt>(static_cast<s64>(rhs.m_value) * m_value + rhs.half >> _Shift);
		return *this;
	}

	consteval FxProxy& operator/(const FxProxy& rhs)
	{
		unsigned int divLShift = (sizeof(s64) - sizeof(_Int)) * 8;
		unsigned int divRShift = divLShift - _Shift;

		s64 numer = static_cast<s64>(static_cast<u64>(m_value) << divLShift);
		_FxInt denom = rhs.m_value;

		s64 divResult = numer / denom;
		divResult += 1ULL << (divRShift - 1);
		divResult >>= divRShift;

		m_value = divResult;
		return *this;
	}

	consteval FxProxy& operator+=(const FxProxy& rhs) { return (*this = *this + rhs); }
	consteval FxProxy& operator-=(const FxProxy& rhs) { return (*this = *this - rhs); }
	consteval FxProxy& operator*=(const FxProxy& rhs) { return (*this = *this * rhs); }
	consteval FxProxy& operator/=(const FxProxy& rhs) { return (*this = *this / rhs); }

	consteval FxProxy operator-() const { return FxProxy(-m_value); }

	consteval _Int whole() const { return m_value >> _Shift; }
	consteval _FxInt floor() const { return whole() << _Shift; }
	consteval _FxInt ceil() const { return floor() + one; }
	consteval _Int round() const { return (m_value + half) >> _Shift; }

	consteval static FxProxy cast(_Int value) { return FxProxy(value << _Shift); }

private:
	_FxInt m_value;
};

typedef FxType<fx16, s16, 12> Fx16;
typedef FxType<fx32, s32, 12> Fx32;
typedef FxType<fx64, s64, 12> Fx64;
typedef FxType<fx64, s64, 32> Fx64c;

namespace Fx
{
	constexpr static Fx64c ldiv(Fx32 a, Fx32 b)
	{
	#if USE_NITRO_NATIVES
		if (!std::is_constant_evaluated())
			return Fx64c(FX_DivFx64c(a, b));
		else
	#endif
		return Fx64c((static_cast<fx64>(a) << 32) / static_cast<fx32>(b));
	}
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wliteral-suffix"

consteval auto operator""fxs(long double value)		{ return FxType<fx16, s16, 12>(__opfx_round<fx16>(value * 0x1000)); }
consteval auto operator""fx(long double value)		{ return FxType<fx32, s32, 12>(__opfx_round<fx32>(value * 0x1000)); }
consteval auto operator""fxl(long double value)		{ return FxType<fx64, s64, 12>(__opfx_round<fx64>(value * 0x1000)); }
consteval auto operator""fxlc(long double value)	{ return FxType<fx64, s64, 32>(__opfx_round<fx64>(value * 0x100000000)); }

#pragma GCC diagnostic pop

#undef FX_CONSTEXPR_OP
