#pragma once

#include "task.hpp"


namespace Net {

	enum class PacketTransferType : u8 {
		Sync,
		FastOrdered,
		FastUnordered
	};

	enum class PacketFastTransfer : u8 {
		Done,
		FastOrdered,
		FastUnordered
	};

	enum class PacketTransferIntegrity : u8 {
		None,
		PacketStreamIntegrity, // Raises an error if the packet stream is interrupted.
		PacketOrderIntegrity   // Raises an error also if the packet sequence doesn't match.
	};

	namespace Core {

		void taskManagerProc();

		void startTaskManager();

		void stopTaskManager();


		void revertTaskFastTransfer();

		void setFastTransfer(PacketFastTransfer type);

		void selectFastTransfer();

		void selectSyncTransfer();

	}


	void scheduleTask(TaskFunction func, void* arg, u32 timeout, PacketFastTransfer fastTransfer);

	BOOL isTaskDone(s32 taskID);

	void revertFastTransfer(PacketFastTransfer type);

	void setTaskFastTransfer();


	extern bool taskManagerActive;
	extern bool packetOrderStability;
	extern PacketTransferType packetTransType;
	extern PacketTransferIntegrity packetTransIntegrity;
	extern PacketFastTransfer packetFastTrans;
	extern bool taskManagerBusy;


	NTR_INLINE bool isTransferStable() {
		return packetTransIntegrity == PacketTransferIntegrity::PacketOrderIntegrity;
	}

}
