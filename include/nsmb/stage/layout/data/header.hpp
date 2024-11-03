#pragma once

#include "nsmb_nitro.hpp"

enum class StageSettings : u16 {
	StartAsMini = 0x1,
	MiniPhysics = 0x2,
	PipeCannonExistDistMod = 0x8,
	WrapAround = 0x20
};
NTR_CREATE_BITMASK_ENUM(StageSettings);

enum class StageMegaDropChance : u16 {
	OneInThree,
	OneInTwo,
	None
};

struct StageHeader {

	u8 entrances[2];
	StageSettings settings;
	u16 timer;
	u16 backgroundTheme[3];
	u16 tilesetTheme[3];
	u16 foregroundTheme[3];
	u16 events;
	u16 soundGroup;
	u16 spritePriority;
	StageMegaDropChance megaDropChance;

};
NTR_SIZE_GUARD(StageHeader, 0x20);
