#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/model.hpp>
#include <nsmb/core/graphics/3d/animation.hpp>

class RedCoinRing : public StageEntity
{
public:
	using StateFunction = bool(RedCoinRing::*)();

	// D0: 0x02152F90
	// D1: 0x02152EDC
	virtual ~RedCoinRing();

	s32 onCreate() override; // 0x02153174
	s32 onDestroy() override; // 0x0215304C
	s32 onRender() override; // 0x02153058

	void onCleanupResources() override; // 0x02153054
	bool onPrepareResources() override; // 0x021533FC
	bool updateMain() override; // 0x02153150

	void updateDistance(u32 playerID); // 0x021532BC
	bool checkCollided(u32 playerID); // 0x02153370
	bool loadResources(); // 0x02153498
	bool collectedState(); // 0x021534CC
	void easeRotation(s16& value, s16 endValue, s16 step); // 0x021535CC
	bool waitCollectState(); // 0x02153604
	void updateState(); // 0x02153804
	bool switchState(StateFunction function); // 0x02153860

	// 0x02153954
	static RedCoinRing* construct();

	static ActorProfile profile; // 0x0216CD90

	static StateFunction sWaitCollect; // 0x0216CD80
	static StateFunction sCollected; // 0x0216CD88

	Model model;
	Animation animation;
	StateFunction updateFunction;
	StateFunction prevUpdateFunction;
	Vec2 playerDistance[2];
	Vec2 prevPlayerDistance[2];
	u32 unused;
	s16 rotationStep;
	u8 rotationTimer;
	s8 updateStep;
};
NTR_SIZE_GUARD(RedCoinRing, 0x4EC);
