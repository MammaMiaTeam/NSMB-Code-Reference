#pragma once
#include "platformbase.h"


class StageActor;


class SegmentPlatform : public PlatformBase
{
public:

	Vec2 start;
	Vec2 end;

	sym SegmentPlatform() __body
	inline virtual ~SegmentPlatform() {}

	sym void init(StageActor* owner, const Vec2& a, const Vec2& b) __body
	sym void init(StageActor* owner, fx32 ax, fx32 ay, fx32 bx, fx32 by) __body

	sym void setPoints(const Vec2& a, const Vec2& b) __body
	sym void setPoints(fx32 ax, fx32 ay, fx32 bx, fx32 by) __body

	sym virtual void update() override __body
};
