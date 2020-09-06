#ifndef NSMB_UTIL_INCLUDED
#define NSMB_UTIL_INCLUDED

#include "nitro_if.h"

#define NOINLINE	__attribute__((noinline)) static
#define FORCEINLINE __attribute__((always_inline)) static inline


// Allows all enum classes to be used as bitfields
template<typename E>
E operator|(E lhs, E rhs) {
	return static_cast<E>(static_cast<int>(lhs) | static_cast<int>(rhs));
}
template<typename E>
E operator&(E lhs, E rhs) {
	return static_cast<E>(static_cast<int>(lhs) & static_cast<int>(rhs));
}


FORCEINLINE constexpr bool is_aligned(u32 x) {
	return !(x % 4);
}



NOINLINE void* memchr(void* ptr, u8 value, u32 num) {

	u8* p = reinterpret_cast<u8*>(ptr);

	while (num-- > 0) {

		if (*p == value) {
			return p;
		}

		p++;

	}

	return nullptr;

}

NOINLINE s32 memcmp(const void* ptr1, const void* ptr2, u32 num) {

	const u8* p1 = reinterpret_cast<const u8*>(ptr1);
	const u8* p2 = reinterpret_cast<const u8*>(ptr2);

	while (num-- > 0) {

		if (*p1 != *p2) {
			return (*p1 < *p2 ? -1 : 1);
		}

		p1++;
		p2++;

	}

	return 0;

}

FORCEINLINE void memcpy(void* destination, const void* source, u32 num) {

	if (is_aligned(num)) {

		MI_CpuCopyFast(source, destination, num);

	} else {

		u32 alignedBytes = num & ~3;
		MI_CpuCopyFast(source, destination, alignedBytes);
		MI_CpuCopy8(reinterpret_cast<const void*>(reinterpret_cast<const u8*>(source) + alignedBytes), reinterpret_cast<void*>(reinterpret_cast<u8*>(destination) + alignedBytes), num & 3);

	}

}

FORCEINLINE void memmove(void* destination, const void* source, u32 num) {

	if (is_aligned(num)) {

		MI_CpuCopyFast(source, destination, num);

	} else {

		u32 alignedBytes = num & ~3;
		MI_CpuCopyFast(source, destination, alignedBytes);
		MI_CpuCopy8(reinterpret_cast<const void*>(reinterpret_cast<const u8*>(source) + alignedBytes), reinterpret_cast<void*>(reinterpret_cast<u8*>(destination) + alignedBytes), num & 3);

	}

}

FORCEINLINE void memset(void* ptr, u8 value, u32 num) {

	if (is_aligned(num)) {

		MI_CpuFillFast(ptr, value << 24 | value << 16 | value << 8 | value, num);

	} else {

		MI_CpuFillFast(ptr, value << 24 | value << 16 | value << 8 | value, num & ~3);
		MI_CpuFill8(reinterpret_cast<void*>(reinterpret_cast<u8*>(ptr) + (num & ~3)), value, num & 3);

	}

}

#endif	// NSMB_UTIL_INCLUDED
