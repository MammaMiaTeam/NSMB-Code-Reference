#ifndef NITRO_IF_H
#define NITRO_IF_H

typedef void* NITRO_TYPE_REPLACEMENT;

#ifdef NO_NITRO_SDK

	#warning("Project built without Nitro-SDK/NNS, replacing interface")

	typedef NITRO_TYPE_REPLACEMENT NNSFndHeapHandle;
	typedef NITRO_TYPE_REPLACEMENT OSMutex;
	typedef NITRO_TYPE_REPLACEMENT OSArenaID;
	typedef NITRO_TYPE_REPLACEMENT NNSFndList;

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
#endif

#endif	// NITRO_IF_H