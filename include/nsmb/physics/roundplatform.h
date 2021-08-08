#pragma once
#include "platformbase.h"


class StageActor;


class RoundPlatform : public PlatformBase
{
public:

	Vec2 center;
	Vec2 unk64;
	Vec2 unk70;
	fx32 radius;
	fx32 unk80;
	fx32 unk84;
	s16 calcAngle;
	u8 unk8a;
	u8 unk8b;

	RoundPlatform();
	inline virtual ~RoundPlatform();

	void init(StageActor* actor, fx32 radius, fx32 centerX, fx32 centerY, fx32 uX, fx32 uY, s16 angle, s32 unk1, s32 unk2, bool externalCollision);

	virtual void update() override;
	virtual void resolveCollision() override;
	virtual void func5() override;
};
