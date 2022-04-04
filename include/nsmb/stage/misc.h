#pragma once
#include "nitro_if.h"
#include "layout/stagelayout.h"
#include "layout/data.h"


enum class CollisionType : u32;

enum class PowerupState : u8;

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

	// 020ca284
	extern u8 megaInteractionFlags;

	// 020ca28c
	extern bool freezeFlag;

	// 020ca29c
	extern bool fenceFreezeFlag;

	// 020ca2a0
	extern u8 currentBooStackIndex;

	// 020ca2a4
	extern u8 eventData[2];

	// 020ca2bc
	extern u32 megaInteractionViews;

	// 020ca2c0
	extern CollisionType globalCollisionTrigger;

	// 020ca2c4
	extern u32 megaGroundPoundViews[2];

	// 02085a18
	extern u8 stageGroup;

	// 02085a14
	extern u8 stageID;

	// 02085a4c
	extern u8 actID;

	// 020ca850
	extern ActorCategory actorFreezeFlag;

	// 020ca874
	extern bool phantomHandsTargetEnabled;

	// 020ca8b0
	extern u16 phantomHandsDisableMask;

	// 020ca918
	extern Vec3 phantomHandsTarget;

	// 0208b328
	extern bool playerDead[2];

	// 0208b324
	extern PowerupState initialPowerup[2];

	// 0208b32c
	extern PowerupState storedPowerup[2];


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
