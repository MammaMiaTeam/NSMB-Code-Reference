#pragma once

#include <nsmb/game/stage/actor.hpp>

// TODO
class StageLayout : public Object
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

	// 020B7FE4
	void animateQuestionBlocks();

	// 020B807C
	void animateBrickBlocks();

	// 020B8364
	void animateCoins(u8 frame);

	// 020cac98
	static bool doLayoutReset;


	u8 unk5C[0xA8CC];

};
NTR_SIZE_GUARD(StageLayout, 0xA928);


namespace Stage
{
	// 0212f180
	extern GXOamAttr* anmTilesOamTable[23];

	// 020cad40
	extern StageLayout* stageLayout;
}