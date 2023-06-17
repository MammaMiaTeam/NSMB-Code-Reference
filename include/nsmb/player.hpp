#pragma once
#include "nitro_if.hpp"
#include "player/model.hpp"


class Player;

namespace Game {

	enum class VSPipeState : u32
	{

		None,
		PipeRising,
		PipeRisen,
		PlayerOut

	};

	extern u8 playerPowerup[2];
	extern bool playerDead[2];
	extern u8 playerInventoryPowerup[2];
	extern u8 playerCharacter[2];
	extern s16 playerMegaTimer[2];
	extern BOOL playerInCutscene;
	extern s16 playerMegaDestructionScore[2];
	extern u32 playerSpawnMask;
	extern s16 playerMiniShockedTimer[2];
	extern s32 playerCount;
	extern BOOL playerLookingAtTarget;
	extern s16 playerStarmanTimer[2];
	extern VSPipeState playerVSPipeState[2];
	extern Player* players[2];
	extern s32 playerLives[2];
	extern s32 playerBattleStars[2];
	extern s32 playerStarCoins[2];
	extern s32 playerCoins[2];
	extern s32 playerScore[2];
	extern s32 playerDisplayedStars[2];
	extern s32 playerDeaths[2];
	extern s32 playerCollectedStars[2];
	extern VecFx32 bossSwitchPosition;
	extern VecFx32 playerLookAtPosition;
	extern u16 playerPaletteParams[12];
	extern u32 playerJumpPressedRingBuffer[2][4];
	extern u32 playerJumpHeldRingBuffer[2][4];
	extern u32 playerTextureParams[32];

	void setPlayerInCutscene(bool enable);
	bool isPlayerInCutscene();
	void setPlayerLookingAtTarget(bool enable);
	bool isPlayerLookingAtTarget();
	void setPlayerLookAtPosition(const Vec3& position);
	void setPlayerLookAtPosition(fx32 x, fx32 y, fx32 z);
	void setBossSwitchPosition(const Vec3& position);
	void setBossSwitchPosition(fx32 x, fx32 y, fx32 z);
	VSPipeState getPlayerVSPipeState(s32 playerID);
	void setPlayerVSPipeState(s32 playerID, VSPipeState state);

	void addMegaDestructionScore(s32 playerID, s16 score);
	s16 getMegaDestructionScore(s32 playerID);
	void setMegaDestructionScore(s32 playerID, s16 score);
	s16 getMegaTimer(s32 playerID);
	void setMegaTimer(s32 playerID, s16 timer);
	void setMiniShockedTimer(s32 playerID, s16 timer);
	s16 getStarmanTimer(s32 playerID);
	void setStarmanTimer(s32 playerID, s16 timer);
	void updatePlayerCameraFocus(s32 playerID);
	u8 getPlayerPowerup(s32 playerID);
	void setPlayerPowerup(s32 playerID, u8 powerup);
	u32 getPlayerTextureParams(s32 slot);
	void setPlayerTextureParams(s32 slot, u32 params);
	u16 getPlayerPaletteParams(s32 slot);
	void setPlayerPaletteParams(s32 slot, u16 params);
	bool getPlayerDead(s32 playerID);
	void setPlayerDead(s32 playerID, bool dead);
	u8 getPlayerInventoryPowerup(s32 playerID);
	void setPlayerInventoryPowerup(s32 playerID, u8 powerup);
	u8 getPlayerCharacter(s32 playerID);
	void setPlayerCharacter(s32 playerID, u8 character);
	u32 getPlayerSpawnMask();
	void setPlayerSpawnMask(u32 mask);
	s32 getPlayerCount();
	void getPlayerCount(s32 count);
	s32 getPlayerCollectedStars(s32 playerID);
	void setPlayerCollectedStars(s32 playerID, s32 count);
	s32 getPlayerDisplayedStars(s32 playerID);
	void setPlayerDisplayedStars(s32 playerID, s32 count);
	void addPlayerScore(s32 playerID, s32 count);
	s32 getPlayerScore(s32 playerID);
	void setPlayerScore(s32 playerID, s32 count);
	bool addPlayerCoin(s32 playerID);
	s32 getPlayerCoins(s32 playerID);
	void getPlayerCoins(s32 playerID, s32 count);
	void addPlayerStarCoin(s32 playerID);
	void setPlayerStarCoins(s32 playerID, s32 count);
	void addPlayerBattleStar(s32 playerID);
	s32 getPlayerBattleStars(s32 playerID);
	void setPlayerBattleStars(s32 playerID, s32 count);
	void addPlayerDeath(s32 playerID);
	s32 getPlayerDeaths(s32 playerID);
	void setPlayerDeaths(s32 playerID, s32 count);
	s32 losePlayerLife(s32 playerID);
	void gainPlayerLife(s32 playerID);
	s32 getPlayerLives(s32 playerID);
	void setPlayerLives(s32 playerID, s32 count);

	void spawnPlayer(s32 playerID, u8 character, u32 settings, const Vec3* position, const Vec3s* rotation = nullptr);
	Player* getLocalPlayer();
	Player* getPlayer(s32 playerID);
	void setPlayer(s32 playerID, Player* player);
	void resetPlayerState();

	bool loadPlayerResources();
	bool setupLuigiResources();
	bool setupMarioResources();
	void playTransitionMusic(s32 seqID);
	void playerModelCallback(NNSG3dRS* rs);

	NTR_INLINE s16 getMiniShockedTimer(s32 playerID) {
		return playerMiniShockedTimer[playerID];
	}

	NTR_INLINE s32 getPlayerStarCoins(s32 playerID) {
		return playerStarCoins[playerID];
	}

}
