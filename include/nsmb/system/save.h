#pragma once
#include "nitro_if.h"
#include "nsmb/util.h"


struct MinigameHighscore {

	/*
		u32 record0 : 20;
		u32 record1 : 20;
		u32 record2 : 20;
		u32 record3 : 20;
		u32 record4 : 20;
	*/

	u8 records[13];

};
NTR_SIZE_GUARD(MinigameHighscore, 0xD);


struct MinigameSave {

	char magic[4];								//'9000' in ASCII
	u32 flags;									//0x80000000 : Started save file
	MinigameHighscore minigameHighscores[18];

};
NTR_SIZE_GUARD(MinigameSave, 0xF4);


struct MainSave {

	enum class WorldFlags : u16 {
		Started				= 0x1,
		BowserJRStart		= 0x2,				//Triggered in any level
		BowserJRTower		= 0x4,				//Triggered in tower
		BowserJRFortress	= 0x8,				//Triggered in fortress
		BowserJRTower2		= 0x10,				//Triggered in tower 2
		MarioExit			= 0x20,				//Triggered in final castle
		Unlocked			= 0x40,
		WorldFinished		= 0x80,
		TowerFinished		= 0x100,			//Triggers the save screen
		FortressFinished	= 0x200,			//Triggers the save screen
		Tower2Finished		= 0x400,			//Triggers the save screen
		ToadHouse			= 0x1000
	};

	enum class NodeFlags : u8 {
		StarCoin1		= 0x1,
		StarCoin2		= 0x2,
		StarCoin3		= 0x4,
		StandardExit	= 0x10,					//Set when the level was exited normally
		ToadHouseDone	= 0x20,					//Set when the level was a toad house
		LevelDone		= 0x40,					//Set when the level was completed in any way and returned to the current world
		Completed		= 0x80,					//Set when the level was finished
	};

	//Node flags used by the arrow sign node
	enum class StartFlags : u8 {
		Item = 0,
		OneUp,
		Mega,
		Trunk
	};

	enum class PathFlags : u8 {
		Start		= 0x10,						//Set for start paths
		Unlocking	= 0x20,						//Set during unlocking
		Unlocked	= 0x40,						//Set when a new level is unlocked
		Activated	= 0x80						//Pipes only get this flag set (since they aren't levels)
	};

	struct WorldmapActor {

		//Only work for those levels where the given type is enabled
		enum class Type : u8 {
			HammerBro = 0,
			FlyingBlock
		};

		u8 node;
		Type type;

	};

	enum class CompletionFlags : u32 {
		StandardLevelsCompleted		= 0x1,		//Excludes cannons
		AllPathsUnlocked			= 0x2,
		AllStarSignsRemoved			= 0x4,
		AllStarCoinsCollected		= 0x8,
		TriggerAllStarCoinsSpent	= 0x10,
		StoryCompleted				= 0x20,
		AllStarCoinsSpent			= 0x80,
		AllLevelsCompleted			= 0x100,	//Includes cannons
		UnlockedBG1					= 0x80000,
		UnlockedBG2					= 0x100000,
		UnlockedBG3					= 0x200000,
		UnlockedBG4					= 0x400000,
		WorldPath12					= 0x800000,
		WorldPath23					= 0x1000000,
		WorldPath24					= 0x2000000,
		WorldPath35					= 0x4000000,
		WorldPath45					= 0x8000000,
		WorldPath56					= 0x10000000,
		WorldPath57					= 0x20000000,
		WorldPath68					= 0x40000000,
		WorldPath78					= 0x80000000,
	};

	char magic[4];								//'7000' in ASCII
	u32 flags;									//Only 0x1 for saved
	CompletionFlags completion;
	u32 lives;
	u32 coins;
	u32 score;
	u32 starCoinsCollected;
	u32 starCoinsSpent;
	u32 currentWorld;
	u32 savedWorld;
	u32 currentWorldmapNode;
	u32 savedWorldmapNode;
	u32 powerup;
	u32 tempScore;								//Score mod 50000
	u32 bottomScreenTheme;
	bool miniMushroomUnlocked;					//True if a mini mushroom was used at least once. Enables flying ?-blocks to drop it.
	u32 actorRespawnWorld;						//World in which the worldmap actors get respawned (for each 50000 score points)
	u32 seenLevelImages[6];						//Each bit represents an image seen on the ending screen. If set and the level was beaten, it will not appear as 'new'.
	u8 inventoryPowerup;
	u8 reserved[3];								//Unused in the final game, but most likely there to store additional powerups
	WorldFlags worldFlags[8];
	NodeFlags nodeFlags[25 * 8];
	PathFlags pathFlags[30 * 8];
	WorldmapActor wmActors[2 * 8];				//Two types per world

};
NTR_SIZE_GUARD(MainSave, 0x248);

IMPL_ENUMCLASS_OPERATORS(MainSave::WorldFlags);
IMPL_ENUMCLASS_OPERATORS(MainSave::NodeFlags);
IMPL_ENUMCLASS_OPERATORS(MainSave::StartFlags);
IMPL_ENUMCLASS_OPERATORS(MainSave::PathFlags);
IMPL_ENUMCLASS_OPERATORS(MainSave::CompletionFlags);


struct OptionSave {

	enum class Sound : u32 {
		Surround = 0,
		Headphones,
		Stereo
	};

	enum class Controls : u32 {
		JumpAX = 0,
		JumpAB
	};

	char magic[4];			//'3000' in ASCII
	u32 flags;				//Only 0x1 for saved
	Sound soundMode;
	Controls controls;
	u32 activeSlot;

};
NTR_SIZE_GUARD(OptionSave, 0x14);


namespace Save {

	enum class returnCode {
		Success = 0,
		Failure,
		BackupBroken,
		BothBroken
	};

	//02088bdc
	extern MainSave mainSave;

	//02088e24
	extern MinigameSave minigameSave;

	//02088f18
	extern OptionSave optionSave;


	//0204c7f4
	returnCode setupBackup(CARDBackupType type, const char* signature);

	//0204c114
	returnCode readBackup(void* data, u32 size, u32 slot);

	//0204c568
	returnCode writeBackup(void* data, u32 size, u32 slot);//returns true on failure. Slot determines the save slot. Data is written 0xA bytes after the slot start.


	//02012788
	void writeMGScore(u32 minigameID, u32 rank, u32 score);

	//02012824
	u32 readMGScore(u32 minigameID, u32 rank);

	//0201289c
	bool writeMGSave(MinigameSave* header);

	//020128c4
	returnCode readMGSave(MinigameSave* header);

	//020128d8
	void clearMGSave(MinigameSave* header);

	//020128fc
	bool createMGSave();

	//02012934
	u16 getWorldmapSceneID();

	//0201293c
	void disableCurrentWorldmapActor(MainSave::WorldmapActor::Type type);

	//020129b0
	bool animationPlayed();

	//02012a20
	u32 getStarCoinAmount();

	//02012a3c
	bool isStarCoinCollected(u32 starCoinID);

	//02012a58
	u8 getCurrentLevelStarCoins();

	//02012a78
	u8 getLevelStarCoins(u32 world, u8 nodeID);

	//02012a98
	void setLevelStarCoins(u32 world, u8 nodeID, u8 starCoins);

	//02012abc

	//02012d6c
	bool onGameOver(u32 slot, MainSave* save);//Does nothing

	//02012d70
	bool onStoryFinished(u32 slot, MainSave* save);

	//02012d98
	bool writeSave(u32 slot, MainSave* save);

	//02012da4
	void loadPlayerData();

	//02012e08
	bool loadMainSave(u32 slot, u32 liveCount, MainSave* save);

	//02012ee0
	bool createMainSave(u32 slot, MainSave* save);

	//02012f24
	bool writeMainSave(u32 slot, MainSave* save);

	//02012f64
	returnCode readMainSave(u32 slot, MainSave* save);

	//02012f9c
	void clearMainSave(MainSave* save);

	//02012ff0
	bool createOptionSave(OptionSave* save);

	//0201301c
	bool writeOptionSave(OptionSave* save);

	//02013050
	returnCode readOptionSave(OptionSave* save);

	//02013064
	void clearOptionSave(OptionSave* save);

	//02013090
	bool createOptionSave();

	//020130b4
	bool generateOptionSave();

	//020130b4
	bool resetSaves();

	//02013100
	void clearLoadedSaves();

}
