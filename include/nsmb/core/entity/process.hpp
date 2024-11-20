#pragma once

#include "common.hpp"
#include "list.hpp"

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
	void updateProcessLists();

	//0204d630
	Base* getNextObjectByType(ObjectType type, const Base* object = nullptr);

	//0204d66c
	Base* getNextObjectByObjectID(u16 objectID, const Base* object = nullptr);

	template<class T>
	T* getNextObject(const T* object = nullptr) {
		return static_cast<T*>(getNextObjectByObjectID(T::ObjectID, object));
	}

	//0204d6a8
	Base* getObjectByID(u32 id);

	//0204d6dc
	u32 getIDIndex(const ProcessLink& link);

	//0204d6ec
	const char* getProcessListName(ProcessListType type);

	//0204d6fc
	SceneNode* getNextNodeByType(SceneGraph* scene, ObjectType type, const SceneNode* node);

	//0204d758
	SceneNode* getNextNodeByObjectID(SceneGraph* scene, u16 objectID, const SceneNode* node);

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
