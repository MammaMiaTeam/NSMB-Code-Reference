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


class PlatformBase {
public:
	// reference to parent
	StageActor* owner;

	// list
	struct {
		PlatformBase* prev;
		PlatformBase* first;
	} list;

	// reference to parent's PlatformMgr
	PlatformMgr* manager;

	// physics calculations
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
	u8 groupID;

	u8 unk54[4];

	sym PlatformBase() __body
	sym virtual ~PlatformBase() __body

	sym virtual void update() __body
	sym virtual void resolveCollision() __body
	sym virtual void func5() __body

	sym void reset() __body
	sym void link() __body
	sym void unlink() __body
};