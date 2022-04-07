#pragma once
#include "platform.h"


class StageActor;


class SegmentPlatform : public Platform
{
public:

	SegmentPlatform();
	inline virtual ~SegmentPlatform() {}

	void init(StageActor* owner, const Vec2& a, const Vec2& b);
	void init(StageActor* owner, fx32 ax, fx32 ay, fx32 bx, fx32 by);

	void setPoints(const Vec2& a, const Vec2& b);
	void setPoints(fx32 ax, fx32 ay, fx32 bx, fx32 by);

	virtual void update() override;

	Vec2 start;
	Vec2 end;

};
NTR_SIZE_GUARD(SegmentPlatform, 0x70);
