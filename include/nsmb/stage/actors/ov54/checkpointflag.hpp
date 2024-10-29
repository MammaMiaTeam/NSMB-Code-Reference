#pragma once
#include "nsmb.hpp"


class CheckpointFlag
{
public:

	// C2: 02162628
	CheckpointFlag();

	inline ~CheckpointFlag() {}

	// 021624BC
	bool update();
	// 021623A0
	void render();


	ModelAnm* linkedModel;

	ArcFunction jumpArc;

	Vec3 position;
	Vec3 scale;

	s32 waitTimer;
	s16 rotation;
	bool visible;
	u8 unused57;
	bool shrinkFlag;


	#include NTR_EXT_INCLUDE(CheckpointFlag)

};
#if !NTR_HAS_EXT(CheckpointFlag)
NTR_SIZE_GUARD(CheckpointFlag, 0x5C);
#endif
