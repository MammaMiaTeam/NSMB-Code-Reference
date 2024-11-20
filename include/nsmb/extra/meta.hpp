#pragma once

#include <nsmb_nitro.hpp>

#include <concepts>
#include <type_traits>


namespace CC {

	template<class A, class B>
	concept Equal = std::same_as<A, B>;

	template<class T>
	concept Integral = std::integral<T>;

	template<class T>
	concept SignedIntegral = std::signed_integral<T>;

	template<class T>
	concept UnsignedIntegral = std::unsigned_integral<T>;

	template<class T>
	concept Integer = !Equal<T, bool> && Integral<T>;

	template<class T>
	concept SignedInteger = !Equal<T, bool> && SignedIntegral<T>;

	template<class T>
	concept UnsignedInteger = !Equal<T, bool> && UnsignedIntegral<T>;

	template<class T>
	concept Float = std::floating_point<T>;

	template<class T>
	concept Arithmetic = Integral<T> || Float<T>;

	template<class T>
	concept Pointer = std::is_pointer_v<T>;

}

namespace TT {

	template<bool C, class A, class B>
	using Conditional = std::conditional_t<C, A, B>;

	template<class A, class B>
	using MaxType = Conditional<sizeof(A) >= sizeof(B), A, B>;

	template<class A, class B>
	using MinType = Conditional<sizeof(A) <= sizeof(B), A, B>;

	template<CC::Integer T>
	using MakeUnsigned = std::make_unsigned_t<T>;

	template<CC::Integer T>
	using MakeSigned = std::make_signed_t<T>;

	namespace Detail {

		template<CC::Integer T, bool Clamp>
		struct BiggerInteger {};

		template<bool C> struct BiggerInteger<u8, C>	{ using Type = u16; };
		template<bool C> struct BiggerInteger<u16, C>	{ using Type = u32; };
		template<bool C> struct BiggerInteger<u32, C>	{ using Type = u64; };
		template<> struct BiggerInteger<u64, true>		{ using Type = u64; };

		template<bool C> struct BiggerInteger<s8, C>	{ using Type = s16; };
		template<bool C> struct BiggerInteger<s16, C>	{ using Type = s32; };
		template<bool C> struct BiggerInteger<s32, C>	{ using Type = s64; };
		template<> struct BiggerInteger<s64, true>		{ using Type = s64; };

		template<CC::Integer T, bool Clamp>
		struct SmallerInteger {};

		template<>	struct SmallerInteger<u8, true>		{ using Type = u8; };
		template<bool C> struct SmallerInteger<u16, C>	{ using Type = u8; };
		template<bool C> struct SmallerInteger<u32, C>	{ using Type = u16; };
		template<bool C> struct SmallerInteger<u64, C>	{ using Type = u32; };

		template<>	struct SmallerInteger<s8, true>		{ using Type = s8; };
		template<bool C> struct SmallerInteger<s16, C>	{ using Type = s8; };
		template<bool C> struct SmallerInteger<s32, C>	{ using Type = s16; };
		template<bool C> struct SmallerInteger<s64, C>	{ using Type = s32; };

		template<class T>
		concept HasBiggerInteger = requires { BiggerInteger<T, false>::Type; };

		template<class T>
		concept HasSmallerInteger = requires { SmallerInteger<T, false>::Type; };

	}

	template<CC::Integer T>
	using BiggerIntegerClamp = typename Detail::BiggerInteger<T, true>::Type;

	template<CC::Integer T>
	using BiggerInteger = typename Detail::BiggerInteger<T, false>::Type;

	template<CC::Integer T>
	using SmallerIntegerClamp = typename Detail::SmallerInteger<T, true>::Type;

	template<CC::Integer T>
	using SmallerInteger = typename Detail::SmallerInteger<T, false>::Type;

	template<CC::Integer T>
	static constexpr bool HasBiggerInteger = Detail::HasBiggerInteger<T>;

	template<CC::Integer T>
	static constexpr bool HasSmallerInteger = Detail::HasSmallerInteger<T>;

}
