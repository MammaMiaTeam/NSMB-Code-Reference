#ifndef NSMB_WORLDMAP_INCLUDED
#define NSMB_WORLDMAP_INCLUDED

#include "Actor.h"


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


//vtable: 021a61ac
class WorldmapScene : public Scene
{
public:

	Particle::Handler unk64;
	Vec2 unk858;
	u32 unk864;
	u32 unk868;
	u32 unk86c;
	u32 unk870;
	u32 unk874;
	u32 unk878;
	u32 unk87c;
	u32 unk880;
	u32 unk884;

	struct PathStruct {
		u8 unk00;
		u8 unk01;//Star coin count
		u8 unk02;//Path flags? 0x2: Path star coin sign; !0xC = Path??? (0218d6b8)
		u8 unk03;
	};

	struct LevelStruct {
		void* unk00;
		u16 unk04;
		u8 unk06;
		WorldmapNodeType unk07;//Node type
		u16 unk08;//Level flags? 0x1: Level with star coins (or isLevel)
		u16 unk0a;
	};

	struct WorldStruct {

		LevelStruct* unk00;//Levels
		PathStruct* unk04;//Paths
		void* unk08;
		void* unk0c;
		void* unk10;
		void* unk14;
		void* unk18;
		void* unk1c;
		u16 unk20;//Node count
		u16 unk22;//Path count
		u32 unk24;

	};

	struct ShitStruct {
		u32 unk00;
		u32 unk04;
	};

	struct WorldPath {
		u32 world0;
		u32 world1;
		Save::CompletionFlags flags;
	};

	//021ade5c
	static LOL lol;

	class LOL {
	public:

		enum class Mode : u32 {
			WorldExit,
			WorldEnter,
			SameWorld
		};

		u32 unk00;
		u32 unk04;//Amplitude
		u32 unk08;//Angle << 4
		u32 unk0c;
		u32 unk10;
		Mode unk14;//Mode

		//02190e38
		LOL();


	};



	//021a67f8
	WorldPath worldPaths[9];

	//021a7384
	WorldStruct looooool[8];

	//021a60d4
	ShitStruct shit[8];

	//021a6e94
	LevelStruct w1Levels[0x13];

	//021a6f78
	LevelStruct w2Levels[0x14];

	//021a6b1c
	LevelStruct w3Levels[0x12];

	//021a6ccc
	LevelStruct w4Levels[0x13];

	//021a7264
	LevelStruct w5Levels[0x18];

	//021a7068
	LevelStruct w6Levels[0x15];

	//021a6bf4
	LevelStruct w7Levels[0x12];

	//021a6db0
	LevelStruct w8Levels[0x13];

	//021a6438
	PathStruct w1Paths[0x17];

	//021a6670
	PathStruct w2Paths[0x18];

	//021a6494
	PathStruct w3Paths[0x17];

	//021a63dc
	PathStruct w4Paths[0x17];

	//021a6a24
	PathStruct w5Paths[0x1E];

	//021a6790
	PathStruct w6Paths[0x1A];

	//021a66d0
	PathStruct w7Paths[0x18];

	//021a6384
	PathStruct w8Paths[0x16];


	//021a3080
	u32 wmPathMaskFiles[9];

	//021a305c
	u32 wmPathFiles[9];

	//021a8154
	u32 worldmapModelFiles[8][16];

	//021add50
	u8 worldStarCoinsCompleted;//Bitmask (1 << world)

	//021a53ec
	s8 nextWorld;//-1 if none pressed, else pressed icon = world

	//02190eb8
	WorldmapScene();


	//0218f188
	virtual s32 onCreate() override;

	//0218f154
	virtual s32 onDestroy() override;


	virtual s32 onUpdate();
	virtual void postUpdate(ReturnState state);
	virtual s32 onRender();

	//0218f150
	virtual void pendingDestroy() override;

	//0218d68c
	static void disableBowserJRAnimations(u32 lastWorld);//Disables all animations up to (including) lastWorld
	
	//0218d95c
	static u32 getStarCoinCount();

	//0218d880
	static u32 getStarCoinSpent();

	//0218d798
	static void checkLevelCompletion();

	//0218d6b8
	static void checkPathCompletion();

	//0218da60
	static void checkCompletion();

	//0219c9f8
	static u32 getWorldMapIndex(u32 worldID);

	//0219bbb8
	static u32 getWorldmapPathMaskFileID(u32 world);

	//0219bbd8
	static u32 getWorldmapPathFileID(u32 world);

	//0218fb04
	//EWWWWWWW

	//0218dbd4
	static u32 getWorldmapModelFile(u32 world, u32 index);

	//02191a6c
	static bool loadWorldmapModels();

	//0219ac4c
	static bool loadBowserJRPeachModels();

	//02190e38
	//IDK

	//0201ec88
	//Bitch do I look like I care? NO


};


#endif  // NSMB_WORLDMAP_INCLUDED
