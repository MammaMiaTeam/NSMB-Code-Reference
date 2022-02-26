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

	// 0212944c
	extern u8 questionBlockFrame;

	// 0212943c
	extern u8 brickBlockFrame;


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


	// 0200e6f4
	// used in stage related operations (actors, spawns, tile randomization)
	ssym u32 getRandom() __rbody

	IMPL_RANDOM(Stage::getRandom);

}
