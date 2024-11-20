#pragma once

#include <nsmb/core/graphics/3d/modelanm.hpp>
#include <nsmb/core/math/arcfunction.hpp>

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


#if NTR_EXT_EXISTS(CheckpointFlag)
	#include NTR_EXT_INCLUDE(CheckpointFlag)
#endif

};
#if !NTR_EXT_EXISTS(CheckpointFlag)
NTR_SIZE_GUARD(CheckpointFlag, 0x5C);
#endif
