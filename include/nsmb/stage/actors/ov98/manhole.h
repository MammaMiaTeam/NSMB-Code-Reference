#pragma once
#include "nsmb.h"


// vtable at 0218987C (ov98)
class Manhole : public StageEntity
{
public:

	enum class CollisionType
	{
		None,
		Player,
		GroundPound,
	};

	// The argument is unused
	using StateFunction = bool(Manhole::*)(void*);

	// D0: 021889AC
	// D1: 02188920
	virtual ~Manhole();

	// 02188B4C
	s32 onCreate() override;
	// 02188AA0
	s32 onRender() override;
	// 02188A7C
	s32 onDestroy() override;
	// 021892A0
	bool onPrepareResources() override;

	// 02188B10
	bool updateMain() override;

	// 021891CC
	bool switchState(StateFunction function, void* arg);
	// 02189198
	void updateState(void* arg);

	// 02188F0C
	bool solidState(void* arg);
	// 02188DC4
	bool rollForwardState(void* arg);
	// 02188C88
	bool rollBackwardState(void* arg);


	// 021890D8
	void updateRollingSound();
	// 02189150
	CollisionType getPlatformCollision();

	// 021892D8
	static bool loadResources();

	// 02188A40
	static void activeCallback(ActiveCollider& self, ActiveCollider& other);

	static constexpr u16 objectID = 187;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 233;

	// 02189870
	static const ActorProfile profile;

	// 02189358
	static const ActiveColliderInfo activeColliderInfo;


	StateFunction updateFunction;
	Model model;
	RotatingPlatform platform;

	fx32 roll;
	u16 rollAngle;
	u16 rollAmplitude;
	s16 lastRotationX;

	s8 updateStep;

	bool playerJumping;
	bool playerGroundPounding;
	u8 rollTimer;
	bool playerStanding;

};
NTR_SIZE_GUARD(Manhole, 0x50C);
