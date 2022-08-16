#pragma once
#include "nitro_if.h"
#include "layout/stagelayout.h"
#include "layout/data.h"
#include "nsmb/wifi/util.h"


enum class CollisionType : u32;

enum class PowerupState : s8;

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
	extern fx32 cameraWidth[2];

	// 020cad8c
	extern fx32 cameraHeight[2];

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

	// 02026290
	extern const GXRgb starToonTable[32];


	NTR_INLINE bool getEvent(u8 id) {
		return events & (1ULL << (id - 1));
	}

	NTR_INLINE void setEvent(u8 id) {
		events &= ~(1ULL << (id - 1));
	}

	NTR_INLINE void clearEvent(u8 id) {
		events &= ~(1ULL << (id - 1));
	}

	// 020facfc
	void setZoom(fx32 zoom, u32 delay, u8 playerID, u8 unk);

	// 0201f53c
	u32 getAreaID(u8 group, u8 stage, u8 act);

	// Used in stage related operations (actor spawning, tile randomization)
	
	NTR_INLINE s32 getRandom(s32 max) {
		return ((Wifi::getRandom() & 0x7FFF) * (max + 1)) / 0x8000;
	}

	NTR_INLINE s32 getRandom(s32 min, s32 max) {
		return getRandom(max - min) + min;
	}

	NTR_INLINE u16 getRandom() {
		return getRandom(0x7FFF);
	}

	// Camera/range utilities

	fx32 getCameraCenterX(u8 playerID);
	fx32 getCameraCenterY(u8 playerID);

	bool isOutsideCamera(const Vec3& position, const FxRect& boundingBox, u8 playerID);
	bool isOutsideCameraNoWrap(const Vec3& position, const FxRect& boundingBox, u8 playerID);
	bool isOutsideCameraWrap(const Vec3& position, const FxRect& boundingBox, u8 playerID);

	bool isOutsidePlayerRangeWrap(const Vec3& position, const FxRect& boundingBox, u8 viewID);
	bool isOutsidePlayerRangeNoWrap(const Vec3& position, const FxRect& boundingBox, u8 playerID, u8 viewID);
	bool isOutsidePlayerRange(const Vec3& position, const FxRect& boundingBox, u8 viewID);

	u32 getForegroundScreenID(u32 fgID);

}
