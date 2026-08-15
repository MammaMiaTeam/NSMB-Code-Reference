#pragma once

#include "common.hpp"
#include <nsmb/core/entity/scene.hpp>
#include <nsmb/core/graphics/2d/font.hpp>
#include <nsmb/core/graphics/particle.hpp>
#include <nsmb/core/system/save.hpp>

//vtable: 020E67EC (overlay 8)
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
		//SaveDialog??,
		QuitDialog = 2
	};

	static constexpr u16 ObjectID = 9;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 294;

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

	struct LmaoStruct {
		u8 unk00;
		u8 unk01;//Target path
		u16 unk02;//Flags? 0x10=pipe?,0x3->index into button mapping
	};

	struct PathStruct {
		u8 unk00;
		u8 unk01;//Star coin count
		u8 unk02;//Path flags? 0x2: Path star coin sign; !0xC = Path??? (0218d6b8)
		u8 unk03;
	};

	struct NodeStruct {
		LmaoStruct* unk00;
		u16 unk04;
		u8 unk06;
		WorldmapNodeType unk07;//Node type
		u16 unk08;//Level flags? 0x1: Level with star coins (or isLevel)
		u16 unk0a;
	};

	struct EntitySpawnSettings {
		WorldmapEntity entitySpawns[2];
	};

	struct MapPointStruct {
		u32 unk00;
		u32 unk04;
		u32 unk08;
		s32 x;
		s32 y;
		s32 z;
	};

	struct WorldStruct {

		NodeStruct* unk00;//Levels
		PathStruct* unk04;//Paths
		EntitySpawnSettings* unk08;//Entity spawns
		MapPointStruct* unk0c;//Map points
		void* unk10;
		void* unk14;
		void* unk18;
		void* unk1c;
		u16 unk20;//Node count
		u16 unk22;//Path count
		u32 unk24;

	};

	struct LevelStruct {
#pragma warning LevelStruct not defined!!!
	};

	struct WorldPath {
		u32 world0;
		u32 world1;
		MainSave::CompletionFlags flags;
	};

	class IconAnimator
	{
	public:

		enum class Mode : u32 {
			WorldExit,
			SameWorld,
			WorldEnter,
		};

		fx32 unk00;//Current scale
		u32 unk04;//Amplitude
		u32 unk08;//Angle
		u32 unk0c;//Countdown
		u32 unk10;//Enter stop delay (at 0x15 the oscillation stops if scale == 1.0)
		Mode unk14;//Mode

		IconAnimator(Mode mode);

		void update();
	};

	//0x020ee49c
	static IconAnimator worldmapIconAnimator;

	//0x020e6e38
	static WorldPath worldPaths[9];

	//0x020e79c4
	static WorldStruct looooool[8];

	//0x020e74d4
	static LevelStruct w1Levels[0x13];

	//0x020e75b8
	static LevelStruct w2Levels[0x14];

	//0x020e715c
	static LevelStruct w3Levels[0x12];

	//0x020e730c
	static LevelStruct w4Levels[0x13];

	//0x020e78a4
	static LevelStruct w5Levels[0x18];

	//0x020e76a8
	static LevelStruct w6Levels[0x15];

	//0x020e7234
	static LevelStruct w7Levels[0x12];

	//0x020e73f0
	static LevelStruct w8Levels[0x13];

	//0x020e6a78
	static PathStruct w1Paths[0x17];

	//0x020e6cb0
	static PathStruct w2Paths[0x18];

	//0x020e6ad4
	static PathStruct w3Paths[0x17];

	//0x020e6a1c
	static PathStruct w4Paths[0x17];

	//0x020e7064
	static PathStruct w5Paths[0x1E];

	//0x020e6dd0
	static PathStruct w6Paths[0x1A];

	//0x020e6d10
	static PathStruct w7Paths[0x18];

	//0x020e69c4
	static PathStruct w8Paths[0x16];


	//0x020e36c0
	static u32 wmPathMaskFiles[9];

	//0x020e369c
	static u32 wmPathFiles[9];

	//0x020e8794
	static u32 worldmapModelFileIDs[8][16];

	//0x020ee390
	static u8 worldStarCoinsCompleted;//Bitmask (1 << world)

	//0x020e5a2c
	static s8 nextWorld;//-1 if none pressed, else pressed icon = world

//Don't really belong here
/*
	//0x020ee4b4
	static Function updateStates[5];

	//0x020ee3f0
	static UpdateState currentUpdateState;

	//020cc2c0
	static SubscreenState currentSubscreenState;

	//0x020ee4dc
	static Function subscreenUpdateStates[11];

	//0x020ee3cc
	static u32 subscreenUpdateStateFlags;//0x1: Initialized

	//0x020ee534
	static Function subscreenRenderStates[11];

	//0x020ee3f8
	static u32 subscreenRenderStateFlags;//0x1: Initialized
*/

	typedef bool(*ChallengeModeStateFunction)();

	struct ChallengeModeState {
		ChallengeModeStateFunction function;
		const char* buttonName;
	};

	//0x020e5a34
	static const char challengeModeButtonNameX[2];

	//0x020e5a38
	static const char challengeModeButtonNameL[2];

	//0x020e5a3c
	static const char challengeModeButtonNameY[2];

	//0x020e5a40
	static const char challengeModeButtonNameR[2];

	//0x020e2dfc
	static ChallengeModeState challengeModeStates[8];

	//0x020ee3d4
	static u32 currentChallengeModeState;

	//0x020ee3e0
	static fx32 textBoxScale;

	//0x020ee3f4
	static void* textFile;

	//0x020ee58c
	static TextBox textBox;

	//0x020ee3b8
	static u32 currentTextIndex;

	//0x020ee374
	static TextBoxType textBoxType;

	//0x020ee380
	static bool isGameCompleted;

	//0x020e64ec
	static u32 textIndices[2 * 4];

	//0x020e6bf0
	static VecFx32 lightDirections[8];

	//0x020e650c
	static u32 worldmapMusicIDs[10];

	//0x020e6714
	static fx32 cameraLimits[8][2];//0=Left,1=Right


	//0x020d14f8
	WorldmapScene();

	//D0:0218d3a4
	//D1:0218d36c
	virtual ~WorldmapScene() override;

	//0x020cf7c8
	virtual s32 onCreate() override;

	//0x020cf794
	virtual s32 onDestroy() override;

	//0x020cf034
	virtual s32 onUpdate() override;

	//0x020cf12c
	virtual void postUpdate(BaseReturnState state) override;

	//0x020cf15c
	virtual s32 onRender() override;

	//0x020cf790
	virtual void onCleanupResources() override;

	//0x020cdccc
	static void disableBowserJRAnimations(u32 lastWorld);//Disables all animations up to (including) lastWorld

	//0x020cdf9c
	static u32 getStarCoinCount();

	//0x020cdec0
	static u32 getStarCoinSpent();

	//0x020cddd8
	static void checkLevelCompletion();

	//0x020cdcf8
	static void checkPathCompletion();

	//0x020ce0a0
	static void checkCompletion();

	//0x020dd038
	static u32 getWorldMapIndex(u32 worldID);

	//0x020dc1f8
	static u32 getWorldmapPathMaskFileID(u32 world);

	//0x020dc218
	static u32 getWorldmapPathFileID(u32 world);

	//0x020d0144
	//EWWWWWWW

	//0x020ce214
	static u32 getWorldmapModelFile(u32 world, u32 index);

	//0x020d20ac
	static bool loadWorldmapModels();

	//0x020db28c
	static bool loadBowserJRPeachModels();

	//0x020d1478
	//IDK

	//0201ec88 - CheckIfLevelAlreadyBeaten
	//Bitch do I look like I care? NO

	//0x020cefd4
	void onUpdateWorldEnter();//State 0

	//0x020ced90
	void onUpdateWorldmap();//State 1

	//0x020ce674
	void onUpdatePauseMenu();//State 2

	//0x020ce330
	void onUpdateSaveDialog();//State 3

	//0x020ce228
	void onUpdateWorldTransition();//State 4, does nothing

	//0x020d08dc
	void updateSubscreen();

	//0x020d0788
	void updateWorldmapSubscreen();//State 0

	//0x020d0708
	void swipeMenuOut();//State 1 & 5-8

	//0x020d06fc
	void loadOptionsMenu();//State 2

	//0x020d06c8
	void swipeMenuIn();//State 3 & 10

	//0x020d06bc
	void updateOptionsMenu();//State 4

	//0x020d06b0
	void loadWorldmapIcons();//State 9

	//0x020d113c
	void renderSubscreen();

	//0x020d0a4c
	void renderOptionsMenu();

	//0x020d0a58
	void renderWorldmapSubscreen();

	//0x020d0548
	static bool updateChallengeModeState(u32* currentState);

	//0x020d0614
	static void resetChallengeModeState(u32* currentState);

	//0x020d0534
	static void resetChallengeModeState();

	//0x020d04fc
	static bool isChallengeModeTriggered();

	//0x020d0620
	static bool isLPressed();

	//0x020d0644
	static bool isRPressed();

	//0x020d0668
	static bool isXPressed();

	//0x020d068c
	static bool isYPressed();

	//0x020cdc30
	static FontString* setTextBox(u32 stringIndex, TextBox::Type type, void* bmg);

	//0x020ced20
	static void showPauseMenu();

	//0x020ce5ec
	static void showSaveDialog();

	//0x020ce22c
	static void transitionToNextWorld();

	//0x020ce298
	static u32 getNextWorldID(u32 currentWorld);

	//0x020ce16c
	static fx32 getLightDirectionX(u32 world);

	//0x020ce16c
	static fx32 getLightDirectionY(u32 world);

	//0x020ce16c
	static fx32 getLightDirectionZ(u32 world);

	//0x020ce12c
	static u32 getWorldmapMusicID(u32 world);

	//0x020cdb44
	static void fadeWorldmap(u16 sceneID, u32 settings);

	//0x020cda7c
	static u16 getWorldmapNodeCount(u32 world);

	//0x020ce1b4
	static fx32 getLeftCameraLimit(u32 world);

	//0x020ce184
	static fx32 getRightCameraLimit(u32 world);

};
NTR_SIZE_GUARD(WorldmapScene, 0x888);
