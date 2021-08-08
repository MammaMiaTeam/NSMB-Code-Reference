#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"


class StageActor;
class PlatformBase;


class PlatformMgr {
public:

	// reference to parent
	StageActor* owner;

	// reference to parent's position vector
	Vec3* parentPos;

	// Platform list
	PlatformMgr* next;
	PlatformBase* prev; // WTF is going on here????
	PlatformBase* obj;

	// reference to CollisionMgr
	CollisionMgr* pCollMgr;

	// physics calculations
	Vec2 collisionPositionMaybe;
	u32 distance;
	u16 angle;
	u16 unk1;

	u8 unk2[4];

	PlatformMgr();
	virtual ~PlatformMgr();

};