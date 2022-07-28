#pragma once
#include "nitro_if.h"
#include "nsmb/util.h"
#include "collisionmgr.h"



/*
	Function type for the Collider's collisions callbacks.
*/
using ColliderCallback = void(*)(StageActor& self, StageActor& other);

/*
	Settings structure used to initialize a Collider.
	The left and bottom boundaries should be less than the right and top boundaries, respectively.
*/
struct ColliderInfo {

	// Collision rectangle boundaries
	fx32 left, top, right, bottom;

	// Collision callbacks
	struct {
		ColliderCallback top;
		ColliderCallback bottom;
		ColliderCallback side;
	} callbacks;

};
NTR_SIZE_GUARD(ColliderInfo, 0x1C);

/*
	Physics class responsible for handling a collision rectangle that acts like a solid object on all sides.
	The Collider can be initialized through a settings structure or manually through public methods.
	Like many other physics classes, it needs to be registered for execution, otherwise any interactions will have no effect.
	Interactions between the collision rectangle and other entities (CollisionMgr' sensors) are defined by the behavior and flags fields.
	Additionally, upon initialization, a scale vector may be used to scale the collision rectangle accordingly.
	Rotation is not supported.
*/
class Collider {
public:

	enum class UpdateFlag : u8
	{
		Collected				= (1 << 2),	// Used internally to signal that the object has been collected (used only for the coin type)
		DirectionLeft			= (1 << 3),	// Used internally to specify if the side collision has occurred from the left
		SkipTop					= (1 << 5),	// Used internally to skip the collision's calculation on the top side
		SkipBottom				= (1 << 6),	// Used internally to skip the collision's calculation on the bottom side
		SkipSides				= (1 << 7),	// Used internally to skip the collision's calculation on the left/right sides
	};

	enum class OptionFlag : u8
	{
		NoDestruction			= (1 << 0),
		CalculateDelta			= (1 << 1),
		IgnoreGround			= (1 << 3),
		DisableBlockParticles	= (1 << 4),
		PushableLeft			= (1 << 5),
		PushableRight			= (1 << 6),
	};

	// Collider owner
	StageActor* owner;					// Reference to the owner of this Collider.

	// Linked list
	Collider* prev;						// Pointer to the previous registered Collider.
	Collider* next;						// Pointer to the next registered Collider.

	CollisionMgr* managers[3];			// Pointers to linked CollisionMgrs

	// Collision callbacks
	struct {
		ColliderCallback top;			// Called when a collision occurs above the collision rectangle.
		ColliderCallback bottom;		// Called when a collision occurs below the collision rectangle.
		ColliderCallback side;			// Called when a collision occurs at the sides of the collision rectangle.
	} callbacks;

	// Collision rectangle
	Vec2 originPointAbs, endPointAbs;	// Represents the rectangle relative to the level.
	Vec2 originPoint, endPoint;			// Represents the rectangle relative to point (0;0).
	Vec2 originPointDelta;

	// Miscellaneous
	TileType tileType;					// Represents the emulated tile type.
	CollisionMgrResult collisionResult;	// Stores the collision result after each update.

	bool registered;					// Represents the Collider execution list registered state.		(Set to true when the Collider gets registered for execution)

	u8 layerID;							// Must match the CollisionMgr's layerID during processing.
	UpdateFlag updateFlag;				// Specifies the settings that are used internally by the collision functions.
	OptionFlag optionFlag;				// Specifies the settings that should be used when checking for collision and when updating.


	static Collider* listHead;			// First registered Collider in the execution list.
	static Collider* listTail;			// Last registered Collider in the execution list.


	Collider();

	~Collider();

	/*
		Resets the Collider's execution parameters.
		Doesn't unregister the Collider from the execution list nor does it
		reset the collision rectangle points, callbacks, behavior and flags.
	*/
	void reset();

	/*
		Initializes the Collider with collision rectangle parameters and collision callbacks.
		A scale vector may also be specified.
	*/
	void initEx(StageActor* owner, fx32 left, fx32 top, fx32 right, fx32 bottom, ColliderCallback topCallback, ColliderCallback bottomCallback, ColliderCallback sideCallback, u32 behavior, u8 colliderRelated, const Vec3* scale = nullptr);

	/*
		Initializes the Collider through a settings structure.
		A scale vector may also be specified.
	*/
	void init(StageActor* owner, const ColliderInfo& info, u32 behavior, u8 colliderRelated, const Vec3* scale = nullptr);

	/*
		Initializes the collision rectangle with parameters.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRectEx(fx32 left, fx32 top, fx32 right, fx32 bottom, const Vec3* scale = nullptr);

	/*
		Initializes the collision rectangle using origin and end points vectors.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRect(const Vec2& originPoint, const Vec2& endPoint, const Vec3* scale = nullptr);

	/*
		Initializes the collision rectangle through a settings structure.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRect(const ColliderInfo& info, const Vec3* scale = nullptr);

	// Links the Collider to the execution list.
	void link();

	// Unlinks the Collider from the execution list.
	void unlink();

	// Updates the collision rectangle based on the position of the owner.
	void updatePosition();

	void updatePlayerInteraction();

};
NTR_SIZE_GUARD(Collider, 0x6C);

IMPL_ENUMCLASS_OPERATORS(Collider::UpdateFlag);
IMPL_ENUMCLASS_OPERATORS(Collider::OptionFlag);
