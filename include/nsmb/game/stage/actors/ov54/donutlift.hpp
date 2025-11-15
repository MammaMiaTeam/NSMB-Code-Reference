#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/game/physics/collider.hpp>

// vtable at 02170560 (ov54)
class DonutLift : public StageEntity {
public:

	using StateFunction = bool(DonutLift::*)();

	// D1: 0216705c
	// D0: 021670cc
	virtual ~DonutLift();

	// 02167208
	s32 onCreate() override;
	// 02167164
	s32 onRender() override;
	// 02167144
	s32 onDestroy() override;

	// 021671bc
	bool updateMain() override;
	// 02167160
	void updateAnimation() override; // does nothing

	// 02167414
	void tryTileSwap(); // if player gets off donut lift before it can activate, the actor is destroyed and replaced with the tile

	// 02167524
	void updateState();
	// 0216756c
	bool switchState(const StateFunction& function);

	// 0216732c
	bool mainState();

	// 021674ec
	static ColliderCallback topColliderCallback;

	static constexpr u16 ObjectID = 71;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 83;

	// 02170538
	static const ActorProfile profile;

	// 02170544
	static const ColliderInfo colliderInfo;

	// 0217261c
	static const StateFunction sMain;

	// 0216f748
	static const GXOamAttr sprite;


	const StateFunction* updateFunction;

	Collider collider;
	const Vec3 colliderScale;

	fx32 offsetX; // flicks between 0 and 1fx and added to the sprite draw position to make a shaking effect

	u16	fallCountdown; // counts down to when the lift should fall
	u16	destroyCountdown; // once no player is on lift, counts down to when actor should be swapped with a tile

	s8 topTouchPlayerID[2]; // for each playerID: set to playerID if player touching top, otherwise -1

	u8 align47E; // alignment
	u8 align47F;

	s8 updateStep;
	
	u8 align481; // alignment
	u8 align482;
	u8 align483;

#if NTR_EXT_EXISTS(DonutLift)
	#include NTR_EXT_INCLUDE(DonutLift)
#endif

};
#if !NTR_EXT_EXISTS(DonutLift)
NTR_SIZE_GUARD(DonutLift, 0x484);
#endif
