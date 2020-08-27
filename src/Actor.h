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
	~Base();

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

	constexpr u16 noScene = 0x181;

	u32 wifiIconOBJIndex;
	u32 wifiIconOBJPalette;

	//0203bd28
	static bool isSceneActive;

	//0203bd2c
	static u16 previousSceneID;

	//0203bd30
	static u16 nextSceneID;

	//0203bd34
	static u16 currentSceneID;

	//02088f38
	static u32 nextSceneSettings;

	//02013b2c
	Scene();

	//D2:020137b8

	//D0:020138dc
	//D1:02013a08
	virtual ~Scene() override;

	//02013764
	virtual bool preCreate() override;

	//02013718
	virtual void postCreate(ReturnState state) override;

	//020136e8
	virtual bool preDestroy() override;

	//020136c8
	virtual void postDestroy(ReturnState state) override;

	//02013500
	virtual bool preUpdate() override;

	//020134f4
	virtual void postUpdate(ReturnState state) override;

	//020134c4
	virtual bool preRender() override;

	//020134b8
	virtual void postRender(ReturnState state) override;

	//020133a4
	static void prepareFirstScene();

	//020132a0
	static u16 tryChangeScene();

	//020131fc
	static void switchScene(u16 sceneID, u32 settings);

	//020131d8
	static void switchToFileCorruptedScene(u32 settings);

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



class FadeMask
{
public:

	Model models[10];

	enum class Shape : u8 {
		Circle = 0,
		FadeCircle,
		Bowser,
		Mario,
		Luigi,
		Wario,
		Yoshi,
		Star,
		SlideDown,
		SlideUp
	};

	enum class Mode : u8 {
		??? = 0,
		Center,
		Invalid,
		???,
		???,
		???
	};

	//02026634
	static u32 modelIDs[10];

	//0203bd88
	static FadeMask::Shape characterFadeMaskIDs[2];

	//02014170
	FadeMask();

	//D0:02014100
	//D1:0201413c
	virtual ~FadeMask();

	//020140a0
	bool loadModels();

	//02013c00
	void updateTransition(Shape shape, VecFx32* scale, GXRgb diffuse, s32 alpha, Mode mode);

	//02013bdc
	static bool loadMaskModelFile();

	//02013bd0
	bool loadMaskModels();

	//02013ba8
	bool update(Shape shape, VecFx32* scale, GXRgb diffuse, s32 alpha, Mode mode);

	//02013b98
	static u8 getCharacterFadeMaskID(u8 character);

};




class Fader
{
public:

	enum class FadingType : u8 {
		FadeOnly = 0,
		StaticMask,
		FadeMask
	};

	enum class StaticMask : u8 {
		Rectangle,
		Rhombus,
		Circle
	};

	//02085c38
	static u8 staticMask[0xC0];

	//02039f80
	static fx32 staticCircleBounds[0xC0];//Used to generate the static circle mask

	//02085a28
	static u32 activeFadeMasks;//Bit0&1

	//02085c28
	static u32 fadeFrames;//Custom fade frames for scenes taking other than 0x20

	//02085c24
	static u32 alphaBlendingPlane1;

	//02085c34
	static u32 alphaBlendingPlane2;

	//02085c30
	static u32 alphaBlendingEVA;

	//02085c2c
	static u32 alphaBlendingEVB;

	FadeMask mask;
	s32 unk5a4;//Target blend brightness
	FadeMask::Mode unk5a8;//Fading mode
	fx32 unk5ac[2];//Blend brightness factor 0-1
	fx32 unk5b4[2];//Blend brightness factor increment
	u8 unk5bc[2];//Flag targets:1=fade mainscreen;2=fade subscreen
	u8 unk5be[2];//Ugh fade flags:
				/*
					0x01: Fading in
					0x02: Started fade-in
					0x04: Initiated fade-in
					0x08: Fading out
					0x10: Started fade-out
					0x20: Initiated fade-out
					0x40: Faded out (scale reached 0x1000)
				*/
	u8 unk5c0[2];//Fading mask transition shape
	FadingType unk5c2;//Fading type
	u8 unk5c3;//Screen enable delay
	u8 unk5c4;//Unknown
	bool unk5c5;//Fading stopped

	//02008558
	Fader();

	//02003090
	~Fader();

	//020083cc
	void setupSceneFading(FadingType type, bool fadeBright, bool staticBlend);

	//02007f70
	void fade();

	//02007e34
	bool startFadeIn(u32 steps, u8 target);

	//02007df0
	bool tryFadeOut();//True if faded out or no fading was pending

	//02007cf8
	bool startFadeOut(u32 steps, u8 target);

	//02007cb0
	bool fadedIn();

	//02007c68
	bool fadedOut();

	//02007c44
	void enableMainScreenFading();

	//02007c20
	void disableMainScreenFading();

	//02007bfc
	void enableSubScreenFading();

	//02007bd8
	void disableSubScreenFading();

	//02007bb4
	void prepareFadeIn();

	//02007b90
	void prepareFadeOut();

	//02007af8
	static void hBlankIrqHandler();//Only used by non-rectangular masks

	//02007970
	void setupStaticMask(u8 flags, u8 target);

	//020076ac
	void updateStaticMask(u8 target);

};




class Camera : public Object
{
public:

	MtxFx44 unk5c;
	MtxFx43 unk9c;

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~Camera();


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




class StageCamera : public Class2123d10
{
public:

	Function unk108;//State function
	Vec3 unk110;
	u32 unk120;//Current state index
	u32 unk124;//Execute pre-state bool
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;//Unused

	//C3:020ce658
	StageCamera();

	//020ce540
	virtual s32 onCreate() override;

	//020ce42c
	virtual s32 onUpdate() override;

	//020ce46c
	virtual s32 onRender() override;



};


//ov9
class Class21bf91c : public Class20c6eb4
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	S16Vec3 unkfc;

	//D0:0x020D3E4C
	//D1:0x020D3DF4
	virtual ~Class21bf91c();

};


//ov9
class TitleScreenCamera : public Class21bf91c
{
public:

	//C3:0x020D3D74
	TitleScreenCamera();

	//D0:0x020D3938
	//D1:0x020D38D4
	virtual ~TitleScreenCamera();

	//0x020D3B68
	virtual s32 onCreate() override;

	//0x020D3A50
	virtual s32 onUpdate() override;

	//0x020D3A94
	virtual s32 onRender() override;

	//0x020D39A4
	void setOrtho(fx32 r, fx32 t, fx32 b, fx32 l);

};


//ov8
class Class21a5300 : public Camera
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	S16Vec3 unkfc;

	//D0:0218cd58
	//D1:0218cd00
	virtual ~Class21a5300();

};



class WorldCamera : public Class21a5300
{
public:

	Function unk108;
	u32 unk110;
	u32 unk114;
	u32 unk118;
	u32 unk11c;


	//C3:0218cc80
	WorldCamera();

	//D0:0218c628
	//D1:0218c5c4
	virtual ~WorldCamera();

	//0218ca00
	virtual s32 onCreate() override;

	//0218c73c
	virtual s32 onUpdate() override;

	//0218c92c
	virtual s32 onRender() override;


};




class WorldMapCamera : public Class21a5300
{
public:

	Function unk108;//State function
	u32 unk110;//State
	u32 unk114;//Setup state bool
	Vec3 unk118;
	Vec3 unk128;//Light Position
	Vec3 unk138;//Physical camera position
	u32 unk148;//Zoom state (0 = in, 1 = out)
	fx32 unk14c;//FovY (in degrees / 2)
	fx32 unk150;//Left camera view x clamp
	fx32 unk154;//Right camera view x clamp
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;

	//021a65b0
	static VecFx32 worldLightPositions[8];

	//021a60d4
	static fx32 worldBoundaries[8][2];

	//021a864c
	static fx32 fovySineTable[450];//I don't wanna say anything to this.

	//021a48cc
	static void initStates();


	//C3:02191958
	WorldMapCamera();

	//D0:02190f74
	//D1:02190f04
	virtual ~WorldMapCamera();

	//0219168c
	virtual s32 onCreate() override;

	//02191244
	virtual s32 onUpdate() override;

	//021915b8
	virtual s32 onRender() override;

	//02191060
	void setState(u32 state);

	//02190fec
	void runState();

};




class EndingCamera : public Class21a5300
{
public:

	Function unk108;
	Vec3 unk110;
	u32 unk120;
	u32 unk124;
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;

	//C3:0219e068
	EndingCamera();

	//D0:0219db2c
	//D1:0219dac4
	virtual ~EndingCamera();

	//0219deb8
	virtual s32 onCreate() override;

	//0219ddc8
	virtual s32 onUpdate() override;

	//0219dde4
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

	//02088f48
	Fader fader;

	//02085b14
	Fader* activeFader;

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
