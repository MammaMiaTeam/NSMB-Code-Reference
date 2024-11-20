#pragma once

#include <nsmb_nitro.hpp>

//
// WARNING:
// If you intend to shake the screen for only one player,
// never do the following with any of the ViewShaker::start overloads!
//
// if (canShakePlayer(Game::localPlayerID)) {
//     ViewShaker::start(type, viewID);
// }
//
// Doing so desynchronizes multiplayer, use the 4 argument overload instead without the local condition as such:
//
// for (s32 playerID = 0; playerID < Game::getPlayerCount(); playerID++) {
//     if (canShakePlayer(playerID)) {
//         ViewShaker::start(type, viewID, playerID, 0);
//     }
// }
//

namespace ViewShaker
{

	using Flags = u32;

	static constexpr Flags TriggerMegaGroundPound			= 1 << 0;
	static constexpr Flags TriggerMegaWalkShockwave			= 1 << 1;
	static constexpr Flags TriggerMegaGroundPoundShockwave	= 1 << 2;
	static constexpr Flags UnusedAction8					= 1 << 3; // update()

	struct Config
	{
		fx32 end;
		fx32 start;
		fx32 speed;
		fx32 max;
		fx32 min;
		u32 flags;
	};

	// Starts shaking the view for the specified player.
	void start(u8 type, u8 viewID, u8 playerID, bool triggerActions);

	// Starts shaking the view for the specified player and the other player if in the same view.
	void start(u8 type, u8 viewID, u8 playerID);

	// Starts shaking the view for both players.
	void start(u8 type, u8 viewID);

	void setConfig(u8 playerID, const Config& config);

	void reset();

	void update();

	void destroy();

	void create();

}
