#pragma once

#include "types.hpp"
#include "nsmb/system/memory.hpp"

namespace Net {

	constexpr u32 TaskCount = 4;
	constexpr s32 TaskAll = -1;
	constexpr s32 TaskInvalid = -1;

	using TaskFunction = void(*)(void* arg);

	class Task {
	public:

		enum State {
			Invalid,
			Scheduled,
			Consumed
		};


		BOOL expired() const;


		OSTick start;
		void* callback;
		void* callbackArg;
		u32 timeout;
		State state;

	};
	NTR_SIZE_GUARD(Task, 0x18);

	class TaskManager {
	public:

		TaskManager();


		s32 scheduleTask(TaskFunction func, void* arg, u32 timeout);

		void execute();

		void clearTask(u32 taskID);

		BOOL validateTask(u32 taskID);

		BOOL validateAllTasks();


		Task tasks[TaskCount];
		u32 scheduledTaskID;
		u32 consumedTaskID;

	};
	NTR_SIZE_GUARD(TaskManager, 0x68);


	extern Heap* taskManagerHeap;
	extern u8* taskManagerStack;
	extern OSMessage taskManagerMsgPool[5];
	extern OSMutex taskManagerMutex;
	extern OSMessageQueue taskManagerMsgQueue;
	extern TaskManager taskManager;
	extern OSThread taskManagerThread;

}
