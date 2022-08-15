#pragma once
#include "nsmb/math/vector.h"
#include "nsmb/graphics/2d/oam.h"


constexpr u32 EffectTypes = 25;


namespace EffectType {

	constexpr s8 Score100			= 0;
	constexpr s8 Score200			= 1;
	constexpr s8 Score400			= 2;
	constexpr s8 Score800			= 3;
	constexpr s8 Score1000			= 4;
	constexpr s8 Score2000			= 5;
	constexpr s8 Score4000			= 6;
	constexpr s8 Score8000			= 7;
	constexpr s8 Score1UP			= 8;
	constexpr s8 Score10			= 9;
	constexpr s8 GlitterStars1		= 10;
	constexpr s8 GlitterStars2		= 11;
	constexpr s8 GlitterStars3		= 12;
	constexpr s8 GlitterStars4		= 13;
	constexpr s8 GlitterPoof		= 14;
	constexpr s8 CollectedStar		= 15;
	constexpr s8 FallingStar		= 16;
	constexpr s8 DroppedStar		= 17;
	constexpr s8 FireballTrail		= 18;
	constexpr s8 Shine				= 19;
	constexpr s8 Star				= 20;
	constexpr s8 PipeShards			= 21;
	constexpr s8 BrickShards		= 22;
	constexpr s8 VolcanoDebris		= 23;
	constexpr s8 RedNumber			= 24;

}


class Effect;
using EffectFunction = void(Effect::*)();


struct EffectFunctions {

	EffectFunction initFunction;
	EffectFunction renderFunction;
	EffectFunction updateFunction;

};


class ChildEffect {
public:

	ChildEffect();
	~ChildEffect();

	u8 palette;
	u8 frame;
	u8 pad[2];
	Vec3 position;
	Vec3 velocity;

};
NTR_SIZE_GUARD(ChildEffect, 0x24);


class Effect {
public:

	Effect();
	virtual ~Effect();

	bool create(s8 id, const Vec3& pos, u32 settingA, u32 settingB, s8 playerID, u32 type);
	void update();
	void render();
	void disable();
	void switchUpdate(EffectFunction updateFunction);

	void applyGravity();
	void applyVelocity(const Vec3& velocity);
	void applyVelocity();

	void initPoints();
	void initGlitter();
	void initCard();
	void initFireballTrail();
	void initShine();
	void initStar();
	void initBricks();
	void initPipeShards();
	void initVolcanoDebris();
	void initRedNumber();

	void updatePoints();
	void updateGlitter();
	void updateDisplayCard();
	void updateFallingCard();
	void updateDroppedCard();
	void updateCardCollect();
	void updateFireballTrail();
	void updateShine();
	void updateBricks();
	void updatePipeShards();
	void updateVolcanoDebris();
	void updateRedNumber();

	void renderPoints();
	void renderGlitter();
	void renderCard();
	void renderFireballTrail();
	void renderShine();
	void renderStar();
	void renderBricks();
	void renderPipeShards();
	void renderVolcanoDebris();
	void renderRedNumber();

	static void incrementBrickCounter();
	static void decrementBrickCounter();

	EffectFunction renderFunction;
	EffectFunction updateFunction;
	OAM::Anim effectAnim;
	Vec3 position;
	Vec3 velocity;
	Vec3 targetVelocity;
	Vec3 scale;
	Vec3s rotation;
	fx32 gravity;
	u32 settingA;
	fx32 relativeX;
	fx32 relativeY;
	u32 unused88[2];
	s32 ticker;
	u32 palette;
	u32 unused98[2];
	s16 data[4];
	u16 settingB;
	s8 slot;
	bool active;
	s8 id;
	s8 updateStep;
	u8 life;
	s8 playerID;
	u32 type;
	ChildEffect pipeChildren[4];
	ChildEffect brickMeteorChildren[4];

};
NTR_SIZE_GUARD(Effect, 0x1D4);


class EffectHandler {
public:

	EffectHandler();
	virtual ~EffectHandler();

	bool init();
	void update();
	void render();
	bool spawn(s8 id, const Vec3& pos, u32 settingA, u16 settingB, s8 playerID, u32 type);
	void destroy(s8 slot);

	Effect effects[32];
	s8 slots[32];
	s8 effectCount;

};
NTR_SIZE_GUARD(EffectHandler, 0x3AA8);


namespace Effects {

	bool init();
	bool spawn(s8 id, const Vec3& pos, s8 playerID);
	bool spawn(s8 id, const Vec3& pos, u32 settingA, u16 settingB, s8 playerID, u32 type);
	void update();
	void render();
	void destroy(s8 slot);

	extern s16 activeBricks;
	extern EffectHandler* effectHandler;

}

