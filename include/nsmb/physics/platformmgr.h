#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"


class StageActor;
class CollisionMgr;
class Platform;


class PlatformMgr {
public:

	// 0201DA00
	PlatformMgr();

	// D0: 0201D9B8
	// D1: 0201D9E4
	virtual ~PlatformMgr();


	// 0201D998
	void init(StageActor* owner, u8 groupID);
	// 0201D960
	void init(Vec3* position, u8 groupID);


	// 0201D954
	void setPlatform(Platform* platform);
	// 0201D940
	Platform* getPlatform();


	// 0201D834
	bool update(u32 unk1, u32 unk2, u32 unk3);


	// 0201D794
	void releasePlatform();
	// 0201D730
	void acquirePlatform();


	StageActor* owner;
	Vec3* linkedPosition;

	PlatformMgr* next;
	Platform* head;
	Platform* platform;

	CollisionMgr* linkedCollisionMgr;

	Vec2 collisionPositionMaybe;
	fx32 distance;
	s16 angle;
	u16 unk1;

	u8 groupID;
	u8 unk31;
	u8 unk32;
	u8 unk33;

};
NTR_SIZE_GUARD(PlatformMgr, 0x34);
