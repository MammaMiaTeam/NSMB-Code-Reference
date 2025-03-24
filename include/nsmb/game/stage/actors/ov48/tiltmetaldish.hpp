#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/game/physics/rotatingplatform.hpp>
#include <nsmb/core/graphics/3d/model.hpp>

class TiltMetalDish : public StageEntity {
public:

	enum ModelID {
		Chain,
		Dish
	};

	using StateFunction = bool(TiltMetalDish::*)();


	virtual ~TiltMetalDish();

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	bool onPrepareResources() override;

	bool updateMain() override;

	s32 getTiltAccelFromAngle() const;
	void updateBalance();
	void attenuateTiltAngle();
	void attenuateChainWobble();
	void updateChainWobble();
	void getEnds(fx32& left, fx32& right);

	bool switchState(StateFunction function);
	void updateState();

	bool mainState();


	static bool loadResources();


	static constexpr u16 ObjectID = 169;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 208;

	static const ActorProfile profile;
	static const u16 tiltAngleLimits[4];


	StateFunction updateFunction;

	Model models[2];

	RotatingPlatform platform;

	fx32 originalY;

	fx32 wobbleOffset;
	fx32 wobbleVelocity;
	fx32 wobbleAccel;

	s16 tiltAngle;
	u16 tiltAngleLimit;

	s8 updateStep;

	s8 tiltAccel;
	s8 tiltVelocity;


#if NTR_EXT_EXISTS(TiltMetalDish)
	#include NTR_EXT_INCLUDE(TiltMetalDish)
#endif

};
#if !NTR_EXT_EXISTS(TiltMetalDish)
NTR_SIZE_GUARD(TiltMetalDish, 0x5A4);
#endif
