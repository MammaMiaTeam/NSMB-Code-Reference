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

	enum class PauseMenuState : u8 {
		Opening = 0,
		Open,
		OnClosing,
		Closing
	};

	enum class SaveDialogState : u8 {
		Opening = 0,
		Open,
		Saving,
		Saved,
		Closing
	};

	enum class UpdateState : u32 {
		WorldEnter = 0,
		Worldmap,
		PauseMenu,
		SaveDialog,
		WorldTransition
	};

	enum class SubscreenState : u8 {
		Main = 0,
		SwipeMainOut,
		LoadOptions,
		SwipeOptionsIn,
		Open,
		OkPressed,
		OkReleased,
		OkUnfocused,
		SwipeOptionsOut,
		LoadWorldmapIcons,
		SwipeMainIn
	};

	enum class TextBoxType : u8 {
		PauseMenu = 0,
		SaveDialog,
		SaveDialog??,
		QuitDialog
	};

	Particle::Handler unk64;
	Vec2 unk858;
	u32 unk864;//Pending pause menu close
	u32 unk868;
	u32 unk86c;//starCoinCounter
	u32 unk870;//starCoinDecSoundRemaining
	u32 unk874;
	u32 unk878;
	u8 unk87c;//Menu option
	u8 unk87d;//Max menu option
	u8 unk87e;//Faded in?
	SaveDialogState unk87f;//Save Dialog state
	PauseMenuState unk880;//Pause Menu state
	u8 unk881;
	u8 unk882;
	u8 unk883;
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

	class IconAnimator
	{
	public:

		enum class Mode : u32 {
			WorldExit,
			SameWorld
			WorldEnter,
		};

		fx32 unk00;//Current scale
		u32 unk04;//Amplitude
		u32 unk08;//Angle
		u32 unk0c;//Countdown
		u32 unk10;//Enter stop delay (at 0x15 the oscillation stops if scale == 1.0)
		Mode unk14;//Mode

		//02190e38
		IconAnimator(Mode mode);

		//02190c6c
		void update();


	};

	//021ade5c
	static IconAnimator worldmapIconAnimator;

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


	//021ade74
	static Function updateStates[5];

	//021addb0
	static UpdateState currentUpdateState;

	//020cc2c0
	static SubscreenState currentSubscreenState;

	//021ade9c
	static Function subscreenUpdateStates[11];

	//021add8c
	static u32 subscreenUpdateStateFlags;//0x1: Initialized

	//021adef4
	static Function subscreenRenderStates[11];

	//021addb8
	static u32 subscreenRenderStateFlags;//0x1: Initialized

	//02085a10
	static bool challengeModeEnabled;

	typedef bool(*ChallengeModeStateFunction)();

	struct ChallengeModeState {
		ChallengeModeStateFunction function;
		const char* buttonName;
	};

	//021a53f4
	const char challengeModeButtonNameX[2];

	//021a53f8
	const char challengeModeButtonNameL[2];

	//021a53fc
	const char challengeModeButtonNameY[2];

	//021a5400
	const char challengeModeButtonNameR[2];

	//021a27bc
	ChallengeModeState challengeModeStates[8];

	//021add94
	u32 currentChallengeModeState;

	//021adda0
	static fx32 textBoxScale;

	//021addb4
	static void* textFile;

	//021adf4c
	static TextBox textBox;

	//021add78
	static u32 currentTextIndex;

	//021add34
	static TextBoxType textBoxType;

	//021add40
	static bool isGameCompleted;

	//021a5eac
	static u32 textIndices[2 * 4];

	//021a65b0
	static VecFx32 lightDirections[8];

	//021a5ecc
	static u32 worldmapMusicIDs[10];


	//02190eb8
	WorldmapScene();

	//D0:0218d3a4
	//D1:0218d36c
	virtual ~WorldmapScene() override;

	//0218f188
	virtual s32 onCreate() override;

	//0218f154
	virtual s32 onDestroy() override;

	//0218e9f4
	virtual s32 onUpdate() override;

	//0218eaec
	virtual void postUpdate(ReturnState state) override;

	//0218eb1c
	virtual s32 onRender() override;

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

	//0218e994
	void onUpdateWorldEnter();//State 0

	//0218e750
	void onUpdateWorldmap();//State 1

	//0218e034
	void onUpdatePauseMenu();//State 2

	//0218dcf0
	void onUpdateSaveDialog();//State 3

	//0218dbe8
	void onUpdateWorldTransition();//State 4, does nothing

	//0219029c
	void updateSubscreen();

	//02190148
	void updateWorldmapSubscreen();//State 0

	//021900c8
	void swipeMenuOut();//State 1 & 5-8

	//021900bc
	void loadOptionsMenu();//State 2

	//02190088
	void swipeMenuIn();//State 3 & 10

	//0219007c
	void updateOptionsMenu();//State 4

	//02190070
	void loadWorldmapIcons();//State 9

	//02190afc
	void renderSubscreen();

	//0219040c
	void renderOptionsMenu();

	//02190418
	void renderWorldmapSubscreen();

	//0218ff08
	static bool updateChallengeModeState(u32* currentState);

	//0218ffd4
	static void resetChallengeModeState(u32* currentState);

	//0218fef4
	static void resetChallengeModeState();

	//0218febc
	static bool isChallengeModeTriggered();

	//0218ffe0
	static bool isLPressed();

	//02190004
	static bool isRPressed();

	//02190028
	static bool isXPressed();

	//0219004c
	static bool isYPressed();

	//0218d5f0
	static FontString* setTextBox(u32 stringIndex, TextBox::Type type, void* bmg);

	//0218e6e0
	static void showPauseMenu();

	//0218dfac
	static void showSaveDialog();

	//0218dbec
	static void transitionToNextWorld();

	//0218dc58
	static u32 getNextWorldID(u32 currentWorld);

	//0218db2c
	static fx32 getLightDirectionX(u32 world);

	//0218db2c
	static fx32 getLightDirectionY(u32 world);

	//0218db2c
	static fx32 getLightDirectionZ(u32 world);

	//0218daec
	static u32 getWorldmapMusicID(u32 world);

	//0218d504
	static void fadeWorldmap(u16 sceneID, u32 settings);

	//0218d43c
	static u16 getWorldmapNodeCount(u32 world);

};


//vtable: 021a9040
class WorldmapActor : public Actor
{
public:

	//02199d58
	WorldmapActor();
};


#endif  // NSMB_WORLDMAP_INCLUDED
