#pragma once

#include "nitro_if.h"


enum Keys {

	KeyA = 0x1,
	KeyB = 0x2,
	KeySelect = 0x4,
	KeyStart = 0x8,
	KeyRight = 0x10,
	KeyLeft = 0x20,
	KeyUp = 0x40,
	KeyDown = 0x80,
	KeyR = 0x100,
	KeyL = 0x200,
	KeyX = 0x400,
	KeyY = 0x800

};


namespace Input {

	struct KeyState {

		u16 held;
		u16 pressed;

	};

	struct Mapping {

		u16 unk0;
		u16 jumpKeys;
		u16 selectKey;
		u16 startKey;
		u16 rightKey;
		u16 leftKey;
		u16 upKey;
		u16 downKey;
		u16 rKey;
		u16 lKey;
		u16 unk14;
		u16 runKeys;

	};



	// 0200a9d0
	void initPlayerMapping();

	// 0200a814
	bool updatePlayerInput();

	// 0200a784
	void setPlayerMapping(bool normal, int playerID);

	// 0200a6e4
	void updateVirtualPlayerInput(int playerID);


	// 0200a594
	void update();


	// 0200a508
	void updateConsoleInput();

	// 0200a4c8
	bool getFirstConsoleKeysPressed(int* consoleID, u16 keys);

	// 0200a488
	bool getFirstConsoleKeysHeld(int* consoleID, u16 keys);

	// 0200a42c
	void updateVerticalSelectionIterator(int* iterator, int max);

	// 0200a3d0
	void updateHorizontalSelectionIterator(int* iterator, int max);



	// 020262ec
	static u16 unusedDirectionalFlags[16];



	// TODO: max player count constant here

	// 020876b0
	extern Mapping playerMapping[2];

	// 020876a0
	extern u16 playerKeysHeldStack[2][4];

	// 02087690
	extern u16 playerKeysPressedStack[2][4];

	// 0208768c
	extern u16 playerKeysRepeated;

	// 02087688
	extern u16 playerRepeatTimer[2];

	// 02087684
	extern u16 playerRepeatDelay[2];

	// 02087680
	extern u16 playerRepeatRate[2];

	// 0208767c
	extern u16 playerDirectionalFlags[2];

	// 02087678
	extern u32 virtualPlayerInputLength;

	// 02087674
	extern u32 playerKeyStackID;

	// 02087670
	extern BOOL virtualPlayerInputEnabled;

	// 0208766c
	extern u8* virtualPlayerInputPatternSource;

	// 02087668
	extern u32 virtualPlayerInputTimer;

	// 02087664
	extern u16 playerKeysPressed[2];

	// 02087660
	extern u16 playerKeysHeld[2];



	// TODO: max console count constant here

	// 02087650
	extern KeyState consoleKeys[4];

	// 02087648
	extern u16 consoleKeysRepeated[4];

	// 02087640
	extern u16 consoleKeysUp[4];

	// 02087638
	extern u16 consoleKeysTimer[4];



	inline u16 getPressedKeys(u8 console = 0){
		return consoleKeys[console].pressed;
	}

	inline u16 getHeldKeys(u8 console = 0){
		return consoleKeys[console].held;
	}

}
