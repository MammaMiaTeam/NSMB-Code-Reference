#pragma once
#include "common.hpp"
#include "base.hpp"


struct ObjectProfile {

	Object* (*constructor)();

	u16 updatePriority;
	u16 renderPriority;

	NTR_INLINE Object* tryConstruct() {
		return constructor ? constructor() : nullptr;
	}

};
NTR_SIZE_GUARD(ObjectProfile, 0x8);


class Object : public Base
{
public:

	NTR_INLINE Object() {}

	//020131a8
	virtual void postCreate(BaseReturnState state);

	//D0:0201313c
	//D1:0201311c
	virtual ~Object();

	//02013168
	static Object* spawnScene(u16 objectID, u32 settings, ObjectType type);

	//02013188
	static Object* spawnObject(u16 objectID, Base* scene, u32 settings, ObjectType type);


	template<class T>
	static Object* constructObject() {
		return new T;
	}

};
NTR_SIZE_GUARD(Object, sizeof(Base));
