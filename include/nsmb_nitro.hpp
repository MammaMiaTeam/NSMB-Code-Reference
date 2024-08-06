#pragma once

// Safety checks
// In reality they only get caught if this header is included somewhere, but it should cover most of the cases

#if !__has_include("nitro.h")
	#error "Nitro SDK 3.0 is missing in the 'include' folder"
#endif

#if !__has_include("nnsys.h")
	#error "Nintendo Nitro System 3.0 is missing in the 'include' folder"
#endif

#ifdef NITRO_H_
	#error "Nitro SDK included from original header (only use nsmb_nitro.hpp)"
#endif

#ifdef NNSYS_H_
	#error "Nintendo Nitro System included from original header (only use nsmb_nitro.hpp)"
#endif


#ifndef SDK_TS
	#define SDK_TS
#endif

#ifndef SDK_CODE_ARM
	#define SDK_CODE_ARM
#endif

#include "nitro.h" // Nitro SDK 3.0
#include "nnsys.h" // Nintendo Nitro System 3.0


#define rcast reinterpret_cast
#define scast static_cast
#define ccast const_cast
#define dcast dynamic_cast


#define NTR_OFFSETOF(s, m)		((::size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#define NTR_ARRAY_SIZE(a)		((::size_t)(sizeof(a) / sizeof(a[0])))
#define NTR_BREAK()				asm("bkpt #0")

#ifdef __INTELLISENSE__
	#define NTR_SIZE_GUARD(t, s)	static_assert(true, "")
	#define NTR_REGISTER(type, name, reg)	register __typeof__(type) name
#else
	#define NTR_SIZE_GUARD(t, s)	static_assert(sizeof(t) == (s), "Size of '" #t "' does not match expected value '" #s "'")
	#define NTR_REGISTER(type, name, reg)	register __typeof__(type) name asm(#reg)
#endif


#define NTR_NOINLINE			[[gnu::noinline]]
#define NTR_INLINE				[[gnu::always_inline]] inline
#define NTR_WEAK				[[gnu::weak]]
#define NTR_NAKED				[[gnu::naked]]
#define NTR_USED				[[gnu::used]]
#define NTR_LONGCALL			[[gnu::long_call]]
#define NTR_THUMB				[[gnu::target("thumb")]]
#define NTR_ARM					[[gnu::target("arm")]]
#define NTR_WARNING(msg)		[[gnu::warning(msg)]]
#define NTR_ERROR(msg)			[[gnu::error(msg)]]
#define NTR_ALIAS(sym)			[[gnu::alias(sym)]]
#define NTR_WEAKREF(sym)		[[gnu::weakref(sym)]]
#define NTR_COPY(sym)			[[gnu::copy(sym)]]
#define NTR_FORMAT(fun, a, b)	[[gnu::format(func, a, b)]]
#define NTR_FALLTHROUGH			[[fallthrough]]
#define NTR_NORETURN			[[noreturn]]
#define NTR_NODISC				[[nodiscard]]


using bool16 = u16;
using bool32 = u32;
using SizeT = size_t;
using AddressT = u32;


NTR_LONGCALL NTR_THUMB void MTX_RotX33(MtxFx33& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotY33(MtxFx33& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotZ33(MtxFx33& mtx, fx16 sine, fx16 cosine);

NTR_LONGCALL NTR_THUMB void MTX_Scale43(MtxFx43& mtx, fx32 x, fx32 y, fx32 z);
NTR_LONGCALL NTR_THUMB void MTX_RotX43(MtxFx43& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotY43(MtxFx43& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotZ43(MtxFx43& mtx, fx16 sine, fx16 cosine);

// Standard C++ attributes do not allow overriding already existing functions
__attribute__((noreturn)) extern void OS_Terminate();

NTR_FORMAT(printf, 2, 3) int OS_SPrintf(char *dst, const char *fmt, ...);

NTR_FORMAT(printf, 2, 3) NTR_INLINE int OS_SNPrintf(char* dst, size_t len, const char* fmt, ...) {

	va_list vl;
	va_start(vl, fmt);

	return OS_VSNPrintf(dst, len, fmt, vl);

}
