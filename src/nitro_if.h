#ifndef NITRO_IF_H
#define NITRO_IF_H

typedef void* NITRO_TYPE_REPLACEMENT;
typedef void* NSMB_TYPE_REPLACEMENT;

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
	#include "nitro.h"
	#include "nnsys.h"
#endif

// nsmb prototypes

class EnemyActor;
class Actor;

#define USED	__attribute__((used))
#define NIN		__attribute__((noinline))
#define FIN		__attribute__((always_inline)) inline

#endif	// NITRO_IF_H
