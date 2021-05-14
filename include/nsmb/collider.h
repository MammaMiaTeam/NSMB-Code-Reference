#ifndef NSMB_COLLIDER_H_
#define NSMB_COLLIDER_H_

#include "nitro_if.h"
#include "nsmb/vector.h"


/*
	Function type for the Collider's collisions callbacks.
*/
typedef void (*ColliderCallback) (StageActor* self, Actor* collision);

/*
	Settings structure used to initialize a Collider.
	The left and top boundaries should be less than the right and bottom boundaries, respectively.
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

	u16 unk1, unk2, unk3;
};

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

	enum UpdateFlag {
		COLLECTED = (1 << 2),	// Used internally to signal that the object has been collected (used only for the coin type)
		DIR_LEFT = (1 << 3),	// Used internally to specify if the side collision has occurred from the left
		SKIP_UPDATE = (1 << 7),	// Used internally to skip the collision's calculation
	};

	enum OptionFlag {
		NOT_SOLID = (1 << 0),
		CALC_DELTA = (1 << 1),
		DISABLE_BLOCK_PARTICLES = (1 << 4),
		SLOW_PASS_THROUGH_RIGHT = (1 << 5),
		SLOW_PASS_THROUGH_LEFT = (1 << 6),
	};

	// Collider owner
	StageActor* owner;						// Reference to the owner of this Collider.

	// Linked list
	struct {
		Collider* prev;					// Pointer to the previous registered Collider.
		Collider* first;				// Pointer to the first registered Collider.
	} list;

	// Pointer to some mysterious structure	(CollisionMgr maybe?)
	u32* unk3;
	u32 unk4;
	u32 unk5;

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
	u32 behavior;						// Represents the general behavior of the Collider.	(TODO: enum?)
	u32 collisionFlag;					// Stores the collision result after each update.	(TODO: enum? bitfield?)

	bool registered;					// Represents the Collider execution list registered state.		(Set to true when the Collider gets registered for execution)

	u8 colliderRelated;
	u8 updateFlag;						// Specifies the settings that are used internally by the collision functions.
	u8 optionFlag;						// Specifies the settings that should be used when checking for collision and when updating.


	static Collider* first;				// First registered Collider in the execution list.
	static Collider* last;				// Last registered Collider in the execution list.


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
	void initEx(StageActor* owner, fx32 left, fx32 top, fx32 right, fx32 bottom, ColliderCallback topCallback, ColliderCallback bottomCallback, ColliderCallback sideCallback, u32 behavior, u8 colliderRelated, Vec3* scale);

	/*
		Initializes the Collider through a settings structure.
		A scale vector may also be specified.
	*/
	void init(StageActor* owner, ColliderInfo* info, u32 behavior, u8 colliderRelated, Vec3* scale);

	/*
		Initializes the collision rectangle with parameters.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRectEx(fx32 left, fx32 top, fx32 right, fx32 bottom, Vec3* scale);

	/*
		Initializes the collision rectangle using origin and end points vectors.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRect(Vec2* originPoint, Vec2* endPoint, Vec3* scale);

	/*
		Initializes the collision rectangle through a settings structure.
		A scale vector may also be specified.
		optionFlag can be used to calculate the origin point's delta from the old origin point.
	*/
	void initRect(ColliderInfo* info, Vec3* scale);

	/*
		Links the Collider to the execution list.
	*/
	void link();

	/*
		Unlinks the Collider from the execution list.
	*/
	void unlink();

	/*
		Updates the collision rectangle based on the position of the owner.
	*/
	void updatePosition();

	/*
		I honestly don't know (it uses unk3, which I've never seen being set).
	*/
	void doSomething();

};

#endif // !NSMB_COLLIDER_H_
