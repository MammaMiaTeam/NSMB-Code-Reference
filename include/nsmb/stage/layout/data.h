#pragma once
#include "nsmb.h"
#include "assert.h"


enum class StageBlockID : u32 {
	Header,
	Camera,
	Background,
	Tileset,
	Foreground,
	Entrances,
	Sprites,
	Views,
	Zones,
	ProgressPaths,
	Paths,
	PathNodes,
	ProgressPathNodes,
	SpriteBanks,

	Max
};


struct StageBlocks {

	void* header;
	void* camera;
	void* background;
	void* tileset;
	void* foreground;
	void* entrances;
	void* sprites;
	void* views;
	void* zones;
	void* progressPaths;
	void* paths;
	void* pathNodes;
	void* progressPathNodes;
	void* spriteBanks;

	__inline void* operator[] (u32 blockID) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		return static_cast<void**>(&header) + blockID;
	}

};


namespace Stage
{

	// DATA
	
	// 0203C8C8
	extern u32 stageBlockUnitSize[14];

	// BSS

	// 0208B0F8
	extern u32 stageBlocksSize[14];

	// 0208B130
	extern u32 stageBlocksElements[14];

	// 0208B168
	extern StageBlocks stageBlocks;



	constexpr u32 getBlockUnitSize(u32 blockID) {
		// this is dumb af
		// ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		if_consteval {
			constexpr u32 sizes[] = { 0x20, 0x18, 0x14, 0x14, 0x14, 0x14, 0x0C, 0x10, 0x0C, 0x08, 0x08, 0x10, 0x10, 0x10 };
			return sizes[blockID];
		}
		else {
			ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
			return stageBlockUnitSize[blockID];
		}
	}

	__inline u32 getBlockSize(u32 blockID) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		return stageBlocksSize[blockID];
	}

	__inline u32 getBlockElementCount(u32 blockID) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		return stageBlocksElements[blockID];
	}

	template<class T>
	__inline T* getBlockData(u32 blockID, u32 index) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		ntr_assert(index < stageBlocksElements[blockID], "Block %d does not contain element %d", blockID, index);
		u8* data = static_cast<u8*>(stageBlocks[blockID]);
		data += (index * getBlockUnitSize(blockID));
		return static_cast<T*>(static_cast<void*>(data));
	}

	template<class T>
	__inline T* getBlock(u32 blockID) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Block ID must be between 0 and 13");
		return static_cast<T*>(stageBlocks[blockID]);
	}

}
