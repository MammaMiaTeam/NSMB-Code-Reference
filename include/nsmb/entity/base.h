#pragma once
#include "common.h"
#include "process.h"


class Heap;
class FrameHeap;


class Base
{
public:

	//0204d2ac (C2, most likely protected)
	sym Base() __body

	//0204d23c (D2, D1 is pure??)
	//~Base()

	//0204cba0
	sym BaseReturnState processCreate() __rbody

	//01ffd22c
	sym BaseReturnState processUpdate() __rbody

	//01ffd1c8
	sym BaseReturnState processRender() __rbody

	//0204cb20
	sym BaseReturnState processDestroy() __rbody

	//01ffd524
	sym BaseReturnState process(BaseOnFunction callback, BasePreFunction preCallback, BasePostFunction postCallback) __rbody

	sym virtual s32 onCreate() __rbody
	sym virtual bool preCreate() __rbody
	sym virtual void postCreate(BaseReturnState state) __body
	sym virtual s32 onDestroy() __rbody
	sym virtual bool preDestroy() __rbody
	sym virtual void postDestroy(BaseReturnState state) __body
	sym virtual s32 onUpdate() __rbody
	sym virtual bool preUpdate() __rbody
	sym virtual void postUpdate(BaseReturnState state) __body
	sym virtual s32 onRender() __rbody
	sym virtual bool preRender() __rbody
	sym virtual void postRender(BaseReturnState state) __body

	sym virtual void onCleanupResources() __body
	sym virtual bool prepareResourcesSafe(u32 size, Heap* parent) __rbody
	sym virtual bool prepareResourcesFast(u32 size, Heap* parent) __rbody
	sym virtual bool onPrepareResources() __rbody

	//0204cc04
	sym void create() __body

	//0204d08c
	sym void destroy() __body

	//0204cac0
	sym bool hasChildNotCreated() __rbody

	//D1 is null
	sym virtual ~Base() __body

	//0204d078
	//Null if root
	sym Base* getParent() __rbody 
	//0204cc98
	sym void* operator new(size_t size) __rbody

	//0204cc7c
	sym void operator delete(void* ptr) __body

	//0204ca80
	sym static void setSpawnParams(u16 objectID, SceneNode* parent, u32 settings, ObjectType type) __body

	//0204c974
	sym static u32 loadSceneOverlay(u16 objectID) __rbody

	//0204c948
	sym static void unloadSceneOverlay(u16 objectID) __body

	//0204c9a4
	sym static Base* spawn(u16 objectID, SceneNode* parent, u32 settings, ObjectType type) __rbody

	//0204c920
	sym static Base* spawnChild(u16 objectID, Base* parent, u32 settings, ObjectType type) __rbody

	//0204c908
	sym static Base* spawnParent(u16 objectID, u32 settings, ObjectType type) __rbody

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
