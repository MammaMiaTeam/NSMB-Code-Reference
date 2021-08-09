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
	extern fx32 playerX[2];

	// 020cad94
	extern fx32 playerY[2];
	
	// 020cada4
	extern fx32 cameraX[2];

	// 020cad8c
	extern fx32 cameraY[2];


	__inline bool getEvent(u8 id) {
		return events & (1ULL << id);
	}
	__inline void setEvent(u8 id) {
		events &= ~(1ULL << id);
	}
	__inline void clearEvent(u8 id) {
		events &= ~(1ULL << id);
	}


	// 020facfc
	void setZoom(fx32 zoom, u32 delay, u8 playerID, u8 unk);


	// 0200e6f4
	// used in stage related operations (actors, spawns, tile randomization)
	ssym u32 getRandom() __rbody

	IMPL_RANDOM(Stage::getRandom);

}
