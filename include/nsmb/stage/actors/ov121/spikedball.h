#pragma once
#include "nsmb.h"


// vtable at 0218DFB4 (ov121)
class SpikedBall : public StageEntity
{
public:

	using StateFunction = bool(SpikedBall::*)();

	// D0: 0218C828
	// D1: 0218C7C0
	virtual ~SpikedBall();

	// 0218C9C0
	s32 onCreate() override;
	// 0218C89C
	s32 onDestroy() override;
	// 0218C8A8
	s32 onRender() override;
	// 0218C8A4
	void onCleanupResources() override;
	// 0218D218
	bool onPrepareResources() override;

	// 0218C9A0
	bool updateMain() override;

	// 0218C898
	void onBlockHit() override;

	// 0218D088
	void updateVelocity();

	// 0218D148
	bool switchState(StateFunction function);
	// 0218D10C
	void updateState();

	// 0218CD6C
	bool mainState();

	// 0218D250
	static bool loadResources();
	// 0218CC34
	static s32 activeCallback(ActiveCollider& self, ActiveCollider& other);

	static constexpr u16 objectID = 103;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 224;

	// 0218DFA8
	static const ActorProfile profile;

	// 0218DF10
	static const ActiveColliderInfo activeColliderInfo;
	// 0218DEFC
	static const fx32 slopeAccelerationsX[5];
	// 0218DEF8
	static const fx16 slopeVelocitiesX[2];
	// 0218DEEC
	static const fx16 velocitiesX[3][2];
	// 0218DEDC
	static const LineSensorV sideSensor;
	// 0218DECC
	static const LineSensorH bottomSensor;
	// 0218DEBC
	static const LineSensorH topSensor;


	Model model;

	StateFunction updateFunction;

	FxRect hitboxRect;
	CollisionMgrResult groundCollision;
	EmitterT smokeEmitterID;

	bool bouncingFlag;
	s8 updateStep;
	u16 renderY;
	u8 spikedBallID;
	bool activeFlag;

};
NTR_SIZE_GUARD(SpikedBall, 0x4AC);
