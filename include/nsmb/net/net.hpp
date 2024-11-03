#pragma once

#include "types.hpp"

namespace Net {

	constexpr u32 SignalStrengthIconFrames = 4;

	constexpr u32 GameGroupIdJP = 0x00000042;
	constexpr u32 GameGroupIdEU = 0x00800055;
	constexpr u32 GameGroupIdUS = 0x00400150;

	u32 getLocalizedGgid();

	const MBGameRegistry* getLocalizedGameInfo();

	void setDefaultHandlers();

	BOOL startParentBroadcast();

	BOOL startMultiBootParent(u8 character);

	BOOL checkMultiBootGgid();

	void onRenderSignalStrengthDefault();

	void onPacketPollingDefault();


	extern const void* signalStrengthGraphics[SignalStrengthIconFrames][2];
	extern GXOamAttr signalStrengthSprite[1];
	extern MBGameRegistry gameInfoEU;
	extern MBGameRegistry gameInfoJP;
	extern MBGameRegistry gameInfoUS;

}
