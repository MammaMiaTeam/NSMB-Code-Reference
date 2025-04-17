#pragma once

#include "meta.hpp"

#include <bit>
#include <utility>


template<class T>
struct alignas(alignof(T)) BitFlag {

	NTR_INLINE T& raw() {
		return *rcast<T*>(this);
	}

	NTR_INLINE T raw() const {
		return *rcast<const T*>(this);
	}

	NTR_INLINE operator T&() {
		return raw();
	}

	NTR_INLINE operator T() const {
		return raw();
	}

};

template<class T>
struct StrongBitFlag : BitFlag<T> {

	using BitFlag<T>::raw;
	using BitFlag<T>::operator T&;
	using BitFlag<T>::operator T;

	NTR_INLINE StrongBitFlag() = default;

	NTR_INLINE StrongBitFlag(const T& data) {
		BitFlag<T>::raw() = data;
	}

};


namespace Bits {

	template<class Dest, class Src>
	constexpr Dest cast(const Src& src) {
		return std::bit_cast<Dest>(src);
	}

	template<class T>
	constexpr SizeT bitCount() {
		return sizeof(T) * 8;
	}

	template<CC::Integer T>
	constexpr T mask(T t, u32 start, u32 count) {
		return t & ((count < bitCount<T>() ? (cast<TT::MakeUnsigned<T>>(T(1)) << count) - 1 : ~T(0)) << start);
	}

	template<CC::Integer I>
	constexpr I allOnes() noexcept {
		return I(-1);
	}

	template<CC::Integer I>
	constexpr I ones(SizeT n) noexcept {
		return n >= bitCount<I>() ? allOnes<I>() : (static_cast<TT::MakeUnsigned<I>>(1) << n) - 1;
	}

	template<CC::IntegralOrEnum I>
	constexpr auto bitmask(I a) {
		using L = TT::Conditional<CC::Integral<I>, I, TT::UnderlyingType<I>>;
		return 1U << scast<L>(a);
	}

	template<CC::IntegralOrEnum I, CC::IntegralOrEnum... Args>
	constexpr auto bitmask(I a, Args&&... args) {
		using L = TT::Conditional<CC::Integral<I>, I, TT::UnderlyingType<I>>;
		return (1U << scast<L>(a)) | bitmask(std::forward<Args>(args)...);
	}

}
