#pragma once

#include "nsmb/extra/assert.hpp"
#include "data/header.hpp"
#include "data/camera.hpp"
#include "data/screen.hpp"
#include "data/entrance.hpp"
#include "data/object.hpp"
#include "data/view.hpp"
#include "data/zone.hpp"
#include "data/path.hpp"

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

	StageHeader* header;
	StageCameraInfo* camera;
	StageScreen* background;
	StageScreen* tileset;
	StageScreen* foreground;
	StageEntrance* entrances;
	StageObject* stageObjs;
	StageView* views;
	StageZone* zones;
	StagePath* progressPaths;
	StagePath* paths;
	StagePathNode* pathNodes;
	StagePathNode* progressPathNodes;
	void* objectBanks;

	NTR_INLINE void* operator[] (u32 blockID) {
		ntr_assert(blockID < u32(StageBlockID::Max), "Invalid block ID [%d]", blockID);
		return rcast<void**>(this) + blockID;
	}

};
NTR_SIZE_GUARD(StageBlocks, sizeof(AddressT) * 14);

namespace Stage {

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

		if consteval {

			constexpr u32 sizes[] = {
				sizeof(StageHeader),
				sizeof(StageCameraInfo),
				sizeof(StageScreen),
				sizeof(StageScreen),
				sizeof(StageScreen),
				sizeof(StageEntrance),
				sizeof(StageObject),
				sizeof(StageView),
				sizeof(StageZone),
				sizeof(StagePath),
				sizeof(StagePath),
				sizeof(StagePathNode),
				sizeof(StagePathNode),
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
