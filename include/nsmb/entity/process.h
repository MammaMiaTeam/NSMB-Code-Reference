#pragma once
#include "common.h"
#include "list.h"

struct ObjectProfile;


struct ProcessLink {

	SceneNode linkConnect;
	PriorityNode linkExecute;
	PriorityNode linkDraw;
	ProcessNode linkIdLookup;

};


enum class ProcessListType : u32 {
	None = 0,
	Connect,
	Create,
	Update,
	Delete,
	Render
};


namespace ProcessManager {

	//0204d598
	ssym void updateProcessLists() __body

	//0204d630
	ssym Base* getNextObjectByType(ObjectType type, const Base* object = nullptr) __rbody

	//0204d66c
	ssym Base* getNextObjectByObjectID(u16 objectID, const Base* object = nullptr) __rbody

	template<class T>
	T* getNextObject(const T* object = nullptr) {
		return static_cast<T*>(getNextObjectByObjectID(T::objectID, object));
	}

	//0204d6a8
	ssym Base* getObjectByID(u32 id) __rbody

	//0204d6dc
	ssym u32 getIDIndex(const ProcessLink& link) __rbody

	//0204d6ec
	ssym const char* getProcessListName(ProcessListType type) __rbody

	//0204d6fc
	ssym SceneNode* getNextNodeByType(SceneGraph* scene, ObjectType type, const SceneNode* node) __rbody

	//0204d758
	ssym SceneNode* getNextNodeByObjectID(SceneGraph* scene, u16 objectID, const SceneNode* node) __rbody

};



namespace Game {

	// DATA

	//0203997c
	extern ObjectProfile* mainProcessTable[385];

	//0208fb98
	extern ObjectProfile** currentProcessTable;

	//020852a8
	extern u32 currentExecutingProcessList;

	//020852cc
	extern BaseProcessFunction renderProcessFunction;

	//020852d4
	extern BaseProcessFunction sortProcessFunction;

	//020852dc
	extern BaseProcessFunction createProcessFunction;

	//020852e4
	extern BaseProcessFunction deleteProcessFunction;

	//020852fc
	extern BaseProcessFunction updateProcessFunction;

	// BSS

	//0208fb08
	extern ProcessNode* currentProcessNode;

	//0208fb0c
	extern SceneGraph actorTree;

	//0208fb18
	extern ProcessSet executeProcess;

	//0208fb28
	extern ProcessList deleteProcess;

	//0208fb38
	extern ProcessSet renderProcess;

	//0208fb48
	extern ProcessList createProcess;

	//0208fb58
	extern LinkedList idLookupProcesses[8];

	//0208027c
	extern const char* processListNames[6];

}
