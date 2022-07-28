#pragma once
#include "nitro_if.h"
#include "nsmb/util.h"
#include "nsmb/math/vector.h"


class StageActor;
class PlatformMgr;


enum class PlatformType : u8
{
	Rotating = 0,
	/* unk1 */
	Segment = 2,
	/* unk2 */
	Deforming = 4,	// used for tightropes
	RoundExternal,	// used by the giant wiggler
	RoundInternal,	// unused
};


class Platform {
public:

	Platform();
	virtual ~Platform();

	virtual void update();
	virtual void resolveCollision();
	virtual void func5();

	void reset();
	void link();
	void unlink();


	StageActor* owner;

	Platform* prev;
	Platform* next;
	PlatformMgr* manager;

	Vec2 pointEnd;
	Vec2 pointStart;
	Vec2 pointStep;
	Vec2 lastStart;

	fx32 length;
	fx32 force;

	s16 angle;
	u16 flags;

	PlatformType type;
	u8 unk51;
	bool linked;
	u8 layerID;

	u8 unk54[4];


	static Platform* listHead;
	static Platform* listTail;

};
NTR_SIZE_GUARD(Platform, 0x58);
