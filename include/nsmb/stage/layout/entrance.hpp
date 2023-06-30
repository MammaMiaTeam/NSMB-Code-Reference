#pragma once
#include "nsmb_nitro.hpp"


enum class PlayerSpawnType : u8;


enum class EntranceType : u8 {

	Normal,
	OverriddenNormal,	// Used in Entrance::accessSpawnEntrance, when the spawn position has been overridden
	Door,
	PipeUp,
	PipeDown,
	PipeLeft,
	PipeRight,
	Falling,
	GroundPounding,
	Sliding,
	Swimming,
	TransitNormal,		// Same as Normal, only during transition from another entrance
	TransitDoor,		// Same as Door, only during transition from another entrance
	MvsLPipe,
	Unknown14,			// Invisible door, no sound
	Unknown15,			// Invisible door
	MiniPipeUp,
	MiniPipeDown,
	MiniPipeLeft,
	MiniPipeRight,
	Jumping,
	Vine

};


enum class EntranceFlags : u8 {
	
	SubScreen		= 0x01,
	LockedPlayer1	= 0x02,
	LockedPlayer0	= 0x04,
	ConnectedPipe	= 0x08,
	WipeFade		= 0x10,
	AlignedX		= 0x40,
	ExitOnly		= 0x80

};
NTR_CREATE_BITMASK_ENUM(EntranceFlags);


enum class EntranceTransitionFlags : u8 {

	SubScreen		= 0x01,
	FromMainScreen	= 0x02,
	FromSubScreen	= 0x04,
	CircleFade		= 0x08

};
NTR_CREATE_BITMASK_ENUM(EntranceTransitionFlags);


enum class EntranceUseResult : u32 {

	InvalidEntrance,
	RegularEntrance,
	ConnectedPipe,

};


struct StageEntrance {

	u16 x;
	u16 y;
	u16 cameraX;
	u16 cameraY;

	u8 id;
	u8 targetStageArea;			// TODO: document behavior when `flags & ConnectedPipe`
	u8 targetStageIndex;		// If `flags & ConnectedPipe` -> Pipe path ID
	u8 targetStageGroup;
	u8 targetEntrance;
	u8 cameraZoom;

	EntranceType type;
	EntranceFlags flags;

	u8 unk10;
	u8 unk11;
	u8 viewID;
	u8 targetWorldmapNode;

};
NTR_SIZE_GUARD(StageEntrance, 0x14);


struct EntranceInfo {

	fx32 x;
	fx32 y;
	fx32 shiftX;
	BOOL markUsedFlag;

};


namespace Entrance {

	void overrideSpawnPosition(u8 playerID, fx32 x, fx32 y);

	void switchVSMusic();

	void resetVSMusic();

	u32 getSpawnMusic(u8 playerID);

	s16 getViewRightBoundary(u8 playerID);

	s16 getViewLeftBoundary(u8 playerID);

	s16 getViewBottomBoundary(u8 playerID);

	s16 getViewTopBoundary(u8 playerID);

	void overrideEntrance(fx32 x, fx32 y, u8 playerID, EntranceType type, EntranceFlags flags, s8 viewID);

	void setSpawnEntrance(u8 entranceID, u8 playerID);

	u32 getEntranceIndex(u8 entranceID);

	u32 getEntranceCount();

	StageEntrance* getEntrance(s8 entranceID);

	StageEntrance* getEntranceBlock();

	fx32 getEntranceZoom(s8 entranceID);

	PlayerSpawnType getEntranceSpawnType(s8 entranceID);

	Vec3 accessSpawnEntrance(u8 playerID);

	Vec3 accessEntrance(s8 entranceID, u8 playerID);

	// Always returns false
	bool switchArea();

	// Does nothing
	void reloadArea();

	void setTargetArea(u8 entranceID, u8 stageArea);

	void setTargetEntrance(const StageEntrance& entrance);

	EntranceUseResult tryUseEntrance(fx32 x, fx32 y, u8 playerID);

	bool setTargetEntrance(u8 entranceID);


	extern EntranceFlags lockedEntranceFlags[2];
	extern u32 vsMusicID;
	extern PlayerSpawnType playerSpawnTypes[22];
	extern EntranceInfo entranceInfoTable[22];


	extern u8 targetEntranceID;
	extern u8 connectedPipeUnkByte[2];
	extern bool subScreenSpawn[2];
	extern u8 connectedPipePath[2];
	extern u8 spawnEntranceID[2];
	extern EntranceTransitionFlags transitionFlags[2];
	extern s32 targetAreaID;
	extern StageEntrance* spawnEntrance[2];
	extern Vec2 overriddenSpawnPosition[2];
	extern StageEntrance overriddenEntrance[2];

}
