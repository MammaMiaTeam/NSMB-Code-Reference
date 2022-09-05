#pragma once
#include "ntr_assert.h"
#include "entrance.h"


enum class StageBlockID : u32 {
	Header,
	Camera,
	Background,
	Tileset,
	Foreground,
	Entrances,
	StageObjs,
	Views,
	Zones,
	ProgressPaths,
	Paths,
	PathNodes,
	ProgressPathNodes,
	ObjectBanks,

	Max
};


struct StageBlocks {

	void* header;
	void* camera;
	void* background;
	void* tileset;
	void* foreground;
	StageEntrance* entrances;
	void* stageObjs;
	void* views;
	void* zones;
	void* progressPaths;
	void* paths;
	void* pathNodes;
	void* progressPathNodes;
	void* objectBanks;

	NTR_INLINE void* operator[] (u32 blockID) {

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		return static_cast<void**>(&header) + blockID;

	}

};


namespace Stage
{

	// DATA

	// 0203C8A0
	extern const char* stageGroupNames[10];

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

		if_consteval {

			constexpr u32 sizes[] = {
				0x20,
				0x18,
				0x14,
				0x14,
				0x14,
				sizeof(StageEntrance),
				0x0C,
				0x10,
				0x0C,
				0x08,
				0x08,
				0x10,
				0x10,
				0x10
			};

			return sizes[blockID];

		}

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		return stageBlockUnitSize[blockID];

	}

	NTR_INLINE u32 getBlockSize(u32 blockID) {

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		return stageBlocksSize[blockID];

	}

	NTR_INLINE u32 getBlockElementCount(u32 blockID) {

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		return stageBlocksElements[blockID];

	}

	template<class T>
	NTR_INLINE T* getBlockData(u32 blockID, u32 index) {

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		ntr_assert(index < stageBlocksElements[blockID], "Invalid element index [%d] for block [%d]", index, blockID);
		return static_cast<T*>(stageBlocks[blockID]) + index;

	}

	template<class T>
	NTR_INLINE T* getBlock(u32 blockID) {

		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID");
		return static_cast<T*>(stageBlocks[blockID]);

	}

}
