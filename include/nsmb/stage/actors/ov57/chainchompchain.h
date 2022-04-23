#pragma once
#include "nsmb.h"


class ChainChompChainLink
{
public:

	using StateFunction = void(ChainChompChainLink::*)();


	// C2: 021754AC
	inline ChainChompChainLink() {}

	// D2: 02173C50
	inline ~ChainChompChainLink() {}

	// 02173194
	void create();
	// 02173140
	void update();
	// 021730D8
	void explode();

	// 021731FC
	void idleState();
	// 021731C0
	void moveState();


	StateFunction updateFunction;

	Vec3 origin;
	Vec3 position;
	Vec2 velocity;

	fx32 offsetY;

};
NTR_SIZE_GUARD(ChainChompChainLink, 0x38);

class ChainChompChain
{
public:

	using StateFunction = void(ChainChompChain::*)(const Vec3&);


	// 021734EC
	void create(const Vec3& origin);
	// 0227ADF0
	void update(const Vec3& position);
	// 021733F0
	void render();
	// 021733C0
	void tighten();
	// 02173248
	void loosen(const Vec3& position);
	// 02173200
	void explode();
	// 02173A34
	bool prepareModel();
	// 02173A74
	void loadModel();

	// 02173654
	Vec3 getLinkPosition(u8 index) const;
	// 021739B0
	void updateLinkGravity(const Vec3& position);
	// 02173954
	void updateLinkDistance(const Vec3& position, fx32 length);

	// 02173790
	void pulledState(const Vec3& position);
	// 021736B8
	void tightState(const Vec3& position);
	// 0217368C
	void defaultState(const Vec3& position);
	// 021735A0
	void looseState(const Vec3& position);
	// 0217359C
	void explodeState(const Vec3& position);


	// 021754CC
	static const fx32 defaultLinkScale;
	// 021754D0
	static const fx32 defaultLooseDistance;


	StateFunction updateFunction;

	Vec3 origin;

	ChainChompChainLink links[7];
	Vec2 linkPositions[32];
	Model linkModel;

	u32 visible;

	Vec3 linkScale;

	fx32 looseDistanceY;
	fx32 reboundStrength;
	u16 reboundTimer;
	u8 positionIndex;


};
NTR_SIZE_GUARD(ChainChompChain, 0x3D0);
