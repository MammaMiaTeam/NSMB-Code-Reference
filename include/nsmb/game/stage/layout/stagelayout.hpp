#pragma once

#include <nsmb/game/stage/actor.hpp>
#include "data/path.hpp"
#include "texturerenderer.hpp"

constexpr u32 PlayerCount = 2;

// TODO
class StageLayout : public Object {
public:

	constexpr static u32 ChunksX = 32;
	constexpr static u32 ChunksY = 16;

	struct ScreenInfo {

		u16 id;
		u16 speedX;
		u16 speedY;
		fx32 y;

	};
	NTR_SIZE_GUARD(ScreenInfo, 0xC);

	struct AnimationInfo {

		struct AnimElement {
			u16 frame;
			s16 timer;
		};
		NTR_SIZE_GUARD(AnimElement, 0x4);

		struct ConveyorAnim {
			u32 frame;
			u16 timer;
		};
		NTR_SIZE_GUARD(ConveyorAnim, 0x8);

		u16 coinFrame;
		u16 questionBlockFrame;
		u8 coinAnimSwitch;
		u8 unk5;
		u16 brickBlockFrame;
		u16 unk8;
		AnimElement coinOutline;
		AnimElement castleTorch;
		AnimElement animBG;
		AnimElement unk16;
		AnimElement animTS;
		AnimElement volcanoBG;
		AnimElement kazangake;
		AnimElement lavaFallBG;
		AnimElement lavaFallFG;
		AnimElement iceGlitters[4];
		AnimElement ghostHouseStairs[3];
		u16 unk4A;
		u16 unk4C;
		u16 unk4E;
		ConveyorAnim conveyorMid;
		ConveyorAnim conveyorSide;
		u32 conveyorBeltSpeed;
		u16 unk64;
		u8 unk66;
		u8 unk67;
		bool redBlocksVisible;
		bool switchCoinVisible;

	};
	NTR_SIZE_GUARD(AnimationInfo, 0x6C);

	struct Scroller {

		StagePathNode* firstNode;
		StagePathNode* currentNode;
		fx32 nextNodeX;
		fx32 nextNodeY;
		fx32 forceX;
		fx32 forceY;
		fx32 speedX;
		fx32 speedY;
		fx32 accelX;
		fx32 accelY;
		fx32 unused28;
		fx32 unused2C;
		fx32 focusVelocity;
		u16 nodeCount;
		u16 viewID;
		u8 unused38;
		u8 autoScrollFlags;
		u8 autoScrollEndMode;
		u8 autoScrollDirection;

	};
	NTR_SIZE_GUARD(Scroller, 0x3C);

	struct ScreenHDMA {

		u16 speed;
		u16 timer;
		fx32 amplitude; // Used for wave effects
		s16 frequency;  // Used for wave effects
		u16 unkA;
		u16 unkC;
		u16 unkE;

	};
	NTR_SIZE_GUARD(ScreenHDMA, 0x10);

	struct AppearingTile {

		u16 tileX;
		u16 tileY;
		u16 switchDelay;
		u16 targetTile;

	};
	NTR_SIZE_GUARD(AppearingTile, 0x8);

	struct ChangingTile {

		u16* rows[2];
		u16 tileOffset;
		u16 unkA;

	};
	NTR_SIZE_GUARD(ChangingTile, 0xC);

	struct ScrollBarrier {

		s16 positionLeft;
		s16 positionRight;
		s16 limitViewTop;
		s16 limitViewBottom;
		s16 positionTop;
		s16 positionBottom;
		s16 viewTop;
		s16 viewBottom;
		s16 viewLeft;
		s16 viewRight;
		u16 flags;

	};
	NTR_SIZE_GUARD(ScrollBarrier, 0x16);

	struct SpawnCamera {

		u32 x;
		u32 y;
		u32 unk8;
		u32 unkC;
		u8 unk10;
		u8 unk11;
		u8 unk12;
		u8 unk13;

	};
	NTR_SIZE_GUARD(SpawnCamera, 0x14);

	struct CameraInfo {

		s32 unk0;
		s32 unk4;
		s32 unk8;
		s32 unkC;
		s32 unk10;
		s32 unk14;
		s32 unk18;
		s32 unk1C;
		s32 unk20;
		s32 unk24;

	};
	NTR_SIZE_GUARD(CameraInfo, 0x28);

	struct Unk2 {

		u32 unk0[4][2];
		u32 unk20[4][2];
		u8 unk40;
		u8 unk41;
		u8 unk42;
		u8 unk43;

	};
	NTR_SIZE_GUARD(Unk2, 0x44);

	struct CameraOffset {

		s16 top;
		s16 bottom;
		s16 left;
		s16 right;
		fx32 offset;
		fx32 frames; // TODO: Maybe?
		u32 computedOffset;

	};
	NTR_SIZE_GUARD(CameraOffset, 0x14);

	struct PathLooperArea {

		fx32 top;
		fx32 bottom;
		fx32 left;
		fx32 right;

	};
	NTR_SIZE_GUARD(PathLooperArea, 0x10);

	struct PathLooperPath {

		PathLooperArea area;
		u8 passedCount;
		u8 unk11;
		u8 unk12;
		u8 unk13;

	};
	NTR_SIZE_GUARD(PathLooperPath, 0x14);

	struct PathLooperSection {

		u32 startX;
		u16 current;
		u16 unk6;
		PathLooperArea area;
		u32 unk18;
		PathLooperPath paths[8];
		u8 unkBC;
		u8 pathCount;
		u8 unkBE;
		u8 unkBF;

	};
	NTR_SIZE_GUARD(PathLooperSection, 0xC0);

	struct PathLooper {

		PathLooperSection sections[4];
		u8 sectionCount;

	};
	NTR_SIZE_GUARD(PathLooper, 0x304);

	struct AffineScreen {

		u16 unk0;
		u16 unk2;
		s16 x;
		s16 y;
		MtxFx22 matrix;

	};
	NTR_SIZE_GUARD(AffineScreen, 0x18);

	struct AffineScreens {

		AffineScreen screens[2];

	};
	NTR_SIZE_GUARD(AffineScreens, 0x30);

	struct Rotator {

		u16* tilesetScreen;
		fx32 viewPosition[PlayerCount];
		fx32 displacement[PlayerCount];
		fx32 forcedScrollX;
		fx32 originalScrollY;
		u16 mirrorOffset;
		u16 angle;
		u8 eventFlag;

	};
	NTR_SIZE_GUARD(Rotator, 0x24);

	struct CameraBounds {

		fx32 bottom;
		fx32 top;
		fx32 left;
		fx32 right;
		fx32 unk10;

	};
	NTR_SIZE_GUARD(CameraBounds, 0x14);

	struct Shaker {

		fx32 target;
		fx32 factor;
		fx32 step;
		fx32 maxStep;
		fx32 minStep;

	};
	NTR_SIZE_GUARD(Shaker, 0x14);


	// 020af30c
	void changeTile(u32 x, u32 y, u32 id);

	// 020af8f0
	u32 getTileBehavior(u32 x,u32 y, s32 playerNo);

	// 020b0308
	u32 getChunkID(u32 x,u32 y);

	// 020afa30
	void readTileBehavior(u16 tileID);

	// 020B7FE4
	void animateQuestionBlocks();

	// 020B807C
	void animateBrickBlocks();

	// 020B8364
	void animateCoins(u8 frame);

	// 020cac98
	static bool doLayoutReset;


	fx32 zoomFactor[PlayerCount];
	u8 tilemapChunkTable[ChunksX * ChunksY];
	u8 scrollChunkTable[ChunksX * ChunksY];
	u16 tilemapChunkCount;
	u16 scrollChunkCount;
	u16 chunkRenderLeftX;
	u16 chunkRenderRightX;
	u16 chunkRenderTopY;
	u16 chunkRenderBottomY;
	u16 wrapMaskX;
	u16 chunkSourceX;
	u16 unk474;
	u16 unk476;
	u8 spawnViewID[PlayerCount];

	ScreenInfo screenBG[PlayerCount];
	ScreenInfo screenTS[PlayerCount];
	ScreenInfo screenFG[PlayerCount];

	AnimationInfo anim;

	u32 unk530;
	u32 unk534[2];
	u32 unk53C[2];
	u32 unk544[2][2];
	u32 unk554[2][2];
	fx32 manualCameraScroll[PlayerCount];
	fx32 manualCameraStep[PlayerCount];
	fx32 unk574[PlayerCount];
	fx32 scrollBoundBottom[PlayerCount];
	fx32 spawnViewTop[PlayerCount];
	fx32 spawnViewBottom[PlayerCount];
	fx32 spawnViewLeft[PlayerCount];
	fx32 spawnViewRight[PlayerCount];
	fx32 unk5A4[PlayerCount];
	fx32 focusCameraScroll[PlayerCount];
	fx32 focusCameraTarget[PlayerCount];
	s16 focusCameraOffset[PlayerCount];

	Scroller scrollers[PlayerCount];

	ScreenHDMA hdmaBG[PlayerCount];
	ScreenHDMA hdmaFG[PlayerCount];
	fx32 hdmaScrollBG[2][4];
	fx32 hdmaScrollFG[2][4];

	AppearingTile appearingCoins[64];
	u16 appearingCoinCount;

	ChangingTile changingTiles[64];

	StageLayoutTextureRenderer textureRenderer;

	ScrollBarrier scrollBarriers[16][4][16];

	fx32 totalBGScrollX[PlayerCount];
	fx32 totalFGScrollX[PlayerCount];
	u32 unk71E8[PlayerCount];

	SpawnCamera spawnCamera[PlayerCount];

	u32 screenBlockBG[PlayerCount];
	u32 screenBlockFG[PlayerCount];

	u16 playerChunkOffsetX[PlayerCount];
	u16 unk722C[PlayerCount];
	u32 unk7230[PlayerCount];
	s32 spawnViewTime[PlayerCount];

	u8 manualCameraScrolling[PlayerCount];
	u8 manualCameraLimited[PlayerCount];

	CameraInfo cameraInfo[PlayerCount];

	Unk2 unk7294[16];
	u8 unk76D4[PlayerCount];
	u8 unk76D6[PlayerCount];

	CameraOffset cameraOffsets[16];
	u16 cameraOffsetCount;
	fx32 cameraOffsetX[PlayerCount];

	PathLooper pathLoopers[16];

	AffineScreens affineScreens[PlayerCount];

	u32 unkA8C4[PlayerCount];

	Rotator rotator;

	bool peachCastleHidden[PlayerCount];

	CameraBounds cameraBounds[PlayerCount];

	u32 unkA91C[PlayerCount];
	u32 unkA924[PlayerCount];
	u32 unkA92C[PlayerCount];
	u32 unkA934[PlayerCount];

	Shaker shakerBG;

};
NTR_SIZE_GUARD(StageLayout, 0xA950);


namespace Stage
{
	// 0212f180
	extern GXOamAttr* anmTilesOamTable[23];

	// 020cad40
	extern StageLayout* stageLayout;
}
