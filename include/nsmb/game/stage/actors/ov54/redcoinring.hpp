#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/model.hpp>
#include <nsmb/core/graphics/3d/animation.hpp>

// vtable at 0216CD9C (ov54)
class RedCoinRing : public StageEntity
{
public:
	using StateFunction = bool(RedCoinRing::*)();

	// D0: 02152F90
	// D1: 02152EDC
	virtual ~RedCoinRing();

	s32 onCreate() override; // 02153174
	s32 onDestroy() override; // 0215304C
	s32 onRender() override; // 02153058

	void onCleanupResources() override; // 02153054
	bool onPrepareResources() override; // 021533FC
	bool updateMain() override; // 02153150

	void updateDistance(u32 playerID); // 021532BC
	bool checkCollided(u32 playerID); // 02153370
	bool loadResources(); // 02153498
	bool collectedState(); // 021534CC
	void easeRotation(s16& value, s16 endValue, s16 step); // 021535CC
	bool waitCollectState(); // 02153604
	void updateState(); // 02153804
	bool switchState(StateFunction function); // 02153860

	// 02153954
	static RedCoinRing* construct();

	static constexpr u16 ObjectID = 151;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 175;

	static ActorProfile profile; // 0216CD90

	static StateFunction sWaitCollect; // 0216CD80
	static StateFunction sCollected; // 0216CD88

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
