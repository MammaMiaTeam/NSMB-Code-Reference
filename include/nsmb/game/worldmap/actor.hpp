#pragma once

#include <nsmb/core/entity/actor.hpp>

//vtable: 020E9680 (overlay 8)
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

	//C1:020da398
	WorldmapActor();

	//D0:020d9dc8
	//D1:020da0b4
	virtual ~WorldmapActor() override;

	//020d8a0c
	virtual s32 onCreate() override;

	//020d81d0
	virtual s32 onDestroy() override;

	//020d6e30
	virtual s32 onUpdate() override;

	//020d7734
	virtual s32 onRender() override;

	//020d81cc
	virtual void onCleanupResources() override;

	//020e96bc
	virtual bool onPrepareResources() override;

	static constexpr u16 ObjectID = 319;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 293;

};
NTR_SIZE_GUARD(WorldmapActor, sizeof(Actor));
