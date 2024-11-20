#pragma once

#include "common.hpp"
#include "process.hpp"


class Heap;
class FrameHeap;


class Base
{
public:

	//0204d2ac (C2, most likely protected)
	Base();

	//0204d23c (D2, D1 is pure??)
	//~Base()

	//0204cba0
	BaseReturnState processCreate();

	//01ffd22c
	BaseReturnState processUpdate();

	//01ffd1c8
	BaseReturnState processRender();

	//0204cb20
	BaseReturnState processDestroy();

	//01ffd524
	BaseReturnState process(BaseOnFunction callback, BasePreFunction preCallback, BasePostFunction postCallback);

	virtual s32 onCreate();
	virtual bool preCreate();
	virtual void postCreate(BaseReturnState state);
	virtual s32 onDestroy();
	virtual bool preDestroy();
	virtual void postDestroy(BaseReturnState state);
	virtual s32 onUpdate();
	virtual bool preUpdate();
	virtual void postUpdate(BaseReturnState state);
	virtual s32 onRender();
	virtual bool preRender();
	virtual void postRender(BaseReturnState state);

	virtual void onCleanupResources();
	virtual bool prepareResourcesSafe(u32 size, Heap* parent);
	virtual bool prepareResourcesFast(u32 size, Heap* parent);
	virtual bool onPrepareResources();

	//0204cc04
	void create();

	//0204d08c
	void destroy();

	//0204cac0
	bool hasChildNotCreated();

	//D1 is null
	virtual ~Base();

	//0204d078
	//Null if root
	Base* getParent();
	//0204cc98
	void* operator new(size_t size);

	//0204cc7c
	void operator delete(void* ptr);

	//0204ca80
	static void setSpawnParams(u16 objectID, SceneNode* parent, u32 settings, ObjectType type);

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
	u32 settings;
	u16 id;//Class ID
	ObjectState state;//Object state
	bool destroyFlag;//Destroy flag

	bool pendingUpdateFlag;//Pending update registry
	bool pendingCreateFlag;//Pending create registry
	ObjectType type;//Object type
	u8 skipFlags;//Flags
	//0x01: Skip update children
	//0x02: Skip update
	//0x04: Skip render children
	//0x08: Skip render

	ProcessLink link;//Link

	u32 unk54; // unused (debug leftover?)
	FrameHeap* resourcesHeap;

};
NTR_SIZE_GUARD(Base, 0x5C);


namespace Game
{
	//02085224
	extern u32 nextFreeID;

	//02085238
	extern BasePreFunction preCreateFunction;

	//02085240
	extern BaseOnFunction onCreateFunction;

	//02085228
	extern BasePostFunction postCreateFunction;

	//01ffd1b8
	extern BasePreFunction preUpdateFunction;

	//01ffd1b0
	extern BaseOnFunction onUpdateFunction;

	//01ffd198
	extern BasePostFunction postUpdateFunction;

	//01ffd1a8
	extern BasePreFunction preRenderFunction;

	//01ffd1a0
	extern BaseOnFunction onRenderFunction;

	//01ffd1c0
	extern BasePostFunction postRenderFunction;

	//02085248
	extern BasePreFunction preDestroyFunction;

	//02085230
	extern BaseOnFunction onDestroyFunction;

	//02085250
	extern BasePostFunction postDestroyFunction;

}
