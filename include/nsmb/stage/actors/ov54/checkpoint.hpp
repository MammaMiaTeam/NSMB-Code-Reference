#pragma once
#include "nsmb.hpp"
#include "checkpointflag.hpp"


// vtable at 0216FF70 (ov54)
class Checkpoint : public StageEntity
{
public:

	// D0: 02162020
	// D1: 02161FA4
	virtual ~Checkpoint();

	// 021621A8
	s32 onCreate() override;
	// 021620A4
	s32 onDestroy() override;
	// 021620C8
	s32 onRender() override;
	// 021620C4
	void onCleanupResources() override;
	// 02162314
	bool onPrepareResources() override;

	// 021620EC
	bool updateMain() override;

	// 021622AC
	bool checkPlayerInRange() const;

	// 0216236C
	static bool loadResources();

	static constexpr u16 ObjectID = 159;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 187;

	// 0216FF58
	static const ActorProfile profile;


	ModelAnm model;
	ProgressBarObject progBarObj;
	CheckpointFlag flag;

	u8 triggerDirection;
	bool collected;


#if NTR_EXT_EXISTS(Checkpoint)
	#include NTR_EXT_INCLUDE(Checkpoint)
#endif

};
#if !NTR_EXT_EXISTS(Checkpoint)
NTR_SIZE_GUARD(Checkpoint, 0x51C);
#endif


// vtable at 0216FF70 (ov54)
class VerticalCheckpoint : public Checkpoint // TODO Remove
{
public:

	static constexpr u16 ObjectID = 158;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 186;

	// 0216FF64
	static const ActorProfile profile;

};
NTR_SIZE_GUARD(VerticalCheckpoint, sizeof(Checkpoint));
