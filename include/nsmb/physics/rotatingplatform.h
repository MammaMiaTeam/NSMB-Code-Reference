#pragma once
#include "platform.h"


class StageActor;


struct RotatingPlatformInfo {
	fx32 x;
	fx32 y;
	fx32 height;
	fx32 right;
	fx32 left;
	s16 angle;
	u8 unused;
};


class RotatingPlatform : public Platform
{
public:

	RotatingPlatform();
	inline virtual ~RotatingPlatform() {}

	void init(StageActor* owner, fx32 x, fx32 y, fx32 height, fx32 right, fx32 left, s16 angle, u8 layerID, const Vec3* scale = nullptr);
	void init(StageActor* owner, const RotatingPlatformInfo& info, const Vec3* scale = nullptr);

	void setHeight(fx32 height, fx32 scale);
	void setRight(fx32 right);
	void setLeft(fx32 left);
	void setBase(fx32 left, fx32 right);

	virtual void update() override;

	Vec2 center;
	fx32 height;
	fx32 right;
	fx32 left;

};
NTR_SIZE_GUARD(RotatingPlatform, 0x70);
