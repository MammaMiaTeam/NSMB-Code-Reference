#pragma once
#include "nitro_if.h"


enum class SceneID;
class Player;

namespace StageGroups
{
	constexpr auto World1 = 0;
	constexpr auto World2 = 1;
	constexpr auto World3 = 2;
	constexpr auto World4 = 3;
	constexpr auto World5 = 4;
	constexpr auto World6 = 5;
	constexpr auto World7 = 6;
	constexpr auto World8 = 7;
	constexpr auto ToadHouse = 8;
	constexpr auto MvsL = 9;
}

namespace StageNodes
{
	constexpr auto Arrow = 0;
	constexpr auto A = 9;
	constexpr auto B = 10;
	constexpr auto C = 11;
	constexpr auto GhostHouse = 12;
	constexpr auto Tower = 13;
	constexpr auto Castle = 14;
	constexpr auto Pipe = 15;
	constexpr auto Cannon = 16;
	constexpr auto RedToadHouse = 17;
	constexpr auto GreenToadHouse = 18;
	constexpr auto YellowToadHouse = 19;
	constexpr auto Fork = 20;
	constexpr auto Tower2 = 21;
	constexpr auto FinalCastle = 22;
	constexpr auto BGChooser = 23;
}

namespace ToadHouses
{
	constexpr auto OneUp = 0;
	constexpr auto Item = 1;
	constexpr auto MegaMushroom = 2;
	constexpr auto BGChooser = 3;
}

namespace MvsLStages
{
	constexpr auto MvsLOverworld = 0;
	constexpr auto MvsLUnderground = 1;
	constexpr auto MvsLIce = 2;
	constexpr auto MvsLPipes = 3;
	constexpr auto MvsLCastle = 4;
}

namespace Game
{

	// 02085A7C
	extern int localPlayerID;

	// 02085A84
	extern u8 vsMode;

	// 02085A50
	extern bool luigiMode;

	// 02085a1c
	extern bool checkpointCollected;

	// 02085a9c
	extern u32 currentWorldmapNode;

	extern MtxFx43 modelMatrix;
	extern MtxFx43 viewMatrix;

	constexpr s32 getStage(u8 group, u8 node) {

		constexpr u8 none = 0xFF;
		constexpr u8 mapping[10][24] =
		{
			/*        0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23	 */
			/*        ^     1     2     3     4     5     6     7     8     A     B     C     GH    TOW   CSTL  PIPE  CANN  RTH   GTH   YTH   FORK  TOW2  FCST  BGCH */
			/* 1 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, none, none, none, 0x05, none, none, none, 0x06, 0x07, none, 0x08, none, none, none, none, none, none, none },
			/* 2 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, none, none, 0x06, none, none, none, 0x07, 0x08, none, 0x09, none, none, none, none, none, none, none },
			/* 3 */ { none, 0x00, 0x01, 0x02, none, none, none, none, none, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, none, 0x09, none, none, none, none, none, none, none },
			/* 4 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, none, none, 0x07, none, none, 0x08, 0x09, 0x0A, none, 0x0B, none, none, none, none, none, none, none },
			/* 5 */ { none, 0x00, 0x01, 0x02, 0x03, none, none, none, none, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, none, 0x0A, none, none, none, none, none, none, none },
			/* 6 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, none, none, 0x06, 0x07, none, none, 0x08, 0x0A, none, 0x0B, none, none, none, none, 0x08, none, none },
			/* 7 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, none, 0x07, none, none, 0x08, 0x09, 0x0A, none, none, none, none, none, none, none, none, none },
			/* 8 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, none, none, none, none, 0x08, 0x0A, none, none, none, none, none, none, 0x09, 0x0B, none },
			/* K */ { 0x00, 0x01, 0x02, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, 0x03 },
			/* V */ { 0x00, 0x01, 0x02, 0x03, 0x04, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none },
		};

		u8 stage = mapping[group][node];

		return stage == 0xFF ? -1 : stage;

	}

	// 0x0200696c
	ssym void loadLevel(u16 scene, u32 vs, u8 group, u8 stage, u8 act, u8 playerID, u8 playerMask, u8 character1, u8 character2, u8 powerup, u8 entrance, u8 flag, u8 unused1, u8 controlOptions, u8 unused2, u8 challengeMode, u32 rngSeed) __body

	__inline void loadLevel(SceneID scene, u32 vs, u8 group, u8 stage, u8 act, u8 playerID, u8 playerMask, u8 character1, u8 character2, u8 powerup, u8 entrance, u8 flag, u8 unused1, u8 controlOptions, u8 unused2, u8 challengeMode, u32 rngSeed) {
		loadLevel(static_cast<u16>(scene), vs, group, stage, act, playerID, playerMask, character1, character2, powerup, entrance, flag, unused1, controlOptions, unused2, challengeMode, rngSeed);
	}

	// 020066f8
	ssym void resetStageCheckpoint() __body

	// 02006740
	ssym void setStageCheckpoint() __body

	// 02006790
	ssym bool getStageCheckpoint() __rbody

	// 020202a0
	ssym u32 getPlayerCount() __rbody

	// 020202b0
	ssym void setPlayerCount(u32 count) __body

	// 020205ec
	ssym Player* getCurrentPlayer() __rbody

	// 02020608
	ssym Player* getPlayer(s32 playerID) __rbody

	// 02020618
	ssym void setPlayer(s32 playerID, Player* player) __body


	// 0200dee0
	ssym void stageObjectBankOverlayProc(void* banks, bool load) __body

	__inline void unloadStageObjectBankOverlays(void* banks) {
		stageObjectBankOverlayProc(banks, false);
	}
	__inline void loadStageObjectBankOverlays(void* banks) {
		stageObjectBankOverlayProc(banks, true);
	}

	// 02020260
	ssym u8 getPlayerCharacter(s32 playerID) __rbody

	// 02020270
	ssym void setPlayerCharacter(s32 playerID, u8 characterID) __body

	// 02020570
	ssym u8 getPlayerLives(s32 playerID) __rbody

	// 02020580
	ssym void setPlayerLives(s32 playerID, s32 lives) __body

	// 02020240
	ssym u8 getPlayerInventoryPowerup(s32 playerID) __rbody

	// 02020250
	ssym u8 setPlayerInventoryPowerup(s32 playerID, u8 powerup) __rbody

	// 02020220
	ssym u8 getPlayerDead(s32 playerID) __rbody

	// 02020230
	ssym u8 setPlayerDead(s32 playerID, bool dead) __rbody

	// 020200B4
	ssym u8 getPlayerRespawnState(s32 playerNo) __rbody

	// 020200C4
	ssym u8 setPlayerRespawnState(s32 playerNo, s32 state) __rbody

}
