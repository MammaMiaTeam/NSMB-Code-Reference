#pragma once

#include <nsmb/game/stage/entity3d.hpp>
#include <nsmb/game/physics/collider.hpp>

// vtable at 02125360 (ov10)
class SpinBlock : public StageEntity3D
{
public:

	using StateFunction = bool(SpinBlock::*)();


	// D0: 020D9F4C
	// D1: 020D9EBC
	virtual ~SpinBlock();

	// 020DA0E4
	s32 onCreate() override;
	// 020D9FE4
	s32 onDestroy() override;
	// 020DA300
	bool onPrepareResources() override;

	// 020DA000
	bool updateMain() override;

	// 020DA338
	void setModelCallback(NNSG3dSbcCallBackFunc cb);
	// 020DA360
	static void modelCallback(NNSG3dRS* rs);
	// 020DA3C0
	void setModelOwner(void* ptr);

	// 020DA6EC
	bool updatePlayerStanding();
	// 020DA6A0
	bool stepRotation(s16& dest, s16 target, s16 step);
	// 020DA554
	bool updateBoardSpin();
	// 020DA410
	bool updateBoardPosition();

	// 020DA91C
	bool switchState(const StateFunction& function);
	// 020DA8D4
	void updateState();

	// 020DA3C8
	bool mainState();

	// 020DA9CC
	static void bottomCollision(StageActor& self, StageActor& other);
	// 020DA9D0
	static void topCollision(StageActor& self, StageActor& other);

	// 020DA9A8
	static bool loadResources();

	static constexpr u16 ObjectID = 254;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 91;

	// 02125348
	static const ActorProfile profile;

	// 0212942C
	static const StateFunction sMain;


	Collider collider;
	ColliderInfo colliderInfo;

	const StateFunction* updateFunction;

	Vec3 colliderScale;

	fx32 boardTransX;
	fx32 boardTransY;
	fx32 boardTransZ;
	s32 spinAccel;
	fx32 boardY;
	s32 spinStep;
	bool spinningFast;
	s8 activePlayerIDs[2];
	s8 activePlayerCooldowns[2];
	s8 updateStep;


#if NTR_EXT_EXISTS(SpinBlock)
	#include NTR_EXT_INCLUDE(SpinBlock)
#endif

};
#if !NTR_EXT_EXISTS(SpinBlock)
NTR_SIZE_GUARD(SpinBlock, 0x55C);
#endif


// vtable at 02125598 (ov24)
class SpinBlock255 : public SpinBlock
{
public:

	// D0: 020DABF0
	// D1: 020DAB54
	virtual ~SpinBlock255() {}

	static constexpr u16 ObjectID = 255;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 92;

	// 0212533C
	static const ActorProfile profile;


#if NTR_EXT_EXISTS(SpinBlock255)
	#include NTR_EXT_INCLUDE(SpinBlock255)
#endif

};
#if !NTR_EXT_EXISTS(SpinBlock255)
NTR_SIZE_GUARD(SpinBlock255, sizeof(SpinBlock));
#endif


// vtable at 0212547C (ov24)
class SpinBlock256 : public SpinBlock
{
public:

	// D0: 020DAD30
	// D1: 020DAC94
	virtual ~SpinBlock256() {}

	static constexpr u16 ObjectID = 256;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 93;

	// 02125354
	static const ActorProfile profile;


#if NTR_EXT_EXISTS(SpinBlock256)
	#include NTR_EXT_INCLUDE(SpinBlock256)
#endif

};
#if !NTR_EXT_EXISTS(SpinBlock256)
NTR_SIZE_GUARD(SpinBlock256, sizeof(SpinBlock));
#endif
