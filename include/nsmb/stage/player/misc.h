#pragma once
#include "nitro_if.h"


/*
*	TODO:
*	move in physics/pendulum.h (?)
*/


class Pendulum;


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
