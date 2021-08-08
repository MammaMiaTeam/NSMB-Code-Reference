#pragma once
#include "nitro_if.h"


/*
*	TODO:
*	move in physics/pendulum.h (?)
*/


class PendulumBase;


class PendulumController
{
public:

	Player* owner;

	PendulumController* unk4;
	PendulumBase* unk8;
	PendulumBase* unkC;

	u32 unk10;
	u32 unk14;
	u8 unk18;
	u8 unk19;
	u8 unk1A;
	u8 unk1B;

};


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
