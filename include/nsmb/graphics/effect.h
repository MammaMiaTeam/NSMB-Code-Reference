#pragma once
#include "nsmb/math/vector.h"
#include "nsmb/graphics/2d/oam.h"


class Effect;
typedef void(Effect::* EffectFunction)();


struct EffectFunctions {
	EffectFunction initFunction;
	EffectFunction renderFunction;
	EffectFunction updateFunction;
};


class ChildEffect {

public:

	sym ChildEffect() __body
	sym ~ChildEffect() __body

	u8 palette;
	u8 frame;
	u8 pad[2];
	Vec3 position;
	Vec3 velocity;

};


class Effect {

public:

	sym Effect() __body
	sym virtual ~Effect() __body

	bool create(s8 id, const Vec3& pos, u32 settingA, u32 settingB, s8 playerID, u32 type);
	void update();
	void render();
	void disable();
	void switchUpdate(EffectFunction updateFunction);

	void applyGravity();
	void applyVelocity(const Vec3& velocity);
	void applyVelocity();

	void initPoints();
	void initSparkles();
	void initCard();
	void initFireballTrail();
	void initShine();
	void initStar();
	void initBricks();
	void initPipeShards();
	void initMeteorDebris();
	void initRedNumber();

	void updatePoints();
	void updateSparkles();
	void updateDisplayCard();
	void updateFallingCard();
	void updateDroppedCard();
	void updateCardCollect();
	void updateFireballTrail();
	void updateShine();
	void updateBricks();
	void updatePipeShards();
	void updateMeteorDebris();
	void updateRedNumber();

	void renderPoints();
	void renderSparkles();
	void renderCard();
	void renderFireballTrail();
	void renderShine();
	void renderStar();
	void renderBricks();
	void renderPipeShards();
	void renderMeteorDebris();
	void renderRedNumber();

	static void incrementBrickCounter();
	static void decrementBrickCounter();

	EffectFunction renderFunction;
	EffectFunction updateFunction;
	OAM::Anim effectAnim;
	Vec3 position;
	Vec3 velocity;
	Vec3 minVelocity;
	Vec3 scale;
	Vec3s rotation;
	fx32 gravity;
	u32 settingA;
	u32 relativeX;
	u32 relativeY;
	u32 unused88[2];
	s32 ticker;
	u32 palette;
	u32 unused98[2];
	s16 data[4];
	u16 settingB;
	s8 slot;
	bool active;
	s8 id;
	s8 effectStep;
	u8 timer;
	s8 playerID;
	u32 type;
	ChildEffect pipeChildren[4];
	ChildEffect brickMeteorChildren[4];

	static s32 effectTableInitialized;
	static EffectFunctions effectTable[24];

};


class EffectHandler {

public:

	EffectHandler();
	virtual ~EffectHandler();

	bool valid() const;
	void update();
	void render();
	bool spawn(s8 id, const Vec3& pos, u32 settingA, u16 settingB, s8 playerID, u32 type);
	void destroy(s8 slot);

	Effect effects[32];
	s8 slots[32];
	s8 effectCount;

};


namespace Effects {

	bool valid();
	bool spawn(s8 id, const Vec3& pos, s8 playerID);
	bool spawn(s8 id, const Vec3& pos, u32 settingA, u16 settingB, s8 playerID, u32 type);
	void update();
	void render();
	void destroy(s8 slot);

	extern s16 activeBricks;
	extern EffectHandler* effectHandler;

}

