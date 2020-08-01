#ifndef NSMB_ACTOR_INCLUDED
#define NSMB_ACTOR_INCLUDED

#include "nitro_if.h"





struct Function {

	u32 functionTarget;		//Callback address or virtual function offset
	u32 callParams;			//Call parameters

	/*

		Call parameters are encoded as follows:
			0x00000001: Virtual function call flag: If set, functionTarget is interpreted as the virtual function table offset
			0xFFFFFFFE: Object offset: Determines the caller object by offsetting the object's current this pointer.

		A function is thereby called like:

			object = static_cast<u8*>(object) + (callParams >> 1); //Offset address by object offset

			if (entry->callParams & 1) {
				(**object + entry->functionTarget)(); //Call virtual function
			} else {
				entry->functionTarget(); //Call entry->functionTarget
			}

		WARNING: An object offset greater than 1GB leads to unpredictable results; The object offset is calculated with an arithmetic shift and any u32 values where the MSB is set are arithmetically shifted to the right, leading to faults.
	
	*/

};



struct ProcessNode {

	ProcessNode* previous;
	ProcessNode* next;
	Base* base;

	//0204d57c
	void unlink();

};



struct PriorityNode : public ProcessNode{

	u16 order;//Execute priority = class ID
	u16 order2;//Draw priority

	//0204d560
	void unlink();

};

struct LinkedList {

	ProcessNode* first;
	ProcessNode* last;

	//020438e8
	bool append(ProcessNode* node);

	//02043920
	bool remove(ProcessNode* node);

	//020438b0
	bool prepend(ProcessNode* node);

	//02043990
	bool insert(ProcessNode* node, ProcessNode* previous);

	//0204d428
	ProcessNode* getNodeByID(u32 id);


};

struct ProcessList : public LinkedList{

	Function executor;

	//0204d46c
	bool execute(); //Traverses the whole list and calls the executor on every node. Always returns true.

};


struct ProcessSet : public ProcessList{

	//0204d4e4
	bool add(PriorityNode* node);

};


//SceneNode
struct SceneNode {

	SceneNode* parent;		// 0
	SceneNode* firstChild;	// 4
	SceneNode* previous;		// 8
	SceneNode* next;			// C
	Base* obj;				// 10

	//02043b58
	SceneNode();

	//02043b40
	void reset();

	//02043a2c
	SceneNode* next(); //Returns the next tree's node or (if none could be found) the next parent's next node. May return null if no parent with siblings exists.

	//020439f0
	SceneNode* parentNext(); //Traverses the tree upwards and returns the next parent's next node. If no parent has siblings anymore, null is returned.

};

//SceneGraph
struct SceneGraph {

	SceneNode* root;
	Function executor;

	//02043acc
	bool addChild(SceneNode* child, SceneNode* parent); //Adds child to the scene graph as a child of parent. Returns true if the node was added successfully, false if node is null or if parent is null (indicating the root node) but root is already set.

	//02043a54
	bool removeChild(SceneNode* child); //Removes the child from the scene graph. Returns true only if child has no children itself, false otherwise.

};





struct ProcessLink {

	SceneNode linkConnect;		// 00
	PriorityNode linkExecute;	// 14
	PriorityNode linkDraw;		// 24
	ProcessNode linkIdLookup;	// 34

};



//vtable: 02085260
/*
0204d234:
0204d22c:
0204d1b8:
0204d1b0:
0204d174:
0204d0e0:
01ffd51c:
01ffd4f4:
01ffd4f0:
01ffd4e8:
01ffd4c0:
01ffd4bc:
0204d0dc:
0204cdbc:
0204ccec:
0204cce4:
pure virtual
0204d270: dtor_free
*/

class FrameHeap;

class Base
{
public:

	enum class ReturnState : u32 {
		PreFailed = 0,
		Failed,
		Success,
		Minus1	//WHEN???
	};

	enum class ObjectState : u32 {
		NotCreated = 0,
		Active,
		Dead
	};

	enum class ObjectType : u32 {
		Other = 0,//Effects???
		Scene,
		Actor
	};

	enum class ProfileStep : u8 {
		None = 0,
		LoadOverlay,
		SetParams,
		Construct,
		Create
	};

	typedef u32(OverlayLoadFunction*)(u16);//u32 loadOverlay(u16 objectID)
	typedef void(OverlayUnloadFunction*)(u16);//void unloadOverlay(u16 objectID)

	static ProfileStep debugProfileStep;
	static ObjectType spawnObjectType;
	static u16 debugProfileName;
	static u16 spawnObjectID;
	static SceneNode* spawnParentNode;
	static OverlayLoadFunction loadOverlay;
	static OverlayUnloadFunction unloadOverlay;
	static u32 spawnSettings;

	u32 unk04;//GUID
	u32 unk08;//Data?Settings?
	u16 unk0c;//Class ID
	ObjectState unk0e;//Object state
	bool destroy;//Destroy flag

	bool unk10;//Pending update registry
	bool unk11;//Pending create registry
	ObjectType unk12;//Object type
	u8 unk13;//Flags
	//0x01: Skip update children
	//0x02: Skip update
	//0x04: Skip render children
	//0x08: Skip render

	ProcessLink unk14;//Link

	u32 unk54;
	FrameHeap* unk58;

	//0204d2ac (C2, most likely protected)
	Base();

	//0204d23c (D2, D1 is pure??)
	//~Base();

	//0204cba0
	ReturnState processCreate();

	//01ffd22c
	ReturnState processUpdate();

	//01ffd1c8
	ReturnState processRender();

	//0204cb20
	ReturnState processDestroy();

	//01ffd524
	ReturnState process(Function callback, Function preCallback, Function postCallback);

	virtual s32 onCreate();
	virtual bool preCreate();
	virtual void postCreate(ReturnState state);
	virtual s32 onDestroy();
	virtual bool preDestroy();
	virtual void postDestroy(ReturnState state);
	virtual s32 onUpdate();
	virtual bool preUpdate();
	virtual void postUpdate(ReturnState state);
	virtual s32 onRender();
	virtual bool preRender();
	virtual void postRender(ReturnState state);
	//0x30
	virtual void pendingDestroy();//When the object is about to get destroyed
	//0x34
	//0x38
	//0204ccec
	virtual bool heapShit(u32 size, Heap* parent);//???
	//0204cdbc
	virtual bool moreHeapShit(u32 size, Heap* parent);//???
	//0204cce4
	virtual bool onHeapCreated();//???

	//0204cc04
	void create();

	//0204d08c
	void destroy();

	//0204cac0
	bool hasChildNotCreated();

	//D1 is null
	virtual ~Base();

	//0204d078
	Base* getParent(); //Null if root

	//0204cc98
	void* operator new(u32 size);

	//0204cc7c
	void operator delete(void* ptr);

	//0204ca80
	static void setSpawnParams(u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

	//0204c9a4
	static void spawn(u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

	//0204c974
	static u32 loadSceneOverlay(u16 objectID);

	//0204c948
	static void unloadSceneOverlay(u16 objectID);

	//0204c9a4
	static Base* spawn(u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

	//0204c920
	static Base* spawnChild(u16 objectID, Base* parent, u32 settings, ObjectType type);

	//0204c908
	static Base* spawnParent(u16 objectID, u32 settings, ObjectType type);

	//0204d174
	//0204d0e0
};




class Object : public Base 
{
public:

	//020131a8
	virtual void postCreate(ReturnState state) override;

	//D0:0201313c
	//D1:0201311c
	virtual ~Object() override;

	//02013168
	static Object* spawnScene(u16 objectID, u32 settings, ObjectType type);

	//02013188
	static Object* spawnObject(u16 objectID, Base* scene, u32 settings, ObjectType type);

};



class Scene : public Object
{
public:

	u32 unk5c;
	u32 unk60;

	//02013b2c
	Scene();

	//D2:020137b8

	//D0:020138dc
	//D1:02013a08
	virtual ~Scene() override;

	//02013764
	virtual bool preCreate() override;

	//02013718
	virtual void postCreate(ReturnState state);

	//020136e8
	virtual bool preDestroy();

	//020136c8
	virtual void postDestroy(ReturnState state);

	//02013500
	virtual bool preUpdate();

	//020134f4
	virtual void postUpdate(ReturnState state);

	//020134c4
	virtual bool preRender();

	//020134b8
	virtual void postRender(ReturnState state);


};



class Actor : public Object
{
public:

	static Vec3* spawnPosition;
	static S16Vec3* spawnRotation;
	static s8* spawnPlayerLink;
	static fx32* spawnScale;

	Vec3 unk5c;//Position
	Vec3 unk6c;//LastPosition
	Vec3 unk7c;//LastStep
	Vec3 unk8c;//CenterOffset from Position
	S16Vec3 unk9c;//Rotation
	S16Vec3 unka8;
	u32 unkb4;
	u32 unkb8;
	u32 unkbc;
	u32 unkc0;
	u32 unkc4;//LeftoverVelocity
	u32 unkc8;
	Vec3 unkcc;//Velocity
	Vec3 unkdc;//MaxVelocity
	Vec3 unkec;//Render scale
	Vec3 unkfc;
	Vec3 unk10c;
	u8 unk11c;
	bool unk11d;//Visible
	s8 unk11e;//Linked player ID
	u8 unk11f;

	//020a0edc
	Actor();

	//D0:020a0e04
	//D1:020a0e74
	virtual ~Actor();

	//D2:020a0d9c

	//020a0d7c
	virtual bool preCreate() override;

	//020a0d70
	virtual void postCreate(ReturnState state) override;

	//020a0d50
	virtual bool preDestroy() override;

	//020a0d44
	virtual void postDestroy(ReturnState state) override;

	//020a0cac
	virtual bool preUpdate() override;

	//020a0ca0
	virtual void postUpdate(ReturnState state) override;

	//020a0c48
	virtual bool preRender() override;

	//020a0c3c
	virtual void postRender(ReturnState state) override;

	//0201ff68
	virtual void setX(fx32 x);//U SURE???

	//0201ff70
	virtual void moveX(fx32 offset);//U SURE???

	//020a0bf8
	u32 getActorCount(u16 objectID);

	//020a0bb8
	static void setSpawnParams(Vec3* position, S16Vec3* rotation, fx32* scale, s8* playerLink);

	//020a0b64
	static Actor* spawnActor(u16 objectID, u32 settings, Vec3* position, S16Vec3* rotation, fx32* scale, s8* playerLink);

	//020a0b5c
	void setPlayerLink(s8 playerLink);



	//020a0aac
	void move(Vec3* velocity);//IN THIS CLASS???


};




class StageActor : public Actor 
{
public:

	//ActivePhysics unk120;
	//Collider unk1d0;
	//AnotherColliderClass unk288;
	//LOL unk2bc;

	//020a127c
	StageActor();

	//D0:020a11ec
	//D1:020a1238
	virtual ~StageActor();

	//D2:020a11a8

	//020a1154
	virtual bool preUpdate() override;

	//020a10f0
	virtual void postUpdate(ReturnState state) override;

	//020a10a0
	//???

};




class Enemy : public StageActor
{
public:




};




class Class20c6eb4 : public Object
{
public:

	MtxFx44 unk5c;
	MtxFx43 unk9c;

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~Class20c6eb4();


};


class Class2123d10 : public Class20c6eb4
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	S16Vec3 unkfc;

	//D0:020ce734
	//D1:020ce6dc
	virtual ~Class2123d10();

};




class WorldCamera : public Class2123d10
{
public:

	Function unk108;
	Vec3 unk110;

	//C3:020ce658
	Camera();

	//020ce540
	virtual s32 onCreate() override;

	//020ce42c
	virtual s32 onUpdate() override;

	//020ce46c
	virtual s32 onRender() override;



};



class Class21bf91c : public Class20c6eb4
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	S16Vec3 unkfc;

	//D0:021b8c2c
	//D1:021b8bd4
	virtual ~Class21bf91c();

};



class TitleScreenCamera : public Class21bf91c
{
public:

	//C3:021b8b54
	TitleScreenCamera();

	//D0:021b8718
	//D1:021b86b4
	virtual ~TitleScreenCamera();

	//021b8948
	virtual s32 onCreate() override;

	//021b8830
	virtual s32 onUpdate() override;

	//021b8874
	virtual s32 onRender() override;


};



struct ProcessManager {

	enum class ProcessListType : u32 {
		None = 0,
		Connect,
		Create,
		Update,
		Delete,
		Render
	};

	//0204d598
	void updateProcessLists();

	//0204d630
	Base* getNextObjectByType(ObjectType type, Base* object);

	//0204d6fc
	SceneNode* getNextNodeByType(SceneGraph* scene, ObjectType type, SceneNode* node);

	//0204d630
	Base* getNextObjectByObjectID(u16 objectID, Base* object);

	//0204d6fc
	SceneNode* getNextNodeByObjectID(SceneGraph* scene, u16 objectID, SceneNode* node);

	//0204d6a8
	Base* getObjectByID(u32 id);

	//0204d6dc
	u32 getIDIndex(ProcessLink* link);

	//0204d6ec
	const char* getProcessListName(ProcessListType type);

	//0204d7b4 TODO FIX NAME BRUV
	bool updateSceneGraph(SceneGraph* scene); //Traverses the graph and calls the executor on every node. Always returns true.

};



namespace Game {

	//020852a8
	u32 currentExecutingProcessList;

	//0208fb08
	ProcessNode* currentProcessNode;
	//ALL IN BSS BRUH
	//0208fb0c
	SceneGraph actorTree;

	//0208fb18
	ProcessSet executeProcess;

	//0208fb28
	ProcessList deleteProcess;

	//0208fb38
	ProcessSet renderProcess;

	//0208fb48
	ProcessList createProcess;

	//0208fb58
	LinkedList idLookupProcesses[8];

	//02085224
	u32 nextFreeID;

	//0202614c
	void initProcessLists(); //STATIC CTOR

	//0208027c
	const char* processListNames[6];

	//020852b4
	const char processListNameNull[5];

	//020852ec
	const char processListNameConnect[8];

	//020852c4
	const char processListNameCreate[7];

	//020852f4
	const char processListNameExecute[8];

	//020852bc
	const char processListNameDelete[7];

	//020852ac
	const char processListNameDraw[5];

	//020852cc
	Function renderProcessFunction;//TO

	//020852d4
	Function sceneProcessFunction; //NAME???TO

	//020852dc
	Function createProcessFunction;//TO

	//020852e4
	Function deleteProcessFunction;//TO

	//02085238
	Function preCreateFunction;

	//02085240
	Function onCreateFunction;

	//02085228
	Function postCreateFunction;

	//01ffd1b8
	Function preUpdateFunction;

	//01ffd1b0
	Function onUpdateFunction;

	//01ffd198
	Function postUpdateFunction;

	//01ffd1a8
	Function preRenderFunction;

	//01ffd1a0
	Function onRenderFunction;

	//01ffd1c0
	Function postRenderFunction;

	//02085248
	Function preDestroyFunction;

	//02085230
	Function onDestroyFunction;

	//02085250
	Function postDestroyFunction;

}




#endif	// NSMB_ACTOR_INCLUDED
