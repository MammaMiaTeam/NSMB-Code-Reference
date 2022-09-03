#pragma once
#include "nsmb.h"


// vtable at 0217B934 (ov82)
class Snowball : public StageEntity
{
public:

	using StateFunction = bool(Snowball::*)();

	~Snowball() override;

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;
	bool updateDefeated() override;
	bool updateDefeatedMega() override;
	void onBlockHit() override;
	void onEntityHit() override;
	void defeat(fx32 velX, fx32 velY, fx32 accelY, u8 arg) override;

	bool switchState(StateFunction func);
	bool updateState();

	bool mainState();

	static bool activeCallback(ActiveCollider& self, ActiveCollider& other);
	static bool loadResources();

	static constexpr u16 objectID = 156;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 181;

	static const ActorProfile profile;
	static const ActiveColliderInfo activeColliderInfo;
	static const LineSensorH topSensor;
	static const LineSensorH bottomSensor;
	static const LineSensorV sideSensor;


	Model model;

	StateFunction updateFunction;

	LineSensorH sensorTop;
	LineSensorH sensorBottom;
	LineSensorV sensorSide;
	FxRect hitboxRect;

	fx32 accelScale;
	fx32 accelCounter;
	EmitterT smokeEmitter;

	u8 unused4D8;
	s8 updateStep;

};
NTR_SIZE_GUARD(Snowball, 0x4DC);
