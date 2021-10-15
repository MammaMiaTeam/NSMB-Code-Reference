#pragma once
#include "nitro_if.h"


enum class SceneID;
class Player;


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
