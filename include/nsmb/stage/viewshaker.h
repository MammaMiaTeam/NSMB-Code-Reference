#pragma once
#include "misc.h"


namespace ViewShaker
{

	using Flags = u32;

	static constexpr Flags TriggerMegaGroundPound			= 1 << 0;
	static constexpr Flags TriggerMegaWalkShockwave			= 1 << 1;
	static constexpr Flags TriggerMegaGroundPoundShockwave	= 1 << 2;
	static constexpr Flags UnusedAction8					= 1 << 3;

	struct Config
	{
		fx32 end;
		fx32 start;
		fx32 speed;
		fx32 max;
		fx32 min;
		u32 flags;
	};

	void start(u8 type, u8 viewID, u8 playerID, bool triggerActions);

	void start(u8 type, u8 viewID, u8 playerID);

	void start(u8 type, u8 viewID);

	void setConfig(u8 playerID, const Config& config);

	void reset();

	void update();

	void destroy();

	void create();

}
