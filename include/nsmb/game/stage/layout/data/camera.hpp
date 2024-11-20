#pragma once

#include <nsmb_nitro.hpp>

/*
	TODO: Solve naming convention with stage blocks

	# StageCamera block #

	If this follows the naming of other blocks then it will conflict with StageCamera (class inheriting from OrthoView).
	Naming it something else will break the stage blocks naming conventions (which simply follow the StageXXX namings).
	It has been temporarily named to StageCameraInfo to bypass compilation errors.

*/
struct StageCameraInfo {

	s32 topOffset;
	s32 bottomOffset;
	s32 topOffsetSpecial;
	s32 bottomOffsetSpecial;
	u16 id;
	u16 scrollHeight;
	u32 unk14;

};
NTR_SIZE_GUARD(StageCameraInfo, 0x18);
