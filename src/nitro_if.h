#ifndef NITRO_IF_H
#define NITRO_IF_H

typedef void* NITRO_TYPE_REPLACEMENT;

#ifdef NITRO_NO_SDK

	#warning("Project built without Nitro-SDK/NNS, replacing interface")

	typedef NITRO_TYPE_REPLACEMENT NNSFndHeapHandle;
	typedef NITRO_TYPE_REPLACEMENT OSMutex;
	typedef NITRO_TYPE_REPLACEMENT OSArenaID;
	typedef NITRO_TYPE_REPLACEMENT NNSFndList;
	typedef NITRO_TYPE_REPLACEMENT NNSG2dFont;
	typedef NITRO_TYPE_REPLACEMENT NNSG2dGlyph;
	typedef NITRO_TYPE_REPLACEMENT NNSSndHandle;
	typedef NITRO_TYPE_REPLACEMENT NNSSndSeqPlayer;

	enum NNSSndCaptureOutputEffectType
	{
		NNS_SND_CAPTURE_OUTPUT_EFFECT_NORMAL = 0x0,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_SURROUND = 0x1,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_HEADPHONE = 0x2,
		NNS_SND_CAPTURE_OUTPUT_EFFECT_MONO = 0x3,
	};

	typedef unsigned char u8;
	typedef unsigned short u16;
	typedef unsigned int u32;
	typedef unsigned long long int u64;

	typedef signed char s8;
	typedef signed short s16;
	typedef signed int s32;
	typedef signed long long int s64;

#else
	#include "nitro.h"
	#include "nnsys.h"
#endif

#endif	// NITRO_IF_H
