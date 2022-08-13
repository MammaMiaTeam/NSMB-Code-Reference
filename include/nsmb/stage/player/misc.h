#pragma once
#include "nitro_if.h"


class ProgressBarObject
{
public:

	StageActor* owner;
	void* progressPath; // StagePath*

	s32 unk8; // prev distance
	u32 unkC;
	u32 unk10;
	u32 unk14;

	u8 unk18;
	u8 unk19;
	u8 viewID;
	u8 unk1B;

	u32 unk1C;

};
NTR_SIZE_GUARD(ProgressBarObject, 0x20);

/*
*	TODO:
*	move in physics/pendulum.h (?)
*/

class PendulumController;

class Pendulum
{
public:

	virtual ~Pendulum();

	StageActor* owner;

	Pendulum* prev;
	Pendulum* next;
	PendulumController* activeController;

	fx32 length;
	fx32 velocityX;
	s16 angleDiff;
	u16 unk1E;
	u8 type;
	bool linked;
	u8 groupID;
	u8 flags;
	u8 dirFlags;
	u8 unk25;

};
NTR_SIZE_GUARD(Pendulum, 0x28);


class PolePendulum : public Pendulum
{
public:

	Vec2 unk28;
	Vec2 unk34;
	Vec2 origin;
	fx32 top;
	fx32 bottom;
	u32 unk58;
	s16 rotation;
	u16 unk5A;

};
NTR_SIZE_GUARD(PolePendulum, 0x5C);


class PendulumController
{
public:

	StageActor* owner;

	PendulumController* nextController;
	Pendulum* grabbedPendulum;
	Pendulum* attachedPendulum;

	fx32 grabHeight;
	fx32 segmentRestore;
	u8 unk18;
	u8 filterID;
	u8 grabbedSegment;
	u8 detachedTimer;

};
NTR_SIZE_GUARD(PendulumController, 0x1C);


// vtable at 0212F71C (ov11)
class VictoryState
{
public:

	VictoryState();
	virtual ~VictoryState();

	Vec3 target;

};
NTR_SIZE_GUARD(VictoryState, 0x14);


// vtable at 02126B6C (ov10)
class SpinState
{
public:

	SpinState();
	virtual ~SpinState();

	Vec3 position;
	int offset;
	int sideVelocity;
	u16 rotationTimer;
	u16 unk1E;
	bool spinning;
	bool enable; // maybe?
	u8 direction;

};
NTR_SIZE_GUARD(SpinState, 0x24);


// vtable at 02128464 (ov10)
class JumpState {
public:

	JumpState();
	JumpState(fx32 force, bool triggerSFX, bool noConsecutive, bool allowZeroForce, s8 variation);
	virtual ~JumpState();

	fx32 force;
	bool triggerSFX;
	bool noConsecutive;
	bool allowZeroForce;
	s8 variation;

};


// vtable at 02128474 (ov10)
class SpinJumpState {
public:

	SpinJumpState();
	SpinJumpState(fx32 force, s16 spinForce, bool triggerSFX);
	virtual ~SpinJumpState();

	fx32 force;
	s16 spinForce;
	bool triggerSFX;

};
