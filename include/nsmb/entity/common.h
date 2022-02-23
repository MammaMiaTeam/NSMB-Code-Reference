#pragma once
#include "nitro_if.h"
#include "nsmb/util.h"


class Base;
class Object;
class Scene;
class Actor;


enum class BaseReturnState : u32 {
	PreFailed = 0,
	Failed,
	Success,
	Minus1	//WHEN??? -> StageScene::onCreate
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


typedef s32(Base::* BaseProcessFunction)();
typedef bool(Base::* BasePreFunction)();
typedef s32(Base::* BaseOnFunction)();
typedef void(Base::* BasePostFunction)(BaseReturnState);

typedef u32(*OverlayLoadFunction)(u16);
typedef void (*OverlayUnloadFunction)(u16);
