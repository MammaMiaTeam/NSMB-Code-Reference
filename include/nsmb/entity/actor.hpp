#pragma once
#include "common.hpp"
#include "object.hpp"
#include "nsmb/math/vector.hpp"
#include "nsmb/extra/bitmaskenum.hpp"


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
NTR_CREATE_BITMASK_ENUM(ActorCategory);


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
	Actor();

	//D0:020a0e04
	//D1:020a0e74
	virtual ~Actor();

	//D2:020a0d9c

	//020a0d7c
	virtual bool preCreate() override;

	//020a0d70
	virtual void postCreate(BaseReturnState state) override;

	//020a0d50
	virtual bool preDestroy() override;

	//020a0d44
	virtual void postDestroy(BaseReturnState state) override;

	//020a0cac
	virtual bool preUpdate() override;

	//020a0ca0
	virtual void postUpdate(BaseReturnState state) override;

	//020a0c48
	virtual bool preRender() override;

	//020a0c3c
	virtual void postRender(BaseReturnState state ) override;

	//0201ff68
	virtual void setX(fx32 x); //U SURE???

	//0201ff70
	virtual void moveX(fx32 offset); //U SURE???

	//020a0bf8
	u32 getActorCount(u16 objectID);

	//020a0bb8
	static void setSpawnParams(const Vec3* position, const Vec3s* rotation, const fx32* scale, const s8* linkPlayerID);

	//020a0b64
	static Actor* spawnActor(u16 objectID, u32 settings, const Vec3* position, const Vec3s* rotation = nullptr, const fx32* scale = nullptr, const s8* linkPlayerID = nullptr);

	//020a0b5c
	void linkPlayer(s8 playerID);



	// Applies the current acceleration to a velocity vector
	Vec3 applyAcceleration(const Vec3& velocity) const;

	// Applies the input velocity to the position
	void applyVelocityToPosition(const Vec3& velocity);

	// Applies the current acceleration to the velocity, then adds the new velocity to the position
	void applyVelocity();

	// Calculates and applies the velocity, using the input Z rotation, to the position (2D, distributed over the X and Y axes)
	void applyDirectionalVelocity(u16 rotation);

	// Calculates the velocity using the actor's Y rotation (3D, distributed over the X and Z axes)
	void setDirectionalVelocity3D();

	// Calculates the horizontal velocity (2D, X axis)
	void updateHorizontalVelocity();
	
	// Calculates the vertical velocity (2D, Y axis)
	void updateVerticalVelocity();

	// Calculates the verical velocity, then clamps it to velVMin (2D, Y axis)
	void updateVerticalVelocityClamped();

	// Calculates the horizontal velocity, then clamps it to velHMin (2D/3D, velH)
	void updateHorizontalVelocityClamped();

	// Calculates the horizontal and vertical velocities, clamping them to velHMin and velVMin (2D, X and Y axes)
	void updateVelocityClamped();

	// Calculates and applies the velocity, using the actor's Y rotation, to the position (3D, distributed over the X and Z axes)
	void applyDirectionalVelocity3D();

	// Performs an exponential smoothing on the acceleration vector in order to attenuate it
	void attenuateAcceleration();



	// Applies the center offset to the current position
	Vec3 getCenteredPosition() const;

};
NTR_SIZE_GUARD(Actor, 0x120);

namespace ProcessManager {

	NTR_INLINE Actor* getNextActor(const Actor* actor = nullptr) {
		return static_cast<Actor*>(getNextObjectByType(ObjectType::Actor, actor));
	}

}
