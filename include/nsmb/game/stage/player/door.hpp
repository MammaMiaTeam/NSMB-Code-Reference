#pragma once

#include <nsmb_nitro.hpp>
#include <nsmb/core/math/vector.hpp>
#include <nsmb/core/graphics/3d/modelanm.hpp>

class Door {
public:
	struct AnimIDs
	{
		u32 open;
		u32 close;
	};

	Door();
	virtual ~Door();

	static bool loadModels();

	s32 init(bool isBossDoor);
	bool render();
	bool open();
	bool close();

	static u32 openSfxIDsForType[4];
	static u32 closeSfxIDsForType[4];
	static AnimIDs animIDsForType[4];

	ModelAnm model;
	AnimIDs* animIDs;
	Vec3 position;
	Vec3 scale;
	u32 modelFileID;
	u32 animFileID;
	u32 isBossDoor;
	u32 doorType;
	u32 isClosed;
	u32 animID;
};
