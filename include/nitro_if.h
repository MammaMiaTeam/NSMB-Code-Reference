#ifndef NITRO_IF_H
#define NITRO_IF_H

#ifdef NITRO_NO_SDK

	#warning("Project built without Nitro-SDK/NNS, replacing interface")

	typedef void* NNSFndHeapHandle;
	typedef void* OSMutex;
	typedef void* OSArenaId;
	typedef void* NNSFndList;
	typedef void* NNSG2dFont;
	typedef void* NNSG2dGlyph;
	typedef void* NNSSndHandle;
	typedef void* NNSSndSeqPlayer;

	enum NNSSndCaptureOutputEffectType {
		
		NNS_SND_CAPTURE_OUTPUT_EFFECT_NORMAL = 0x0,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_SURROUND = 0x1,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_HEADPHONE = 0x2,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_MONO = 0x3
		
	};

	void MI_CpuFillFast(void* dest, u32 data, u32 size);
	void MI_CpuCopyFast(const void* src, void* dest, u32 size);
	void MI_CpuFill8(void* dest, u8 data, u32 size);
	void MI_CpuCopy8(const void* src, void* dest, u32 size);
	
	typedef unsigned char u8;
	typedef unsigned short int u16;
	typedef unsigned long u32;
	typedef unsigned long long int u64;

	typedef signed char s8;
	typedef signed short int s16;
	typedef signed long s32;
	typedef signed long long int s64;

	typedef s16 fx16;
	typedef s32 fx32;
	typedef s64 fx64;
	typedef s64 fx64c;

	struct VecFx32 { fx32 x, y, z; };
	struct VecFx16 { fx16 x, y, z; };

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
