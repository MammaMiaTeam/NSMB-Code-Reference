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


#define NTR_OFFSETOF(s, m)		((::size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#define NTR_SIZE_GUARD(t, s)	static_assert(sizeof(t) == (s), "Size of '" #t "' does not match expected value '" #s "'")
#define NTR_ARRAY_SIZE(a)		(sizeof(a) / sizeof(a[0]))

#define NTR_NOINLINE			[[gnu::noinline]]
#define NTR_INLINE				[[gnu::always_inline]] inline
#define NTR_WEAK				[[gnu::weak]]

#define NTR_PRAGMA(p)			_Pragma(#p)

#define GCC_DIAGNOSTIC(x)		NTR_PRAGMA(GCC diagnostic x)
#define GCC_PUSH				GCC_DIAGNOSTIC(push)
#define GCC_POP					GCC_DIAGNOSTIC(pop)
#define GCC_IGNORE(x)			GCC_DIAGNOSTIC(ignored x)
#define GCC_ERROR(x)			GCC_DIAGNOSTIC(error x)
#define GCC_WARNING(x)			GCC_DIAGNOSTIC(warning x)


#ifdef _MSC_VER
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
