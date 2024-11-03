#pragma once

#include "types.hpp"

namespace Wifi::MB {

	BOOL isChildDownloadFailed();

	BOOL isFakeChild();

	BOOL isChildReadyForBoot();

	void connectFakeChild();

	void terminateFakeChild();

	MBGameInfo* getFakeChildParentGameInfo();

	WMBssDesc* getFakeChildParentsBssDesc();

	BOOL startFakeChild(u32 ggid);

	MBCommCState getChildDownloadState();

	void onFakeSetCState(u32 status, void* arg);

	u16 getFakeScanState();

	void onFakeStartScan(u16 type, void* arg);

	u8* getChildMacAddress(u16 aid);

	u8* getDownloadParameter();

	MBPChildInfo* getChildInfo(u16 aid);

	u16 update(u16 targetState);

	BOOL startParent(u32 ggid, MBGameRegistry* gameInfo);


	extern u16 fakeScanState;
	extern MBCommCState childState;

	extern BOOL fakeChildFlag;
	extern MBGameRegistry* gameInfo;
	extern MBGameInfo fakeChildParentGameInfo[MaxParentScan];

}
