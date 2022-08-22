#pragma once
#include "common.h"
#include "object.h"
#include "nsmb/math/vector.h"


enum class ActorType : u8 {
	None,
	Player,
	Entity,
	Overlay,
};


enum class ActorCategory : u8 {
	None				= (1 << 0),
	Player				= (1 << 1),
	Actor				= (1 << 2),
	Overlay				= (1 << 3),
	StageForeground		= (1 << 5),
	StageOverlay		= (1 << 6),
	StageEntity			= (1 << 7)
};
IMPL_ENUMCLASS_OPERATORS(ActorCategory);


struct ActorProfile : public ObjectProfile {

	bool (*loadResources)();

	NTR_INLINE bool tryLoad() {
		return loadResources ? loadResources() : true;
	}

};


class Actor : public Object
{
public:

	// 020ca85c
	static Vec3* spawnPosition;
	// 020ca860
	static Vec3s* spawnRotation;
	// 020ca864
	static s8* spawnPlayerID;
	// 020ca868
	static fx32* spawnScale;

	Vec3 position;
	Vec3 lastPosition;
	Vec3 lastStep;
	Vec3 centerOffset;
	Vec3s rotation;
	Vec3s lastRotation;
	fx32 velH;
	fx32 targetVelH;
	fx32 accelV;
	fx32 targetVelV;
	fx32 accelH;
	u32 unkC4;
	Vec3 velocity;
	Vec3 targetVelocity;
	Vec3 scale;
	Vec3 accel;
	Vec3 velocityLimit;
	ActorType actorType;
	bool visible;
	s8 linkedPlayerID;
	ActorCategory actorCategory;

	//020a0edc
	sym Actor() __body

	//D0:020a0e04
	//D1:020a0e74
	sym virtual ~Actor() __body

	//D2:020a0d9c

	//020a0d7c
	sym virtual bool preCreate() override __rbody

	//020a0d70
	sym virtual void postCreate(BaseReturnState state) override __body

	//020a0d50
	sym virtual bool preDestroy() override __rbody

	//020a0d44
	sym virtual void postDestroy(BaseReturnState state) override __body

	//020a0cac
	sym virtual bool preUpdate() override __rbody

	//020a0ca0
	sym virtual void postUpdate(BaseReturnState state) override __body

	//020a0c48
	sym virtual bool preRender() override __rbody

	//020a0c3c
	sym virtual void postRender(BaseReturnState state ) override __body

	//0201ff68
	sym virtual void setX(fx32 x) __body //U SURE???

	//0201ff70
	sym virtual void moveX(fx32 offset) __body //U SURE???

	//020a0bf8
	sym u32 getActorCount(u16 objectID) __rbody

	//020a0bb8
	sym static void setSpawnParams(const Vec3* position, const Vec3s* rotation, const fx32* scale, const s8* linkPlayerID) __body

	//020a0b64
	sym static Actor* spawnActor(u16 objectID, u32 settings, const Vec3* position, const Vec3s* rotation = nullptr, const fx32* scale = nullptr, const s8* linkPlayerID = nullptr) __rbody

	//020a0b5c
	sym void linkPlayer(s8 playerID) __body



	// Applies the current acceleration to a velocity vector
	sym Vec3 applyAcceleration(const Vec3& velocity) const __rbody

	// Applies the input velocity to the position
	sym void applyVelocityToPosition(const Vec3& velocity) __body

	// Applies the current acceleration to the velocity, then adds the new velocity to the position
	sym void applyVelocity() __body

	// Calculates and applies the velocity, using the input Z rotation, to the position (2D, distributed over the X and Y axes)
	sym void applyDirectionalVelocity(u16 rotation) __body

	// Calculates the velocity using the actor's Y rotation (3D, distributed over the X and Z axes)
	sym void setDirectionalVelocity3D() __body

	// Calculates the horizontal velocity (2D, X axis)
	sym void updateHorizontalVelocity() __body
	
	// Calculates the vertical velocity (2D, Y axis)
	sym void updateVerticalVelocity() __body

	// Calculates the verical velocity, then clamps it to velVMin (2D, Y axis)
	sym void updateVerticalVelocityClamped() __body

	// Calculates the horizontal velocity, then clamps it to velHMin (2D/3D, velH)
	sym void updateHorizontalVelocityClamped() __body

	// Calculates the horizontal and vertical velocities, clamping them to velHMin and velVMin (2D, X and Y axes)
	sym void updateVelocityClamped() __body

	// Calculates and applies the velocity, using the actor's Y rotation, to the position (3D, distributed over the X and Z axes)
	sym void applyDirectionalVelocity3D() __body

	// Performs an exponential smoothing on the acceleration vector in order to attenuate it
	sym void attenuateAcceleration() __body



	// Applies the center offset to the current position
	sym Vec3 getCenteredPosition() const __rbody

};
NTR_SIZE_GUARD(Actor, 0x120);

namespace ProcessManager {

	NTR_INLINE Actor* getNextActor(const Actor* actor = nullptr) {
		return static_cast<Actor*>(getNextObjectByType(ObjectType::Actor, actor));
	}

}
