#pragma once
#include "nitro_if.h"


enum class WorldmapNodeType : u8 {
	Arrow = 0,
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	Level6,
	Level7,
	Level8,
	LevelA,
	LevelB,
	LevelC,
	GhostHouse,
	Tower1,
	Fortress,
	Pipe,
	Cannon,
	RedToadHouse,
	GreenToadHouse,
	YellowToadHouse,
	Fork,
	Tower2,
	FinalCastle,
	BlueToadHouse
};


struct WorldmapEntity {

	//Only work for those levels where the given type is enabled
	enum class Type : u8 {
		HammerBro = 0,
		FlyingBlock
	};

	u8 node;
	Type type;

};
