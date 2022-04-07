#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"
#include "nsmb/graphics/2d/oam.h"


class Fireball {

public:

	typedef void (Fireball::* UpdateState)();

	UpdateState state;

	Vec3 position;
	Vec3 spawnPosition;
	Vec3 velocity;
	Vec3 scale;
	Vec3s unk4C;

	OAM::Anim anim;
	u32 unk70[4];

	bool active;
	u8 playerNo;
	u8 unk82;
	u8 stateID;
	u8 unk84;
	u8 unk85;
	u8 id;
	u8 unk87;
	u8 viewID;

	// 
	Fireball();

	// D0
	// D1
	virtual ~Fireball();

};
NTR_SIZE_GUARD(Fireball, 0x8C);


class FireballHandler {

public:

	Fireball fireballs[16];

	// 
	FireballHandler();

	// D0
	// D1
	virtual ~FireballHandler();

};
NTR_SIZE_GUARD(FireballHandler, 0x8C4);


namespace Game {

	// 02129484
	extern FireballHandler* fireballHandler;

}
