#pragma once
#include "nsmb.h"


// vtable at 0214520C (ov34)
class FenceKoopa : public StageEntity {

public:

	using StateFunction = bool(FenceKoopa::*)();

	// D0: 02141EE8
	// D1: 02141E80
	virtual ~FenceKoopa();

	// 021424FC
	s32 onCreate() override;
	// 02142214
	s32 onDestroy() override;
	// 02142220
	s32 onRender() override;
	// 0214221C
	void onCleanupResources() override;
	// 02142F50
	bool onPrepareResources() override;

	// 021424A0
	bool updateMain() override;

	// 021421A0
	void onBlockHit() override;
	// 02142408
	void onStomped() override;

	// 02142374
	void damagePlayer(ActiveCollider& self, Player& player) override;
	// 02142450
	void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 arg) override;

	// 02142104
	static void setMaterialPalette(ModelAnm& model, u32 matID, u32 paletteID);

	// 02142138
	u32 checkAdjacentTile(const PointSensor& sensor) const;

	// 02142E5C
	bool switchState(StateFunction function);
	// 02142E20
	void updateState();

	// 02142C54
	bool horizontalClimbState();
	// 02142AA0
	bool verticalClimbState();

	// 02142900
	bool horizontalFlipSideState();
	// 021427F0
	bool verticalClimbOverGrabState();
	// 02142660
	bool verticalClimbOverJumpState();

	// 02142FD0
	static void loadModel();
	// 02142FA8
	static bool loadResources();

	// 02141F58
	static void activeCallback(ActiveCollider& self, ActiveCollider& other);

	static constexpr u16 objectID = 96;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 244;

	// 02145200
	static const ActorProfile profile;

	// 02144F80
	static const ActiveColliderInfo activeColliderInfo;

	// 02144F74
	static PointSensor bottomSensor;
	// 02144F68
	static PointSensor topSensor;
	// 02144F5C
	static PointSensor sideSensor;

	// 02144F58
	static const s16 layerRotationY[2];
	// 02144F54
	static const fx16 climbFastVelocities[2];
	// 02144F50
	static const fx16 climbVelocities[2];
	// 02144F4C
	static const u16 paletteOffsets[2];
	// 021454C0
	static u16 paletteBase;


	ModelAnm model;

	StateFunction updateFunction;
	StateFunction prevUpdateFunction;

	fx32 climbDistance;
	fx32 climbOverPosY;

	u8 verticalFlag;
	s8 updateStep;

};
NTR_SIZE_GUARD(FenceKoopa, 0x4B8);
