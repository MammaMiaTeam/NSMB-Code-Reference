#pragma once
#include "nitro_if.h"
#include "nsmb/util.h"


namespace Keys {

	constexpr u16 A				= PAD_BUTTON_A;
	constexpr u16 B				= PAD_BUTTON_B;
	constexpr u16 Select		= PAD_BUTTON_SELECT;
	constexpr u16 Start			= PAD_BUTTON_START;

	constexpr u16 Right			= PAD_KEY_RIGHT;
	constexpr u16 Left			= PAD_KEY_LEFT;
	constexpr u16 Up			= PAD_KEY_UP;
	constexpr u16 Down			= PAD_KEY_DOWN;

	constexpr u16 R				= PAD_BUTTON_R;
	constexpr u16 L				= PAD_BUTTON_L;
	constexpr u16 X				= PAD_BUTTON_X;
	constexpr u16 Y				= PAD_BUTTON_Y;

	constexpr u16 Debug			= PAD_BUTTON_DEBUG;
	constexpr u16 Folding		= PAD_DETECT_FOLD_MASK;
	constexpr u16 Hinge			= Folding;

	constexpr u16 ABXY			= A | B | X | Y;
	constexpr u16 Shoulder		= R | L;
	constexpr u16 Vertical		= Up | Down;
	constexpr u16 Horizontal	= Left | Right;
	constexpr u16 Directional	= PAD_PLUS_KEY_MASK;
	constexpr u16 Buttons		= PAD_BUTTON_MASK;
	constexpr u16 All			= PAD_ALL_MASK;

}


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
	void setPlayerMapping(bool normal, u32 playerID);

	// 0200a6e4
	u16 updateVirtualPlayerInput(u32 playerID);


	// 0200a594
	void update();


	// 0200a508
	void updateConsoleInput(u32 consoleAID, u16 keys);

	// 0200a4c8
	bool getFirstConsoleKeysPressed(u32* consoleID, u16 keys);

	// 0200a488
	bool getFirstConsoleKeysHeld(u32* consoleID, u16 keys);

	// 0200a42c
	void updateVerticalSelectionIterator(s32* iterator, s32 max);

	// 0200a3d0
	void updateHorizontalSelectionIterator(s32* iterator, s32 max);



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
	extern u16 playerKeysRepeated[2];

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

	// 02087634
	extern u8 localConsoleID;

	// 02087630
	extern bool triggerSoftReset;



	NTR_INLINE u16 getPressedKeys(u8 console = 0) {
		return consoleKeys[console].pressed;
	}
	NTR_INLINE u16 getHeldKeys(u8 console = 0) {
		return consoleKeys[console].held;
	}
	NTR_INLINE u16 getRepeatedKeys(u8 console = 0) {
		return consoleKeysRepeated[console];
	}
	NTR_INLINE u16 getUpKeys(u8 console = 0) {
		return consoleKeysUp[console];
	}

	NTR_INLINE u16 getPlayerPressedKeys(u8 player = 0) {
		return playerKeysPressed[player];
	}
	NTR_INLINE u16 getPlayerHeldKeys(u8 player = 0) {
		return playerKeysHeld[player];
	}
	NTR_INLINE u16 getPlayerRepeatedKeys(u8 player = 0) {
		return playerKeysRepeated[player];
	}

}
