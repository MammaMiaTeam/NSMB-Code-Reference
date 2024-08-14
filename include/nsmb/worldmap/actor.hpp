#pragma once
#include "nsmb/entity/actor.hpp"


//vtable: 021a9040
class WorldmapActor : public Actor
{
public:

	enum class UpdateStates : u32 {
		Idle = 0,
		a,
		Walking,
		//...
		//6
		LevelEnter = 6,
		EntityMoving,
		//9
		LevelUnlocking = 9,
		//C
		CameraScroll = 12,
		CameraRevert,
		//10
		StarcoinSignRemoved = 16,
		StarcoinSignWaiting,
	};

	//C1:02199d58
	//C3:0219ab98
	WorldmapActor();

	//D0:02199788
	//D1:02199a74
	virtual ~WorldmapActor() override;

	//021983cc
	virtual s32 onCreate() override;

	static constexpr u16 ObjectID = 319;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 293;

};
NTR_SIZE_GUARD(WorldmapActor, sizeof(Actor));
