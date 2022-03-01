#pragma once
#include "nitro_if.h"
#include "layout/stagelayout.h"
#include "layout/data.h"


namespace Stage
{

	// 020cae0c
	extern fx32 liquidPosition[2];

	// 020cadac
	extern fx32 lastLiquidPosition[2];

	// 0208af3c
	extern u64 events;

	// 020cae1c
	extern fx32 cameraX[2];

	// 020cad94
	extern fx32 cameraY[2];

	// 020cada4
	extern fx32 cameraZoomX[2];

	// 020cad8c
	extern fx32 cameraZoomY[2];

	// 020ca29c
	extern bool fenceFreezeFlag;

	// 0212944c
	extern u8 questionBlockFrame;
	
	// 02085a18
	extern u8 stageGroup;

	// 02085a14
	extern u8 stageID;

	// 02085a4c
	extern u8 actID;

	// 020ca850
	extern ActorCategory freezeFlag;


	__inline bool getEvent(u8 id) {
		return events & (1ULL << (id - 1));
	}
	__inline void setEvent(u8 id) {
		events &= ~(1ULL << (id - 1));
	}
	__inline void clearEvent(u8 id) {
		events &= ~(1ULL << (id - 1));
	}

	// 020200d4
	void addMegaDestructionScore(u8 playerID, s16 amount);

	// 02020114
	u16 getMegaDestructionScore(u8 playerID);

	// 02020128
	void setMegaDestructionScore(u8 playerID, u16 score);

	// 020facfc
	void setZoom(fx32 zoom, u32 delay, u8 playerID, u8 unk);

	// 0201f53c
	u32 getAreaID(u8 group, u8 stage, u8 act);


	// 0200e6f4
	// used in stage related operations (actors, spawns, tile randomization)
	ssym u32 getRandom() __rbody

	IMPL_RANDOM(Stage::getRandom);

}
