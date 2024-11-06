#pragma once

#include "types.hpp"

namespace Net {

	using OnPacketPolling = void(*)();
	using OnConnectionError = void(*)();
	using OnRenderSignalStrength = void(*)(u16 charName, u16 paletteID);

	// TODO: Check all names, document missing bits!!!
	enum class ErrorState : u16 {
		ParentEntryError = 0x1,
		MultiBootParentLost = 0x2,
		SilentError = 0x4, // Does not trigger the OnConnectionError handler.
		ChildDisconnect = 0x8,
		ParentError = 0x10,
		LocalError = 0x20,
		ChildDesync = 0x80,
		Console0Disconnect = 0x100,
		Console1Disconnect = 0x200,
		Console2Disconnect = 0x400,
		Console3Disconnect = 0x800,
		MultiBootFailed = 0x1000,
		// Runtime_WFS_Error = 0x2000,
		FatalDataStreamInterruption = 0x4000,
		Timeout = 0x8000,
	};

	enum class ConnectionState : u8 {
		Stopped,
		ParentMultiBoot,
		FakeChildScan,
		ParentBroadcast,
		ChildScan,
		Synchronizing,
		SyncTransfer,
		FastTransfer,
		Unused,
		Error
	};

	enum class SessionState : u8 {
		Waiting,
		Synchronize,
		Complete,
		Invalid
	};

	enum class ConsoleState : u8 {

	};
	NTR_CREATE_BITMASK_ENUM(ConsoleState);

	enum class ModuleState : u8 {
		ModuleInit = 0x2,
		HandlerSet = 0x4,
		FullyInit = ModuleInit | HandlerSet
	};
	NTR_CREATE_BITMASK_ENUM(ModuleState);

	enum class ProgramTransferFlags : u32 {
		None = 0x0,
		ParentSynchronizing = 0x1,
		FastTransferOrdered = 0x2,
		FastTransferUnordered = 0x4,
		TransferDone = 0x8,
		MultiBootStarving = 0x10
	};

	struct MultiBootUserParam {
		u8 language;
		u8 character;
	};

	namespace Core {

		void childScanState();

		void fastTransferState();

		ProgramTransferFlags transferPacket(PacketAction action);

		void pairConsoles();

		void stabilizeTransfer();

		void setConnectionState(ConnectionState state);

		BOOL startChildScan();

		void resetSessionInfo(BOOL populateParentInfo);

		void readUserInfo(MBUserInfo* userInfo);

		void stopConnection();

		void resetConnection();

		WMBssDesc* getParentBssDesc(u32 parentIndex);

		void beginSynchronization();

		void beginSyncTransfer();

	}

	void initialize(s8 maxConsoles);

	void setHandlers(OnPacketPolling packetPolling, OnConnectionError connectionError, OnRenderSignalStrength renderSignalStrength);

	void updatePacket();

	void update();


	BOOL initializeWireless();

	BOOL shutdownWireless();


	BOOL connectToParent(u32 parentIndex);


	extern u8 multiBootParentBssid[WM_SIZE_BSSID];

	extern u8 currentLanguage;
	extern u8 localAid;
	extern ConnectionState connectionState;
	extern u8 connectedConsoleCount;
	extern u8 expectedConsoleCount;
	extern bool multiBootSession;
	extern SessionState sessionState;
	extern ModuleState moduleState;
	extern u8 maxSessionChildren;
	extern u8 unused820;
	extern u8 unused824;
	extern u8 unused828;
	extern u8 maxConsoleCount;
	extern u8 unused834;
	extern u8 unused838;
	extern ErrorState errorState;
	extern u16 packetTick;
	extern u16 timeoutTimer;
	extern u16 unused848;
	extern MultiBootUserParam multiBootDownloadParam;
	extern MBPChildInfo* consoleGameInfos;
	extern ConsoleState* consoleStates;
	extern u32 ggid;
	extern OnPacketPolling onPacketPolling;
	extern OnConnectionError onConnectionError;
	extern OnRenderSignalStrength onRenderSignalStrength;
	extern u32 syncCount;
	extern Packet sendPacket;

	NTR_INLINE bool isConnected() {
		return connectionState != ConnectionState::Stopped && connectionState != ConnectionState::Unused && connectionState != ConnectionState::Error;
	}

}
