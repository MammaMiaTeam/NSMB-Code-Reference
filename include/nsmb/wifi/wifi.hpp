#pragma once

#include "types.hpp"
#include "nsmb/system/memory.hpp"

namespace Wifi {

	BOOL isWMInitialized();

	BOOL shutdownWM();

	void onShutdownWM(void* arg);

	BOOL initializeWM();

	void onInitializeWM(void* arg);


	void disableChildEntry();

	u16 getConnectedBitmap();

	BOOL hasErrorOccurred();

	WMLinkLevel getLinkLevel();

	u16 getCurrentAid();

	u16 getCommunicatingConsoleCount();

	BOOL isConsoleCommunicating(u16 aid);

	BOOL isChild();

	BOOL isParent();

	BOOL isMultiBootChild();

	BOOL terminateSession();

	void* getSharedData(u16 aid);

	BOOL updateSharedData(const void* data);

	BOOL isWFSReady();

	BOOL connectToParent(u32 parentIndex);

	WMBssDesc* getParentsBssDesc();

	BOOL startChildScan(u32 ggid, u8* parentMacAddress);

	void onParentFound(WMBssDesc* bssDesc);

	BOOL startParent(u32 ggid, u8 maxEntries, void* gameInfo, u16 gameInfoSize);

	BOOL isFastTransferEnabled();

	BOOL enableFastTransfer();

	void onEnableFastTransfer(void* arg);

	BOOL enableSyncTransfer();

	void onEnableSyncTransfer(void* arg);

	void initialize(OSTick timeout);

	BOOL measureOptimalChannel();

	BOOL setupSession(BOOL multiboot);

	BOOL whJudgeAcceptor(WMStartParentCallback* arg);

	void wfsCallback(void* arg);

	void* wfsAllocator(void* arg, u32 size, void* ptr);

	void indicateCallback(WMCallbackFunc* arg);


	extern u8 maxChildren;
	extern u16 optimalChannel;
	extern u16 communicatingConsoleCount;

	extern u16 sessionTgid;
	extern u16 parentsBssDescCount;
	extern u16 disconnectReason;
	extern BOOL pictoChatParentFlag;
	extern BOOL wmEnabled;
	extern BOOL parentFlag;
	extern u32 sessionGgid;
	extern BOOL sessionReady;
	extern u32 unused7E4;
	extern u32 beaconCount;
	extern BOOL fastTransfer;
	extern Heap* heap;
	extern BOOL multiBooting;
	extern BOOL communicating;
	extern BOOL multiBootEnded;
	extern OSTick connectionTimeout;
	extern BOOL communicatingConsoles[MaxConsoleCount];
	extern SharedData sendData;
	extern SharedData recvData[MaxConsoleCount];
	extern WMBssDesc parentsBssDesc[MaxParentScan];

}

