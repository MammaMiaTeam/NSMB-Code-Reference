#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/game/physics/segmentplatform.hpp>
#include <nsmb/core/math/springfunction.hpp>
#include <nsmb/core/graphics/3d/texture.hpp>

// vtable at 0218883c (ov97)
class SwellingGround : public StageEntity {
public:

	enum class State : u32 {
		Idle,
		Swell,
		SwollenIdle,
		Unswell,

		Count
	};

	enum Direction : u8 {
		Up,
		Down
	};

	struct Point {
		fx32 offsetX;
		fx32 offsetY;
		fx32 swollenOffsetY;
	};


	using StateFunction = void(SwellingGround::*)();

	// D1: 02185600
	// D0: 021856c4
	virtual ~SwellingGround();

	// 02185fc8
	s32 onCreate() override;
	// 02185f88
	s32 onDestroy() override;
	// 02185bc0
	s32 onRender() override;
	// 02185f84
	void onCleanupResources() override;
	// 02185f90
	bool onPrepareResources() override;

	// 02185b78
	bool updateMain() override;

	// 02185830
	void setState(State stateID);
	// 021857b4
	void updateState();

	// 02185b74
	void initIdleState();
	// 02185b28
	void idleState();
	// 02185b24
	void initSwellState();
	// 02185a0c
	void swellState();
	// 02185a08
	void initSwollenIdleState();
	// 021859bc
	void swollenIdleState();
	// 021859b8
	void initUnswellState();
	// 0218585c
	void unswellState();


	// 02185790
	static bool loadResources();

	static constexpr u16 ObjectID = 231;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 194;

	// 02188830
	static const ActorProfile profile;

	// 02188808
	static const Point* targetPoints[2]; // [direction] | pointers to the following two arrays
	// 021885b0
	static const Point targetPointsUp[12];
	// 02188640
	static const Point targetPointsDown[12];

	// 02188bc0
	static const StateFunction initStates[4];
	// 02188be0
	static const StateFunction states[4];

	// 021887f0
	// static const u32 texParams[2]; // ??


	SegmentPlatform segments[11];
	Vec2 pointPositions[12];
	Vec2 swollenPointOffsets[12]; // NOTE: the x component here is actually the point's base y offset! it does NOT represent an offset on the x-axis!!
	SpringFunction swellFunction;

	Texture texture;
	u32 textureInfo[3]; 			// tex1, tex2, palette (?)

	StateFunction updateFunction;
	State currentState;
	BOOL enteringState;

	u32 texParams; 					// ?

	bool enableTriggerID;			// true if swell can be triggered by events

#if NTR_EXT_EXISTS(SwellingGround)
	#include NTR_EXT_INCLUDE(SwellingGround)
#endif

};
#if !NTR_EXT_EXISTS(SwellingGround)
NTR_SIZE_GUARD(SwellingGround, 0xA30);
#endif

using SwellingGroundState = SwellingGround::State;
using SwellingGroundPoint = SwellingGround::Point;
