#pragma once
#include "nitro_if.h"
#include "nsmb/math/vector.h"


class LineController
{
public:

	using StateFunction = void(LineController::*)();

	enum class State : u8 {

		Idle,
		Fall,
		AscSlope,
		DescSlope,
		VerticalCorner,
		HorizontalCorner,
		Horizontal,
		Vertical,
		AscFlatSlopeLeft,
		AscFlatSlopeRight,
		DescFlatSlopeLeft,
		DescFlatSlopeRight,
		AscSteepSlopeTop,
		AscSteepSlopeBottom,
		DescSteepSlopeBottom,
		DescSteepSlopeTop,
		SmallCircle,
		Medium2ndArc,
		Medium1stArc,
		Medium3rdArc,
		Medium4thArc,
		Big1stArc,
		Big2ndArc,
		Big3rdArc,
		Big4thArc,

	};

	void create(const Vec2& position, fx32 speed, bool stopOnEnd = false);
	void update();
	Vec2 getPosition() const;
	void setPosition(const Vec2& position);
	void setSpeed(fx32 speed);
	void setOffset(const Vec2& offset, u32 index);
	void start();

	void switchDirection();
	void clearOffsets();
	bool checkEndTile();

	bool calculateHorizontalStep(fx32 slope, fx32 length, Vec2 source, Vec2 target, Vec2& out) const;
	bool calculateVerticalStep(fx32 length, Vec2 source, Vec2 target, fx32& out) const;
	u16 calculateCurveStep(fx32 radiusSquared, Vec2 source, Vec2 target) const;

	bool attachToAscSlope(Vec2 target, Vec2 source, Vec2 current);
	bool attachToDescSlope(Vec2 target, Vec2 source, Vec2 current);
	bool attachToHorizontalCorner(Vec2 target, Vec2 source, Vec2 current);
	bool attachToVerticalCorner(Vec2 target, Vec2 source, Vec2 current);
	bool attachToHorizontal(Vec2 target, Vec2 source, Vec2 current);
	bool attachToVertical(Vec2 target, Vec2 source, Vec2 current);
	bool attachToAscFlatSlopeLeft(Vec2 target, Vec2 source, Vec2 current);
	bool attachToAscFlatSlopeRight(Vec2 target, Vec2 source, Vec2 current);
	bool attachToDescFlatSlopeLeft(Vec2 target, Vec2 source, Vec2 current);
	bool attachToDescFlatSlopeRight(Vec2 target, Vec2 source, Vec2 current);
	bool attachToAscSteepSlopeTop(Vec2 target, Vec2 source, Vec2 current);
	bool attachToAscSteepSlopeBottom(Vec2 target, Vec2 source, Vec2 current);
	bool attachToDescSteepSlopeBottom(Vec2 target, Vec2 source, Vec2 current);
	bool attachToDescSteepSlopeTop(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToSmallCircle(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToMedium2ndArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToMedium1stArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToMedium3rdArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToMedium4thArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToBig1stArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToBig2ndArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToBig3rdArc(Vec2 target, Vec2 source, Vec2 current);
	u16 attachToBig4thArc(Vec2 target, Vec2 source, Vec2 current);
	void attachToLine();

	void beginIdle();
	void beginFall();
	void beginAscSlope();
	void beginDescSlope();
	void beginVerticalCorner();
	void beginHorizontalCorner();
	void beginHorizontal();
	void beginVertical();
	void beginAscFlatSlopeLeft();
	void beginAscFlatSlopeRight();
	void beginDescFlatSlopeLeft();
	void beginDescFlatSlopeRight();
	void beginAscSteepSlopeTop();
	void beginAscSteepSlopeBottom();
	void beginDescSteepSlopeBottom();
	void beginDescSteepSlopeTop();
	void beginSmallCircle();
	void beginMedium2ndArc();
	void beginMedium1stArc();
	void beginMedium3rdArc();
	void beginMedium4thArc();
	void beginBig1stArc();
	void beginBig2ndArc();
	void beginBig3rdArc();
	void beginBig4thArc();

	void idleState();
	void fallState();
	bool checkAscendingLine();
	bool checkDescendingLine();
	void crossVerticalBottom();
	void crossAscendingSlope();
	void crossHorizontalRight();
	void crossDescendingSlope();
	void update1stArc(fx32 radius, fx32 step);
	void update2ndArc(fx32 radius, fx32 step);
	void update3rdArc(fx32 radius, fx32 step);
	void update4thArc(fx32 radius, fx32 step);
	void ascSlopeState();
	void descSlopeState();
	void verticalCornerState();
	void crossHorizontalLeft();
	void horizontalCornerState();
	void horizontalState();
	void verticalState();
	void ascFlatSlopeLeftState();
	void ascFlatSlopeRightState();
	void descFlatSlopeLeftState();
	void descFlatSlopeRightState();
	void ascSteepSlopeTopState();
	void ascSteepSlopeBottomState();
	void descSteepSlopeBottomState();
	void descSteepSlopeTopState();
	void smallCircleState();
	void medium2ndArcState();
	void medium1stArcState();
	void medium3rdArcState();
	void medium4thArcState();
	void big1stArcState();
	void big2ndArcState();
	void big3rdArcState();
	void big4thArcState();

	Vec2 offsets[3];

	StateFunction updateFunction;

	Vec2 velocity;
	Vec2 position;
	Vec2 lastPosition;
	Vec2 curveSource;
	Vec2 curveOrigin;

	fx32 speed;
	u16 curveAngle;
	State stateID;

	bool reachedEnd;
	bool stopped;
	bool direction;
	bool stopOnEnd;

};
NTR_SIZE_GUARD(LineController, 0x74);
