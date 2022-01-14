#pragma once

// Set to 1 when generating symbols
#define GEN_SYM 0

#define __ret return {};

#if GEN_SYM
#define sym __attribute__((noinline, used))
#define ssym __attribute__((noinline, used)) static
#define GEN_FUNC(x, ...) sym x (__VA_ARGS__) {}
#define GEN_SFUNC(x, ...) sym static x (__VA_ARGS__) {}
#define __body {}
#define __rbody { __ret }
#else
#define sym
#define ssym
#define GEN_FUNC(x, ...) x (__VA_ARGS__) ;
#define GEN_SFUNC(x, ...) x (__VA_ARGS__) ;
#define __body ;
#define __rbody ;
#endif

#define USED	__attribute__((used))
#define NIN		__attribute__((noinline))
#define FIN		__attribute__((always_inline)) inline

#ifdef _MSC_VER // VSCode doesn't need it
#include "intellisense.h"
#else
#define __inline	FIN
#define if_consteval if (std::is_constant_evaluated())
#define __weak		__attribute__((weak))
#endif


// Set to 1 when compiling in Debug mode
#define NTR_DEBUG 1


typedef void* NITRO_TYPE_REPLACEMENT;

#ifdef NITRO_NO_SDK

	#warning("Project built without Nitro-SDK/NNS, replacing interface")

	typedef NITRO_TYPE_REPLACEMENT NNSFndHeapHandle;
	typedef NITRO_TYPE_REPLACEMENT OSMutex;
	typedef NITRO_TYPE_REPLACEMENT OSArenaId;
	typedef NITRO_TYPE_REPLACEMENT NNSFndList;
	typedef NITRO_TYPE_REPLACEMENT NNSG2dFont;
	typedef NITRO_TYPE_REPLACEMENT NNSG2dGlyph;
	typedef NITRO_TYPE_REPLACEMENT NNSSndHandle;
	typedef NITRO_TYPE_REPLACEMENT NNSSndSeqPlayer;

	enum NNSSndCaptureOutputEffectType {

		NNS_SND_CAPTURE_OUTPUT_EFFECT_NORMAL = 0x0,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_SURROUND = 0x1,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_HEADPHONE = 0x2,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_MONO = 0x3

	};

	void MI_CpuFillFast(const void*, int, int);
	void MI_CpuCopyFast(const void*, void*, int);
	void MI_CpuFill8(const void*, int, int);
	void MI_CpuCopy8(const void*, void*, int);

	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned int u32;
	typedef unsigned long long int u64;

	typedef signed char s8;
	typedef signed short s16;
	typedef signed int s32;
	typedef signed long long int s64;

	typedef s16 fx16;
	typedef s32 fx32;
	typedef s64 fx64;
	typedef s64 fx64c;

	struct VecFx32 {
		fx32 x, y, z;
	};

	struct VecFx16 {
		fx16 x, y, z;
	};

	fx32 FX_Div(fx32, fx32);
	fx32 FX_MulInline(fx32, fx32);

#else

#	ifndef SDK_TS
#	define SDK_TS
#	endif

#	ifndef SDK_CODE_ARM
#	define SDK_CODE_ARM
#	endif

#	include "nitro.h"
#	include "nnsys.h"

#endif

#include "extra/ostream.hpp"

#define __ntr_message(s)	do { log::cout << s; } while (false)
#define __ntr_terminate()	OS_Terminate()

#include "assert.h"
