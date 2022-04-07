#pragma once
#include "nsmb/graphics/3d/modelanm.h"
#include "nsmb/graphics/3d/animationctrl.h"


class WorldmapEntityModel
{
public:

	enum class Type : u32 {
		HammerBro = 0,
		FlyingBlock
	};


	ModelAnm entityModel;				//Model of the given entity
	AnimationCtrl patternAnimation;		//Pattern animation for FlyingBlock
	Model linkModel;					//Model for Hammer/Map Shadow
	AnimationCtrl shadowAnimation;		//Shadow animation for FlyingBlock
	Type type;							//Type of the entity


	//021ae1a0
	static u32 shadowAnimations[2];

	//021ae1a8
	static u32 entityAnimations[2][2];//Type & ID

	//021ae19c
	static u16 texPaletteBase;

	//021a2814
	static u16 texPaletteOffset[2];

	//021a9300
	static u32 resourceFileIDs[2][2];//Type & Model/Animation


	//0219bb7c
	WorldmapEntityModel();

	//D0:0219bafc
	//D1:0219bb40
	virtual ~WorldmapEntityModel();

	//0219b9a0
	bool create(Type type);

	//0219b7b8
	void render(MtxFx43* modelMatrix, Vec3* scale, Vec3* relPos);//relPos only used by Flying Block (and even there only Y)

	//0219b790
	void update();

	//0219b720
	void setAnimation(u32 animID);

	//0219b648
	static bool loadFiles();

};
NTR_SIZE_GUARD(WorldmapEntityModel, 0x198);
