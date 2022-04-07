#pragma once
#include "platform.h"


class StageActor;


class DeformingPlatform : public Platform
{
public:

	// 0201b778
	DeformingPlatform();
	// D1:0201afec
	// D0:0201b02c
	inline virtual ~DeformingPlatform() {}

	// 0201b6d4
	void init(StageActor* owner, const Vec2& a, const Vec2& b, const Vec2& pt1, const Vec2& pt2);

	// 0201b67c
	void setPoints(const Vec2& a, const Vec2& b);

	// 0201b51c
	virtual void update() override;
	// 0201b514
	virtual void func5() override;

	Vec2 start;
	Vec2 end;
	Vec2 bendPoint1Abs;
	Vec2 bendPoint2Abs;
	Vec2 bendPoint1;
	Vec2 bendPoint2;

};
NTR_SIZE_GUARD(DeformingPlatform, 0xA0);
