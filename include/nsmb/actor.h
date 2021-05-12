#ifndef NSMB_ACTOR_H_
#define NSMB_ACTOR_H_

#include "nitro_if.h"
#include "nsmb/memory.h"
#include "nsmb/vector.h"
#include "nsmb/model.h"

#include "nsmb/misc.h"


class Object;
class Base;
class Actor;
class StageActor;

struct ProcessNode {

	ProcessNode* previous;
	ProcessNode* next;
	Base* base;

	//0204d57c
	GEN_FUNC(void unlink);

};



struct PriorityNode : public ProcessNode {

	u16 order;//Execute priority = class ID
	u16 order2;//Draw priority

	//0204d560
	GEN_FUNC(void unlink);

};



struct SceneNode {

	SceneNode* parent;		// 0
	SceneNode* firstChild;	// 4
	SceneNode* previous;		// 8
	SceneNode* next_;			// C
	Base* obj;				// 10

	//02043b58
	GEN_FUNC( SceneNode );

	//02043b40
	GEN_FUNC( void reset );

	//02043a2c
	GEN_FUNC( SceneNode* next ); //Returns the next tree's node or (if none could be found) the next parent's next node. May return null if no parent with siblings exists.

	//020439f0
	GEN_FUNC( SceneNode* parentNext ); //Traverses the tree upwards and returns the next parent's next node. If no parent has siblings anymore, null is returned.

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

	enum class ObjectState : u8 {
		NotCreated = 0,
		Active,
		Dead
	};

	enum class ObjectType : u8 {
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

	typedef s32(Base::*ProcessFunction)();
	typedef bool(Base::*PreFunction)();
	typedef s32(Base::*OnFunction)();
	typedef void(Base::*PostFunction)(ReturnState);

	typedef u32(*OverlayLoadFunction)(u16);//u32 loadOverlay(u16 objectID)
	typedef void (*OverlayUnloadFunction)(u16);//void unloadOverlay(u16 objectID)

	// 0208fae8
	static ProfileStep debugProfileStep;
	// 0208faec
	static ObjectType spawnObjectType;
	// 0208faf0
	static u16 debugObjectID;
	// 0208faf4
	static u16 spawnObjectID;
	// 0208faf8
	static SceneNode* spawnParentNode;
	// 0208fafc
	static OverlayLoadFunction loadOverlay;
	// 0208fb00
	static OverlayUnloadFunction unloadOverlay;
	// 0208fb04
	static u32 spawnSettings;

	u32 guid;//GUID
	u32 settings;//Data?Settings?
	u16 id;//Class ID
	ObjectState state;//Object state
	bool destroy_;//Destroy flag

	bool unk10;//Pending update registry
	bool unk11;//Pending create registry
	ObjectType type;//Object type
	u8 flags;//Flags
	//0x01: Skip update children
	//0x02: Skip update
	//0x04: Skip render children
	//0x08: Skip render

	ProcessLink link;//Link

	u32 unk54; // unused (debug leftover?)
	FrameHeap* unk58; // internal heap (???)

	//0204d2ac (C2, most likely protected)
	GEN_FUNC( Base )

	//0204d23c (D2, D1 is pure??)
	//~Base();

	//0204cba0
	GEN_FUNC(ReturnState processCreate);

	//01ffd22c
	GEN_FUNC(ReturnState processUpdate);

	//01ffd1c8
	GEN_FUNC(ReturnState processRender);

	//0204cb20
	GEN_FUNC(ReturnState processDestroy);

	//01ffd524
	GEN_FUNC(ReturnState process, OnFunction callback, PreFunction preCallback, PostFunction postCallback);

	GEN_FUNC( virtual s32 onCreate );
	GEN_FUNC( virtual bool preCreate );
	GEN_FUNC( virtual void postCreate, ReturnState state);
	GEN_FUNC( virtual s32 onDestroy );
	GEN_FUNC( virtual bool preDestroy );
	GEN_FUNC( virtual void postDestroy, ReturnState state);
	GEN_FUNC( virtual s32 onUpdate );
	GEN_FUNC( virtual bool preUpdate );
	GEN_FUNC( virtual void postUpdate, ReturnState state);
	GEN_FUNC( virtual s32 onRender );
	GEN_FUNC( virtual bool preRender );
	GEN_FUNC( virtual void postRender, ReturnState state);
	//0x30
	GEN_FUNC( virtual void pendingDestroy );//When the object is about to get destroyed
	//0x34
	//0x38
	//0204ccec
	GEN_FUNC( virtual bool heapShit, u32 size, Heap* parent);//???
	//0204cdbc
	GEN_FUNC( virtual bool moreHeapShit, u32 size, Heap* parent);//???
	//0204cce4
	GEN_FUNC( virtual bool onHeapCreated );//???

	//0204cc04
	GEN_FUNC(void create);

	//0204d08c
	GEN_FUNC(void destroy)

	//0204cac0
	GEN_FUNC(bool hasChildNotCreated);

	//D1 is null
	GEN_FUNC( virtual ~Base )

	//0204d078
	GEN_FUNC( Base* getParent); //Null if root

	//0204cc98
	GEN_FUNC(void* operator new,size_t size);

	//0204cc7c
	GEN_FUNC(void operator delete,void* ptr);

	//0204ca80
	GEN_FUNC(static void setSpawnParams,u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

	//0204c974
	GEN_FUNC(static u32 loadSceneOverlay,u16 objectID);

	//0204c948
	GEN_FUNC(static void unloadSceneOverlay,u16 objectID);

	//0204c9a4
	GEN_FUNC(static Base* spawn,u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

	//0204c920
	GEN_FUNC(static Base* spawnChild,u16 objectID, Base* parent, u32 settings, ObjectType type);

	//0204c908
	GEN_FUNC(static Base* spawnParent,u16 objectID, u32 settings, ObjectType type);

};




class Object : public Base
{
public:

	inline Object() {}

	//020131a8
	GEN_FUNC( virtual void postCreate, ReturnState state) //override;

	//D0:0201313c
	//D1:0201311c
	GEN_FUNC( virtual ~Object ) //override;

	//02013168
	GEN_FUNC( static Object* spawnScene, u16 objectID, u32 settings, ObjectType type);

	//02013188
	GEN_FUNC( static Object* spawnObject, u16 objectID, Base* scene, u32 settings, ObjectType type);


	template<class T>
	static Object* constructObject() {
		return new T();
	}

};

struct ObjectProfile {
	Object* (*constructor)();
	u16 order1;
	u16 order2;
};

struct ActorProfile : public ObjectProfile {
	bool (*loadResources)();
};


class Scene : public Object
{
public:

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
	GEN_FUNC(Scene);

	//D2:020137b8

	//D0:020138dc
	//D1:02013a08
	GEN_FUNC(virtual ~Scene ) ////override;

	//02013764
	GEN_FUNC(virtual bool preCreate ) //override;

	//02013718
	GEN_FUNC(virtual void postCreate, ReturnState state) //override;

	//020136e8
	GEN_FUNC(virtual bool preDestroy ) //override;

	//020136c8
	GEN_FUNC(virtual void postDestroy, ReturnState state) //override;

	//02013500
	GEN_FUNC(virtual bool preUpdate, ) //override;

	//020134f4
	GEN_FUNC(virtual void postUpdate, ReturnState state) //override;

	//020134c4
	GEN_FUNC(virtual bool preRender ) //override;

	//020134b8
	GEN_FUNC(virtual void postRender, ReturnState state) //override;

	//020133a4
	GEN_FUNC(static void prepareFirstScene );

	//020132a0
	GEN_FUNC(static u16 tryChangeScene );

	//020131fc
	GEN_FUNC( static void switchScene, u16 sceneID, u32 settings)

	//020131d8
	GEN_FUNC( static void switchToFileCorruptedScene, u32 settings);

};


struct SceneID {
	enum : u16 {
		Boot,
		Connect,
		Debug,
		Stage,
		TitleScreen,
		MvsLSetup,
		MvsLMainMenu,
		Save,
		World,
		Worldmap,
		MvsLResults,
		CorruptedSave,
		Ending,
		StageIntro,
		GameOver,
		MvsLStageIntro,
		SoundTest,
		Key,

		Max,
		Invalid = 0x0181,
	};
};


enum ActorType : u8 {
	ActorType_None,
	ActorType_Player,
	ActorType_Actor,
	ActorType_Overlay,
};

enum StageUnitCategory : u8 {
	StageUnitCategory_None				= (1 << 0),
	StageUnitCategory_Player			= (1 << 1),
	StageUnitCategory_Actor				= (1 << 2),
	StageUnitCategory_Overlay			= (1 << 3),
	StageUnitCategory_StageForeground	= (1 << 5),
	StageUnitCategory_StageOverlay		= (1 << 6),
	StageUnitCategory_StageEntity		= (1 << 7)
};

class Actor : public Object
{
public:

	// 020ca85c
	static Vec3* spawnPosition;
	// 020ca860
	static Vec3s* spawnRotation;
	// 020ca864
	static s8* spawnPlayerLink;
	// 020ca868
	static fx32* spawnScale;

	Vec3 position;//Position
	Vec3 lastPosition;//LastPosition
	Vec3 lastStep;//LastStep
	Vec3 centerOffset;//CenterOffset from Position
	Vec3s rotation;//Rotation
	Vec3s lastRotation;
	fx32 velH;
	fx32 velHMin;
	fx32 velVStep;
	fx32 velVMin;
	fx32 velHStep;//LeftoverVelocity
	u32 unkC4;
	Vec3 velocity;//Velocity
	Vec3 targetVelocity;//MaxVelocity
	Vec3 scale;//Render scale
	Vec3 accel;
	Vec3 velocityLimit;
	ActorType actorType;
	bool visible;//Visible
	s8 linkPlayerNo;//Linked player ID
	StageUnitCategory actorCategory;

	//020a0edc
	GEN_FUNC( Actor )

	//D0:020a0e04
	//D1:020a0e74
	GEN_FUNC( virtual ~Actor )

	//D2:020a0d9c

	//020a0d7c
	GEN_FUNC( virtual bool preCreate ) //override;

	//020a0d70
	GEN_FUNC( virtual void postCreate, ReturnState state) //override;

	//020a0d50
	GEN_FUNC( virtual bool preDestroy ) //override;

	//020a0d44
	GEN_FUNC( virtual void postDestroy, ReturnState state) //override;

	//020a0cac
	GEN_FUNC( virtual bool preUpdate ) //override;

	//020a0ca0
	GEN_FUNC( virtual void postUpdate, ReturnState state) //override;

	//020a0c48
	GEN_FUNC( virtual bool preRender ) //override;

	//020a0c3c
	GEN_FUNC( virtual void postRender, ReturnState state ) //override;

	//0201ff68
	GEN_FUNC( virtual void setX, fx32 x);//U SURE???

	//0201ff70
	GEN_FUNC( virtual void moveX, fx32 offset);//U SURE???

	//020a0bf8
	GEN_FUNC(u32 getActorCount,u16 objectID);

	//020a0bb8
	GEN_FUNC(static void setSpawnParams,Vec3* position, Vec3s* rotation, fx32* scale, s8* playerLink);

	//020a0b64
	GEN_FUNC(static Actor* spawnActor, u16 objectID, u32 settings, Vec3* position, Vec3s* rotation = nullptr, fx32* scale = nullptr, s8* playerLink = nullptr)

	//020a0b5c
	GEN_FUNC( void setPlayerLink,s8 playerLink);



	//020a0aac
	GEN_FUNC( void move,Vec3* velocity);//IN THIS CLASS???


};


class ActiveCollider;
class CollisionMgr;
class PlatformMgr;

class StageActor : public Actor
{
public:

	ActiveCollider activeCollider;
	CollisionMgr collisionMgr;
	PlatformMgr platformMgr;

	u8 unk0;
	u8 direction; // 0=right, 1=left
	u8 viewID;
	u8 unk3;
	u32 preUpdatePassed;

	//ActivePhysics unk120;
	//Collider unk1d0;
	//AnotherColliderClass unk288;
	//LOL unk2bc;

	//020a127c
	GEN_FUNC( StageActor )

	//D0:020a11ec
	//D1:020a1238
	GEN_FUNC( virtual ~StageActor )

	//D2:020a11a8

	//020a1154
	GEN_FUNC( virtual bool preUpdate ) // override

	//020a10f0
	GEN_FUNC( virtual void postUpdate, ReturnState state ) // override

	//020a10a0
	//???

	// 020a08a4
	void updateVerticalVelocity();

	//020a08c4
	void updateHorizontalVelocity();

	// 020998e4
	void updateBounce(fx32 min, fx32 amtX, fx32 amtY);

};




class StageEntity : public StageActor
{
public:

	u16 notAVector;
	u16 stompedMaybe;
	u16 spriteSettings;
	u16 argh;
	u8 hitCountdown;
	u8 idk[3];
	u32 dummyZ;
	u32 unk5[6];
	Vec3 unkV1;
	u32 unk11[4];
	Vec3 unkV2;
	Vec3 movementStrength;
	u32 unk12[2];
	u32 eventHi; // 0xFFFFFFFF........
	u32 eventLo; // 0x........FFFFFFFF

	struct StageActorEventIDs {
		u8 targetID;
		u8 triggerID;
	} eventIDs;

	u16 padMaybe;
	u32 vStateId;
	u32 unk15;
	u32 playerNum;
	u32 defeatSFX;
	u32 unk18;
	u32 bitfield;
	u32 used;

	// scale for wiggling effect
	Vec3 wiggleScale;

	// actor range vectors
	Vec2 existDist;
	Vec2 drawDist;
	Vec2 deleteDist;

	// physics collision vectors
	Vec2 collisionSelfPos;
	Vec2 collisionActorPos;

	u32 wiggleOscillator;

	u32 unk21[2];
	u32 defeatedBitfield; // 0x40 is set when a collision occurs

	s32 velX_sum;
	u16 wiggleTimer;
	u16 divVelBy2;
	u16 sizeMod;
	u16 unk25_a;
	u16 unkForPlayer[2];
	u16 unk26;
	u16 unk27;

	u16* ptrToShort;

	u8 defeatRelated;
	u8 unk28;
	u8 decrement;
	u8 unk29;
	u32 unk30;

	u8* ptrToByte;

	u8 playerDirection;
	u8 unk33;

	u8 scoreEnhancement;
	u8 unk34;
	bool spawnedByCreateActorMaybe; // bool
	u8 unk35;

	u8 directionForBlockCallback;

	u8 killedRelated;
	u8 permanentDelete;
	u8 unk36;
	u8 usedInLiquid;
	u8 unk37;

	bool disableDefeatRoll; // bool
	bool invisible; // bool

	u8 notMovableMaybe;
	u8 unk39;
	u8 oneIfOdd;
	u8 unk40;

	u8 defeatedDirection;
	u8 freezeRelated;
	u8 zLayer;
	u8 unk42;
	u8 unk43;
	u8 facing; // 0 = down, 1 = up, 2 = left, 3 = right


	GEN_FUNC( StageEntity )

	virtual s32 onUpdate() override;
	virtual bool preUpdate() override;
	virtual void postUpdate(ReturnState state) override;
	virtual bool preRender() override;

	// D1: 020986e0
	// D0: 02098730
	inline virtual ~StageEntity() {}

	virtual void virt20();
	virtual bool virt21();
	virtual void virt22();
	virtual void virt23();
	virtual void virt24();
	virtual void virt25();
	virtual void virt26();
	virtual void virt27();
	virtual void virt28();
	virtual void virt29();
	virtual void virt30();
	virtual void updateAnimation();
	virtual void virt32();
	virtual void virt33();
	virtual void virt34();
	virtual void virt35();
	virtual void virt36();
	virtual void virt37();
	virtual void virt38();
	virtual void virt39();
	virtual void virt40();
	virtual void virt41();
	virtual void virt42();
	virtual void virt43();
	virtual void virt44();
	virtual void virt45();
	virtual void virt46();
	virtual void virt47();
	virtual void virt48();
	virtual void virt49();
	virtual void virt50();
	virtual void virt51();
	virtual void virt52();
	virtual void virt53();
	virtual void virt54();
	virtual void virt55();
	virtual void virt56();
	virtual void virt57();
	virtual void virt58();
	virtual void virt59();
	virtual void virt60();
	virtual void virt61();
	virtual void virt62();
	virtual void virt63();
	virtual void virt64();
	virtual void virt65();
	virtual void virt66();

	// 020995a4
	GEN_FUNC( void setEvent, u32 id, u32 time, bool enable, bool reverse = false, bool timerSfx = false )

	// 0209C85C
	GEN_FUNC( void applyMovement )

	// 020991f8
	GEN_FUNC( u32 updateTileCollision )

	// 0209c820
	GEN_FUNC( u32 updateLiquids, fx32 defaultAccelY )

	// 0209adb0
	GEN_FUNC( bool deleteIfOutOfRange, u32 flags )

};




class StageEntity3D : public StageEntity
{
public:

	inline StageEntity3D() {}

	// 020ce92c
	virtual s32 onRender() override;

	// D0: 020ce83c
	// D1: 020ce8b8
	inline virtual ~StageEntity3D() override {}

	// 020ceac4
	virtual void preRender3D();

	// 020ceac0
	virtual void postRender3D();

};


class StageEntity3DAnm : public StageEntity
{
public:

	// 020cee34
	StageEntity3DAnm();

	// 020ceae0
	virtual s32 onRender() override;

	// D0: 020ced44
	// D1: 020cedc0
	// D2: 020cecd0
	virtual ~StageEntity3DAnm() override;

	// 020ceac8
	virtual void updateAnimation() override;

	// 020ceccc
	virtual void preRender3D();

	// 020cecc8
	virtual void postRender3D();

};


// totally doesn't belong here, but Function prevents me from putting this in other files
class Fireball {

public:

	typedef bool(Fireball::*StateFunction)();

	StateFunction state;

	Vec3 position;
	Vec3 spawnPosition;
	Vec3 velocity;
	Vec3 scale;
	Vec3s unk4C;

	OAM::Anim anim;
	u32 unk70[4];

	bool active;
	u8 playerNo;
	u8 unk82;
	u8 stateID;
	u8 unk84;
	u8 unk85;
	u8 id;
	u8 unk87;
	u8 viewID;

	// 
	Fireball();

	// D0
	// D1
	virtual ~Fireball();

};

class FireballHandler {

public:

	Fireball fireballs[16];

	// 
	FireballHandler();

	// D0
	// D1
	virtual ~FireballHandler();

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
		//??? = 0,
		Center = 1,
		Invalid,
		//???,
		//???,
		//???
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
	GEN_FUNC(void enableSubScreenFading);

	//02007bd8
	GEN_FUNC(void disableSubScreenFading);

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




class View : public Object
{
public:

	MtxFx44 unk5c;
	MtxFx43 unk9c;

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~View();


};


class OrthoView : public View
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	Vec3s unkfc;

	//D0:020ce734
	//D1:020ce6dc
	virtual ~OrthoView();

};




class StageCamera : public OrthoView
{
public:

	typedef void(StageCamera::*StateFunction)();	

	StateFunction unk108;//State function
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
class FixedOrthoView : public View
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	Vec3s unkfc;

	//D0:0x020D3E4C
	//D1:0x020D3DF4
	virtual ~FixedOrthoView();

};


//ov9
class TitleScreenCamera : public FixedOrthoView
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
class PerspView : public View
{
public:

	Vec3 unkcc;//Target
	Vec3 unkdc;//Position
	Vec3 unkec;//Up
	Vec3s unkfc;

	//D0:0218cd58
	//D1:0218cd00
	virtual ~PerspView();

};



class WorldCamera : public PerspView
{
public:

	typedef void(WorldCamera::*StateFunction)();

	StateFunction unk108;
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




class WorldMapCamera : public PerspView
{
public:

	typedef void(WorldMapCamera::*StateFunction)();

	StateFunction unk108;//State function
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




class EndingCamera : public PerspView
{
public:

	typedef void(EndingCamera::*StateFunction)();

	StateFunction unk108;
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




//Engine related structures
struct LinkedList {

	ProcessNode* first;
	ProcessNode* last;

	//020438e8
	GEN_FUNC(bool append,ProcessNode* node);

	//02043920
	GEN_FUNC(bool remove,ProcessNode* node);

	//020438b0
	GEN_FUNC(bool prepend,ProcessNode* node);

	//02043990
	GEN_FUNC(bool insert,ProcessNode* node, ProcessNode* previous);

	//0204d428
	GEN_FUNC(ProcessNode* getNodeByID,u32 id);


};



struct ProcessList : public LinkedList {

	Base::ProcessFunction executor;

	//0204d46c
	GEN_FUNC(bool execute ); //Traverses the whole list and calls the executor on every node. Always returns true.

};


struct ProcessSet : public ProcessList {

	//0204d4e4
	GEN_FUNC( bool add,PriorityNode* node);

};


struct SceneGraph {

	SceneNode* root;
	Base::ProcessFunction executor;

	//02043acc
	GEN_FUNC(bool addChild,SceneNode* child, SceneNode* parent); //Adds child to the scene graph as a child of parent. Returns true if the node was added successfully, false if node is null or if parent is null (indicating the root node) but root is already set.

	//02043a54
	GEN_FUNC(bool removeChild,SceneNode* child); //Removes the child from the scene graph. Returns true only if child has no children itself, false otherwise.

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
	static void updateProcessLists();

	//0204d630
	static Base* getNextObjectByType(Object::ObjectType type, Base* object);

	//0204d66c
	GEN_FUNC(static Base* getNextObjectByObjectID, u16 objectID, Base* object)

	//0204d6a8
	GEN_FUNC(static Base* getObjectByID, u32 id)

	//0204d6dc
	static u32 getIDIndex(ProcessLink* link);

	//0204d6ec
	static const char* getProcessListName(ProcessListType type);

	//0204d6fc
	static SceneNode* getNextNodeByType(SceneGraph* scene, Object::ObjectType type, SceneNode* node);

	//0204d758
	static SceneNode* getNextNodeByObjectID(SceneGraph* scene, u16 objectID, SceneNode* node);

	//0204d7b4 TODO FIX NAME BRUV
	static bool updateSceneGraph(SceneGraph* scene); //Traverses the graph and calls the executor on every node. Always returns true.

};



namespace Game {

	//02088f48
	extern Fader fader;

	//02085b14
	extern Fader* activeFader;

	//020852a8
	extern u32 currentExecutingProcessList;

	//0208fb08
	extern ProcessNode* currentProcessNode;
	//ALL IN BSS BRUH
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

	//02085224
	extern u32 nextFreeID;

	//0202614c
	void initProcessLists(); //STATIC CTOR

	//0208027c
	extern const char* processListNames[6];

	//020852b4
	extern const char processListNameNull[5];

	//020852ec
	extern const char processListNameConnect[8];

	//020852c4
	extern const char processListNameCreate[7];

	//020852f4
	extern const char processListNameExecute[8];

	//020852bc
	extern const char processListNameDelete[7];

	//020852ac
	extern const char processListNameDraw[5];

	//020852cc
	extern Base::ProcessFunction renderProcessFunction;//TO

	//020852d4
	extern Base::ProcessFunction sceneProcessFunction; //NAME???TO

	//020852dc
	extern Base::ProcessFunction createProcessFunction;//TO

	//020852e4
	extern Base::ProcessFunction deleteProcessFunction;//TO

	//020852fc
	extern Base::ProcessFunction updateProcessFunction;

	//02085238
	extern Base::PreFunction preCreateFunction;

	//02085240
	extern Base::OnFunction onCreateFunction;

	//02085228
	extern Base::PostFunction postCreateFunction;

	//01ffd1b8
	extern Base::PreFunction preUpdateFunction;

	//01ffd1b0
	extern Base::OnFunction onUpdateFunction;

	//01ffd198
	extern Base::PostFunction postUpdateFunction;

	//01ffd1a8
	extern Base::PreFunction preRenderFunction;

	//01ffd1a0
	extern Base::OnFunction onRenderFunction;

	//01ffd1c0
	extern Base::PostFunction postRenderFunction;

	//02085248
	extern Base::PreFunction preDestroyFunction;

	//02085230
	extern Base::OnFunction onDestroyFunction;

	//02085250
	extern Base::PostFunction postDestroyFunction;

}




#endif // !NSMB_ACTOR_H_
