#pragma once
#include "nsmb.h"


// vtable at 02125220 (ov10)
class Coin : public StageEntity
{
public:

	using StateFunction = bool(Coin::*)();

	enum class CoinType
	{
		Normal,
		Bubble,
		ThreeBubbles,
		Jumping,
		Falling,
		JumpingStationary,
		FloatingHorizontal,
		BlockFloating,
		CheepCheepTrail,
		Collected,
		BlockJumping,
		JumpingHigh
	};


	// D0: 020D8150
	// D1: 020D80CC
	virtual ~Coin();

	// 020D8628
	s32 onCreate() override;
	// 020D8604
	s32 onDestroy() override;
	// 020D8248
	s32 onRender() override;

	// 020D84EC
	bool updateMain() override;

	// 020D8244
	void updateAnimation() override;

	// 020D9BF4
	void onBlockHit() override;
	// 020D8568
	void onStageBeaten(Player& player) override;

	// 020D81DC
	void detach();
	// 020D823C
	void setOwnerBlock(u32 guid);
	// 020D8488
	void renderBubbleSprite();
	// 020D8B40
	void prepareBubble();
	// 020D99A8
	void updateBubbleScale();
	// 020D9ACC
	void updateLiquidScale();
	// 020D9B40
	void updateSpriteAnimations();
	// 020D9B84
	void updateDespawn();
	// 020D9C78
	bool updateCollision();

	// 020D9DCC
	bool switchState(const StateFunction& function);
	// 020D9D84
	void updateState();

	// 020D9890
	bool defaultState();
	// 020D9634
	bool jumpState();
	// 020D93B4
	bool fallState();
	// 020D923C
	bool detachedState();
	// 020D91F4
	bool floatState();
	// 020D9004
	bool bubbleState();
	// 020D8FB0
	bool blockFloatWaitState();
	// 020D8EEC
	bool blockFloatState();
	// 020D8D9C
	bool collectedState();
	// 020D8B9C
	bool blockJumpState();

	// 020D9CF0
	static void bottomCollision(StageActor& self, StageActor& other);

	static constexpr u16 objectID = 66;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 158;

	// 021251F8
	static const ActorProfile profile;

	// 02125204
	static const ColliderInfo colliderInfo;

	// 02121700
	static const fx32 velocitiesY[8];
	// 021216EC
	static const fx32 blockFloatingVelocitiesX[5];
	// 021216D8
	static const fx32 slopeVelocitiesX[5];
	// 021216C4
	static const fx32 blockFloatingVelocitiesY[5];
	// 021216B4
	static const fx32 bounceVelocitiesY[4];
	// 021216A8
	static const fx32 velocityXMasks[3];
	// 0212169C
	static const PointSensor sideSensor;
	// 02121690
	static const PointSensor topSensor;
	// 02121684
	static const PointSensor bottomSensor;
	// 02121678
	static const fx32 bubbleSpawnOffsetsY[3];
	// 0212166C
	static const fx32 bubbleSpawnOffsetsX[3];
	// 02121660
	static const fx32 fallingVelocityAttenuation[3];
	// 02121654
	static const fx32 fallingVelocityMax[3];
	// 0212164C
	static const fx32 floatingVelocitiesX[2];
	// 02121644
	static const fx32 blockJumpVelocitiesX[2];
	// 0212163C
	static const fx32 detachedVelocitiesX[2];
	// 02121634
	static const s16 bubbleAngles[4];

	// 02129424
	static const StateFunction sBlockSpawn;
	// 0212941C
	static const StateFunction sDefault;
	// 02129414
	static const StateFunction sJump;
	// 0212940C
	static const StateFunction sFall;
	// 02129404
	static const StateFunction sCollected;
	// 021293FC
	static const StateFunction sFloat;
	// 021293F4
	static const StateFunction sDetached;
	// 021293EC
	static const StateFunction sBlockFloatWait;
	// 021293E4
	static const StateFunction sBubble;
	// 021293DC
	static const StateFunction sBlockFloat;


	u32 blockGUID;

	Vec3 spawnPositionBubble;
	Vec3 spawnPosition;
	Vec2 liquidScale;
	Vec2 bubbleScale;

	const StateFunction* updateFunction;

	Vec3 unused434;
	Collider collider;

	fx32 bubbleScaleStep;
	u32 velocityMask;
	u32 velocityMax;
	u32 velocityAttenuation;
	CoinType type;
	u32 layerFlag;

	u16 blockFloatCooldown;
	u16 despawnTimer;
	u16 blinkTimer;
	u16 blinkVisible;
	u16 bounceCounter;
	u16 collectedCooldown;
	u16 blockJumpCooldown;
	bool16 blockJumpAppeared;

	bool renderBubble;
	u8 bubbleFrame;
	u8 bubblesLeft;
	u8 bubbleDirection;
	bool bubbleBlockImmune;
	u8 liquidScalePhase;
	u8 bubbleScalePhase;
	bool renderLiquid;
	u8 animationFrame;
	u8 animationTimer;
	u8 unused4E2;
	u8 collectedPlayerID;
	s8 updateStep;

};
NTR_SIZE_GUARD(Coin, 0x4E8);
