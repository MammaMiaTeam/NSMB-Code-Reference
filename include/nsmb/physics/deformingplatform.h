#pragma once
#include "platformbase.h"


class StageActor;


class DeformingPlatform : public PlatformBase
{
public:

	Vec2 start;
	Vec2 end;
	Vec2 bendPoint1Abs;
	Vec2 bendPoint2Abs;
	Vec2 bendPoint1;
	Vec2 bendPoint2;

	// 0201b778
	sym DeformingPlatform() __body
	// D1:0201afec
	// D0:0201b02c
	inline virtual ~DeformingPlatform() {}

	// 0201b6d4
	sym void init(StageActor* owner, const Vec2& a, const Vec2& b, const Vec2& pt1, const Vec2& pt2) __body

	// 0201b67c
	sym void setPoints(const Vec2& a, const Vec2& b) __body

	// 0201b51c
	sym virtual void update() override __body
	// 0201b514
	sym virtual void func5() override __body
};
