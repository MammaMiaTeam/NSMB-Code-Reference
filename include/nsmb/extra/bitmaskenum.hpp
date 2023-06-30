#pragma once

#include "meta.hpp"


#define NTR_CREATE_BITMASK_ENUM_EX(type, rhs_type, cast_type) \
constexpr type  operator   ~ (type const& rhs) noexcept { return static_cast<type>(~static_cast<cast_type>(rhs)); } \
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
template<CC::Integer T> constexpr type  operator   | (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr type  operator   & (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr type  operator   ^ (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr type  operator  << (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr type  operator  >> (type const& lhs, T const& rhs) noexcept { return static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr type& operator  |= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr type& operator  &= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr type& operator  ^= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr type& operator <<= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr type& operator >>= (type& lhs, T const& rhs) noexcept { lhs = static_cast<type>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr T  operator   | (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr T  operator   & (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr T  operator   ^ (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr T  operator  << (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr T  operator  >> (T const& lhs, type const& rhs) noexcept { return static_cast<T>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); } \
template<CC::Integer T> constexpr T& operator  |= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) | static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr T& operator  &= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) & static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr T& operator  ^= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) ^ static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr T& operator <<= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) << static_cast<cast_type>(rhs)); return lhs; } \
template<CC::Integer T> constexpr T& operator >>= (T& lhs, type const& rhs) noexcept { lhs = static_cast<T>(static_cast<cast_type>(lhs) >> static_cast<cast_type>(rhs)); return lhs; }

#define NTR_CREATE_BITMASK_ENUM(type) NTR_CREATE_BITMASK_ENUM_EX(type, type, u32)
