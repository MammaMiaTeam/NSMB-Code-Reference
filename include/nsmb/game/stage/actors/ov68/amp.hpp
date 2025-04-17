#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/modelanm.hpp>
#include <nsmb/core/graphics/3d/animationctrl.hpp>

// vtable at 0217942C (ov68)
class Amp : public StageEntity
{
public:

	// The argument is unused
	using StateFunction = bool(Amp::*)(void*);

	// D0: 021785D4
	// D1: 0217853C
	virtual ~Amp();

	// 02178918
	s32 onCreate() override;
	// 02178680
	s32 onRender() override;
	// 02178674
	s32 onDestroy() override;
	// 0217867C
	void onCleanupResources() override;
	// 02178A94
	bool onPrepareResources() override;

	// 021788F4
	bool updateMain() override;

	// 0217882C
	void damagePlayer(ActiveCollider& self, Player& player) override;


	// 02178DC4
	bool switchState(StateFunction function, void* arg);
	// 02178D5C
	void updateState(void* arg);

	// 02178D24
	void updateBobbing();

	// 02178C78
	bool idleState(void* arg);
	// 02178B9C
	bool electrocuteState(void* arg);

	// 02178EA8
	static bool loadResources();

	static constexpr u16 ObjectID = 110;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 128;

	// 02179420
	static const ActorProfile profile;
	
	static const AcConfig acConfig;


	ModelAnm bodyModel;
	Model effectModel;
	AnimationCtrl effectPattern;
	Animation effectAnimation;

	StateFunction updateFunction;

	AcConfig currentAcConfig;

	s16 bobPosition;
	u8 bobTimer;
	u8 freezeTimer;

	s8 updateStep;


#if NTR_EXT_EXISTS(Amp)
	#include NTR_EXT_INCLUDE(Amp)
#endif

};
#if !NTR_EXT_EXISTS(Amp)
NTR_SIZE_GUARD(Amp, 0x5A4);
#endif
