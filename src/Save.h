#ifndef NSMB_SAVE_INCLUDED
#define NSMB_SAVE_INCLUDED



union SaveHeader {

	char ascii[4];
	u32 value;

};



struct MinigameHighscore {

	u32 record0 : 20;
	u32 record1 : 20;
	u32 record2 : 20;
	u32 record3 : 20;
	u32 record4 : 20;

};



struct MinigameSave {

	char magic[4];								//'9000' in ASCII
	u32 flags;									//0x80000000 : Started save file
	MinigameHighscore minigameHighscores[18];

};



struct LevelFlags {

	enum class LevelFlags : u8 {
		StarCoin1 = 0x1,
		StarCoin2 = 0x2,
		StarCoin3 = 0x4,

	};

};



struct MainSave {

	enum class WorldFlags : u16 {
		Started = 0x1,
		BowserJRStart = 0x2,					//Triggered in any level
		BowserJRTower = 0x4,					//Triggered in tower
		BowserJRFortress = 0x8,					//Triggered in fortress
		BowserJRTower2 = 0x10,					//Set after world finish
		MarioExit = 0x20,						//Set after world finish
		Unlocked = 0x40,
		WorldFinished = 0x80,
		TowerFinished = 0x100,					//Triggers the save screen
		FortressFinished = 0x200,				//Triggers the save screen
		Tower2Finished = 0x400,					//Triggers the save screen
		ToadHouse = 0x1000
	};

	enum class LevelFlags : u8 {
		StarCoin1 = 0x1,
		StarCoin2 = 0x2,
		StarCoin3 = 0x4,
		StandardExit = 0x10,					//Set when the level was exited normally
		ToadHouseDone = 0x20,					//Set when the level was a toad house
		LevelDone = 0x40,						//Set when the level was completed in any way and returned to the current world
		Completed = 0x80,						//Set when the level was finished
	};

	//Level flags used by the arrow sign node
	enum class StartFlags : u8 {
		Item = 0,
		OneUp,
		Mega,
		Trunk
	};

	enum class PathFlags : u8 {
		Start = 0x10,							//Set for start paths
		Unlocking = 0x20,						//Set during unlocking
		Unlocked = 0x40,						//Set when a new level is unlocked
		Activated = 0x80						//Pipes only get this flag set (since they aren't levels)
	};

	struct WorldmapActors {

		enum class Type : u8 {
			HammerBro = 0,
			FlyingBlock
		};

		u8 node0;
		Type type0;
		u8 node1;
		Type type1;

	};

	char magic[4];								//'7000' in ASCII
	u32 unk04;
	u32 unk08;
	u32 lives;
	u32 coins;
	u32 score;
	u32 starCoinsCollected;
	u32 starCoinsSpent;
	u32 currentWorld;
	u32 unk24;
	u32 currentWorldmapNode;
	u32 savedWorldmapNode;
	u32 powerup;
	u32 tempScore;								//Score mod 50000
	u32 bottomScreenTheme;
	u32 unk3c;
	u32 unk40;
	u32 unk44;
	u32 unk48;
	u32 unk4c;
	u32 unk50;
	u32 unk54;
	u32 unk58;
	u8 inventoryPowerup;
	u8 unk5d;
	u8 unk5e;
	u8 unk5f;
	WorldFlags worldFlags[8];
	LevelFlags levelFlags[25 * 8];
	PathFlags pathFlags[30 * 8];
	WorldmapActors wmActors[8];

};




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
	u32 flags;				//None
	Sound soundMode;
	Controls controls;
	u32 activeSlot;

};



namespace Save {

	enum class ReturnCode {
		Success = 0,
		Failure,
		BackupBroken,
		BothBroken
	};

	//02088bdc
	MainSave mainSave;

	//02088e24
	MinigameSave minigameSave;

	//02088f18
	OptionSave optionSave;

	//0204c7f4
	ReturnCode setupBackup(CARDBackupType type, const char* signature);

	//0204c114
	ReturnCode readBackup(void* data, u32 size, u32 slot);

	//0204c568
	ReturnCode writeBackup(void* data, u32 size, u32 slot);//Returns true on failure. Slot determines the save slot. Data is written 0xA bytes after the slot start.

	//0201289c
	bool writeMGSave(SaveHeader* header);

	//020128c4
	ReturnCode readMGSave(SaveHeader* header);

	//020128d8
	void newMGSave(SaveHeader* header);

	//020128fc
	bool writeNewMGSave();

	//02012934

	//0201293c

	//020129b0

	//02012f64
	ReturnCode readMainSave(u32 slot, MainSave* save);

	//02012f24
	bool writeMainSave(u32 slot, MainSave* save);

	//02013050
	ReturnCode readOptionSave(OptionSave* save);

	//0201301c
	bool writeOptionSave(OptionSave* save);

}




#endif  // NSMB_SAVE_INCLUDED
