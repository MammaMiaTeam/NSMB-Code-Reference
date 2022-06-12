#pragma once

#include "nitro_if.h"


namespace End::Graphics {

	struct alignas(4) CacheEntry {
		u32 address;
		void* data;
		u32 size;
		bool palette;
	};
	NTR_SIZE_GUARD(CacheEntry, 0x10);


	// 020E2A50
	u32 getResourceIndex(NNSG3dResMdl* mdl, const char* name);
	// 020E2AA4
	u32 getResourceIndex(NNSG3dResDict* dict, const char* name);

	// 020E2A68
	u32 getPaletteAddress(NNSG3dResMatData* mat);
	// 020E2A8C
	u32 getTextureAddress(NNSG3dResMatData* mat);

	// 020E2AE0
	void loadTexPltt(void* src, u32 dest, u32 size);
	// 020E2B14
	void loadTex(void* src, u32 dest, u32 size);

	// 020E2B48
	bool cacheData(void* data, u32 addr, u32 size, bool palette);
	// 020E2BA0
	bool cacheModelTexture(NNSG3dResMdl* model, const char* name, void* tex, u32 texSize, void* pal, u32 palSize, u32 texOfs, u32 palOfs);

	// 020E2C70
	bool hasCachedData();
	// 020E2D0C
	void clearCache();
	// 020E2D20
	void initCache();

	// 020E2C8C
	void endingVBlankHandler();

	// 020F1648
	extern u32 cacheIndex;
	// 020F164C
	extern CacheEntry cache[10];

}
