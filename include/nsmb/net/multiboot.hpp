#pragma once

#include "types.hpp"
#include "wireless_shared/mbp.hpp"

namespace Net {

	namespace Core {

		void parentMultiBootState();

		void fakeChildState();

		void parentBroadcastState();

		void unusedState();

		void multiBootPairChildren();

		BOOL startParentBroadcast();

	}

	BOOL startMultiBootParent(MBGameRegistry* gameInfo);

	BOOL startFakeChild();

	void startMultiBootTransfer();

	const MBPChildInfo* getParentGameInfo(u32 parentIndex);

	const u8* getParentBssid(u32 parentIndex);

	void acceptChildren();

}
