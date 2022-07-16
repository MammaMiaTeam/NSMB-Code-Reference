#pragma once
#include "nsmb.h"


// vtable at 0218E0DC (ov121)
class BigSpikedBall : public StageEntity
{
public:

	using StateFunction = bool(BigSpikedBall::*)();

	// D0: 0218D314
	// D1: 0218D2AC
	virtual ~BigSpikedBall();

	// 0218D4A4
	s32 onCreate() override;
	// 0218D388
	s32 onDestroy() override;
	// 0218D394
	s32 onRender() override;
	// 0218D390
	void onCleanupResources() override;
	// 0218DC84
	bool onPrepareResources() override;

	// 0218D484
	bool updateMain() override;

	// 0218D384
	void onBlockHit() override;

	// 0218DAF4
	void updateVelocity();

	// 0218DBB4
	bool switchState(StateFunction function);
	// 022D7718
	void updateState();

	// 0218D850
	bool mainState();

	// 0218DCBC
	static bool loadResources();
	// 0218D700
	static s32 activeCallback(ActiveCollider& self, ActiveCollider& other);

	static constexpr u16 objectID = 185;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 226;

	// 0218E0D0
	static const ActorProfile profile;

	// 022D7B20
	static const ActiveColliderInfo activeColliderInfo;
	// 0218DF6C
	static const fx32 slopeAccelerationsX[5];
	// 0218DF68
	static const fx16 slopeVelocitiesX[2];
	// 0218DF5C
	static const fx16 velocitiesX[3][2];
	// 0218DF4C
	static const LineSensorV sideSensor;
	// 0218DF3C
	static const LineSensorH bottomSensor;
	// 0218DF2C
	static const LineSensorH topSensor;


	Model model;

	StateFunction updateFunction;

	FxRect hitboxRect;
	EmitterT smokeEmitterID;
	CollisionMgrResult groundCollision;

	bool bouncingFlag;
	s8 updateStep;

};
NTR_SIZE_GUARD(BigSpikedBall, 0x4A8);
