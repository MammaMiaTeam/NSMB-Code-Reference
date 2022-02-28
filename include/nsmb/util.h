#pragma once
#include "nitro_if.h"


template<bool Value>
struct BoolConstant
{
	static constexpr inline bool value = Value;
};



template<class A, class B>
struct IsSame : BoolConstant<false> {};

template<class T>
struct IsSame<T, T> : BoolConstant<true> {};



template<class T>
struct IsInteger : BoolConstant<false> {};

template<> struct IsInteger<char>				: BoolConstant<true> {};
template<> struct IsInteger<wchar_t>			: BoolConstant<true> {};
template<> struct IsInteger<signed char>		: BoolConstant<true> {};
template<> struct IsInteger<unsigned char>		: BoolConstant<true> {};
template<> struct IsInteger<signed short>		: BoolConstant<true> {};
template<> struct IsInteger<unsigned short>		: BoolConstant<true> {};
template<> struct IsInteger<signed int>			: BoolConstant<true> {};
template<> struct IsInteger<unsigned int>		: BoolConstant<true> {};
template<> struct IsInteger<signed long>		: BoolConstant<true> {};
template<> struct IsInteger<unsigned long>		: BoolConstant<true> {};
template<> struct IsInteger<signed long long>	: BoolConstant<true> {};
template<> struct IsInteger<unsigned long long>	: BoolConstant<true> {};



template<class T>
struct IsFloat : BoolConstant<false> {};

template<> struct IsFloat<float>		: BoolConstant<true> {};
template<> struct IsFloat<double>		: BoolConstant<true> {};
template<> struct IsFloat<long double>	: BoolConstant<true> {};



template<class T>
concept Integer = IsInteger<T>::value;


template<class T>
concept Float = IsFloat<T>::value;


template<class T>
concept Arithmetic = Integer<T> || Float<T>;



#define __IMPL_ENUMCLASS_OPERATORS(type, rhs_type, cast_type) \
constexpr type operator ~ (type const& rhs) noexcept { return static_cast<type>(~static_cast<cast_type>(rhs)); } \
constexpr type  operator   | (type const& lhs, rhs_type const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); } \
constexpr type  operator   & (type const& lhs, rhs_type const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); } \
constexpr type  operator   ^ (type const& lhs, rhs_type const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); } \
constexpr type  operator  << (type const& lhs, rhs_type const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); } \
constexpr type  operator  >> (type const& lhs, rhs_type const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); } \
constexpr type& operator  |= (type& lhs, rhs_type const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); return lhs; } \
constexpr type& operator  &= (type& lhs, rhs_type const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); return lhs; } \
constexpr type& operator  ^= (type& lhs, rhs_type const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); return lhs; } \
constexpr type& operator <<= (type& lhs, rhs_type const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); return lhs; } \
constexpr type& operator >>= (type& lhs, rhs_type const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr type  operator   | (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr type  operator   & (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr type  operator   ^ (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr type  operator  << (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr type  operator  >> (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr type& operator  |= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr type& operator  &= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr type& operator  ^= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr type& operator <<= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr type& operator >>= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr T  operator   | (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr T  operator   & (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr T  operator   ^ (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr T  operator  << (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr T  operator  >> (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); } \
template<Integer T> constexpr T& operator  |= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr T& operator  &= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr T& operator  ^= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr T& operator <<= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); return lhs; } \
template<Integer T> constexpr T& operator >>= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); return lhs; }


// Lets us use bitwise operators with enum class types
#define IMPL_ENUMCLASS_OPERATORS(type) __IMPL_ENUMCLASS_OPERATORS(type, type, u32)


#define get_over_asm(_1,_2,_3,NAME,...) NAME
#define over_asm(...) get_over_asm(__VA_ARGS__, over_asm3, over_asm2)(__VA_ARGS__)
#define over_asm2(addr, asm) over(addr) asm_func void over_##addr() { __asm__(asm); }
#define over_asm3(addr, ov, asm) over(addr, ov) asm_func void over_##addr##_ov##ov() { __asm__(asm); }


extern "C"
{
	/*
		Misc memory transfer functions
	*/
	void* memchr(void* ptr, u8 value, u32 num);
	s32 memcmp(const void* ptr1, const void* ptr2, u32 num);
	void memcpy(void* destination, const void* source, u32 num);
	void memmove(void* destination, const void* source, u32 num);
	void memset(void* ptr, u8 value, u32 num);

	int strlen(const char* __s);

}
