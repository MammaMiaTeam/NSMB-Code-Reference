#pragma once

#include "nsmb_nitro.hpp"

struct StagePathNode {

	s16 x;
	s16 y;
	fx32 speed;
	fx32 accel;
	u16 delay;
	u16 flags;

};
NTR_SIZE_GUARD(StagePathNode, 0x10);

struct StagePath {

	u8 id;
	u16 nodeOffset;
	u16 nodeCount;
	u16 unk6;

};
NTR_SIZE_GUARD(StagePath, 0x8);

namespace Path {

}
