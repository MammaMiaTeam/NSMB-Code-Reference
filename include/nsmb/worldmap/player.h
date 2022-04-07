#pragma once
#include "nsmb/player/model.h"


//vtable 021a9530
class WorldmapPlayerModel
{
public:

	struct ModelConfig {
		s8 sizeIndex;
		s8 texPalette;
	};

	struct WMAnimation {
		u32 animFileID;
		u32 animIndex;			//NSBCA animation index
		fx32 speed;
		FrameCtrl::Type type;
		u32 unknown;
		u32 headAnimID;
	};

	enum class WMPowerupState : s8 {
		Small = 0,
		Super,
		Fire,
		Unused0,	//Identical to Small
		Shell,
		Unused1		//Identical to Super
	};

	enum class AnimationType : u32 {
		Idle = 0,
		Walk,
		Run,
		Pipe,
		CourseEnter,
		CoinCompleted
	};

	PlayerModel model;				//Player model
	ModelConfig* config;			//Configuration for the model depending on powerup state
	AnimationType animID;			//Current main animation ID
	u32 headAnimID;					//Current head animation ID
	u8 playerID;					//Player ID
	s8 sizeState;					//Size: 0=standard,1=small
	WMPowerupState powerupState;	//Current powerup state

	
	//021a39d0
	static WMAnimation animations[6];

	//021a39bc
	static u32 idleAnimationIDs[2];		//Not applicable to size state 1

	//021a39b4
	static u32 walkAnimationIDs[2];

	//021a39ac
	static u32 runAnimationIDs[2];

	//021a39c4
	static ModelConfig modelConfigs[6];


	//0219d710
	WorldmapPlayerModel();

	//D0:0219d6c0
	//D1:0219d6ec
	virtual ~WorldmapPlayerModel();

	//0219d5e8
	bool create(u8 playerID, s8 playerPowerup, u32 animID);

	//0219d574
	void render(MtxFx43* modelMatrix, Vec3* scale);

	//0219d550
	void update(bool skip);

	//0219d440
	void setAnimation(AnimationType animID, bool continueAnimation);

	//0219d3b8
	void setHeadAnimation(u32 headAnimID);

	//0219cbdc
	static bool loadFiles();

};
NTR_SIZE_GUARD(WorldmapPlayerModel, 0x3D8);
