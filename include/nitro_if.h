#pragma once


// Set to 1 when generating symbols
#define NTR_GEN_SYM 0

// Set to 1 when compiling in Debug mode
#define NTR_DEBUG 1


#if NTR_GEN_SYM
#define sym [[gnu::noinline, gnu::used]]
#define ssym sym static
#define __body {}
#define __rbody { return {}; }
#else
#define sym
#define ssym
#define __body ;
#define __rbody ;
#endif


#define rcast reinterpret_cast
#define scast static_cast
#define ccast const_cast
#define dcast dynamic_cast


#ifdef __INTELLISENSE__
	#ifdef _MSC_VER
		#define IDE_VS
	#else
		#define IDE_VSCODE
	#endif
#elif defined(__CLION_IDE__)
	#define IDE_CLION
#else
	#define IDE_UNKNOWN
#endif


#define NTR_OFFSETOF(s, m)		((::size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#define NTR_SIZE_GUARD(t, s)	static_assert(sizeof(t) == (s), "Size of '" #t "' does not match expected value '" #s "'")
#define NTR_ARRAY_SIZE(a)		((::size_t)(sizeof(a) / sizeof(a[0])))

#ifdef __INTELLISENSE__
	#define NTR_REGISTER(r, d)	register d
#else
	#define NTR_REGISTER(r, d)	register d asm(#r)
#endif


#define NTR_NOINLINE			[[gnu::noinline]]
#define NTR_INLINE				[[gnu::always_inline]] inline
#define NTR_WEAK				[[gnu::weak]]
#define NTR_NAKED				[[gnu::naked]]
#define NTR_USED				[[gnu::used]]
#define NTR_LONGCALL			[[gnu::long_call]]
#define NTR_TARGET(t)			[[gnu::target(#t)]]
#define NTR_THUMB				NTR_TARGET(thumb)
#define NTR_ARM					NTR_TARGET(arm)
#define NTR_WARNING(s)			[[gnu::warning(#s)]]
#define NTR_ERROR(s)			[[gnu::error(#s)]]

#define NTR_PRAGMA(p)			_Pragma(#p)

#define GCC_DIAGNOSTIC(x)		NTR_PRAGMA(GCC diagnostic x)
#define GCC_PUSH				GCC_DIAGNOSTIC(push)
#define GCC_POP					GCC_DIAGNOSTIC(pop)
#define GCC_IGNORE(x)			GCC_DIAGNOSTIC(ignored x)
#define GCC_ERROR(x)			GCC_DIAGNOSTIC(error x)
#define GCC_WARNING(x)			GCC_DIAGNOSTIC(warning x)


#ifdef IDE_VS
	#include "intellisense.h"
#else
	#define if_consteval if (std::is_constant_evaluated())
#endif


#ifndef SDK_TS
#define SDK_TS
#endif

#ifndef SDK_CODE_ARM
#define SDK_CODE_ARM
#endif

#include "nitro.h"
#include "nnsys.h"


template<auto>
[[gnu::warning("SoftLog")]] constexpr void SoftLog() {}

template<auto>
[[gnu::error("HardLog")]] constexpr void HardLog() {}


#ifdef __INTELLISENSE__
	#define NTR_SOFTLOG(v) do {} while (false)
	#define NTR_HARDLOG(v) do {} while (false)
#else
	#define NTR_SOFTLOG(v) do { SoftLog<(v)>() } while (false)
	#define NTR_HARDLOG(v) do { HardLog<(v)>() } while (false)
#endif


NTR_LONGCALL NTR_THUMB void MTX_RotX33(MtxFx33& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotY33(MtxFx33& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotZ33(MtxFx33& mtx, fx16 sine, fx16 cosine);

NTR_LONGCALL NTR_THUMB void MTX_Scale43(MtxFx43& mtx, fx32 x, fx32 y, fx32 z);
NTR_LONGCALL NTR_THUMB void MTX_RotX43(MtxFx43& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotY43(MtxFx43& mtx, fx16 sine, fx16 cosine);
NTR_LONGCALL NTR_THUMB void MTX_RotZ43(MtxFx43& mtx, fx16 sine, fx16 cosine);


using bool16 = u16;
using bool32 = u32;

template<class T>
struct BitFlag {

	NTR_INLINE T& raw() {
		return *reinterpret_cast<T*>(this);
	}

	NTR_INLINE T raw() const {
		return *reinterpret_cast<const T*>(this);
	}

	NTR_INLINE operator T& () {
		return raw();
	}

	NTR_INLINE operator T () const {
		return raw();
	}

};

inline int OS_SNPrintf(char* dst, size_t len, const char* fmt, ...) {

	va_list vl;
	va_start(vl, fmt);

	return OS_VSNPrintf(dst, len, fmt, vl);

}
