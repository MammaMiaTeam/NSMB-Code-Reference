#pragma once
#include "nitro_if.h"


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


class SpinState
{
public:

	Vec3 position;
	int offset;
	int sideVelocity;
	u16 rotationTimer;
	u16 unk1E;
	bool spinning;
	bool enable; // maybe?
	u8 direction;

	// 02
	SpinState();

	// D0:
	// D1:
	virtual ~SpinState();

};
NTR_SIZE_GUARD(SpinState, 0x24);


class Class212f724
{
public:

	Vec3 unk0;

	// 0212b1a8
	Class212f724();

	// D0: 0212b160
	// D1: 0212b18c
	virtual ~Class212f724();

};
NTR_SIZE_GUARD(Class212f724, 0x14);


class ProgressBarObject
{
public:

	StageActor* owner;
	void* progressPath; // LevelPath*

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
