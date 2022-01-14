#pragma once
#include "nitro_if.h"
#include "nsmb/stage/actor.h"


// TODO
class StageLayout : public StageActor
{
public:

	// 020af30c
	void changeTile(u32 x, u32 y, u32 id);

	// 020af8f0
	u32 getTileBehavior(u32 x,u32 y, s32 playerNo);

	// 020b0308
	u32 getChunkID(u32 x,u32 y);

	// 020afa30
	void readTileBehavior(u16 tileID);
};


namespace Stage
{
	// 0212944c
	extern u8 questionBlockFrame;

	// 0212943c
	extern u8 brickBlockFrame;

	// 0212f180
	extern GXOamAttr* anmTilesOamTable[23];

	// 020cad40
	extern StageLayout* stageLayout;
}
