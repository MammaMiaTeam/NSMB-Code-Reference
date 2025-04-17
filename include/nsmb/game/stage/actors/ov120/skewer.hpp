#pragma once

#include <nsmb/game/stage/entity.hpp>
#include <nsmb/core/graphics/3d/model.hpp>

// ov120
class Skewer : public StageEntity {
public:

	using FormulaFunction = fx32(Skewer::*)(u32 time);

	struct MovementProgram {

		u32 duration; // Duration of this movement program.
		FormulaFunction formula; // Formula used to calculate the distance based on the current time.

	};
	NTR_SIZE_GUARD(MovementProgram, 0xC);

	enum Step {
		Step_Idle,
		Step_Expanding,
		Step_Expanded,
		Step_Retracting,
		Step_Retracted,
		Step_Invalid = -1
	};

	enum Direction : u8 {
		Down,
		Up,
		Left,
		Right
	};

	enum Speed : u8 {
		Regular,
		Fast,
		Slow,
		SpeedMax
	};


	virtual ~Skewer();

	s32 onCreate() override;
	s32 onDestroy() override;
	s32 onRender() override;
	void onCleanupResources() override;
	bool onPrepareResources() override;

	bool updateMain() override;

	bool playerCollision(ActiveCollider& self, ActiveCollider& other) override;

	bool isInCamera() const;
	void update();
	void onReachedPeak();
	Step getStepInfo(u32& stepTime, bool& reachedPeak, u32 timer) const;
	void installStates();
	void prepareCollision();
	void programStart();

	fx32 expandingRegular(u32 time);
	fx32 expandingFast(u32 time);
	fx32 expandingSlow(u32 time);
	fx32 retractingRegular(u32 time);
	fx32 retractingFast(u32 time);
	fx32 retractingSlow(u32 time);


	static u32 getSkewerCount();

	static bool loadResources();


	static const AcConfig downTipAcConfig;
	static const AcConfig upPillarAcConfig;
	static const AcConfig upTipAcConfig;
	static const AcConfig leftPillarAcConfig;
	static const AcConfig leftTipAcConfig;
	static const AcConfig downPillarAcConfig;
	static const AcConfig rightPillarAcConfig;
	static const AcConfig rightTipAcConfig;
	static const s16 distanceTableFast[27];
	static const FxRect boundingRectangles[4]; // [0-3=Direction, see enum above]
	static const s16 distanceTableRegular[48];
	static const s16 distanceTableSlow[112];
	static const MovementProgram retractPrograms[SpeedMax];
	static const MovementProgram expandPrograms[SpeedMax];

	static u32 syncTimer;


	Direction direction; // Based on actor ID, see enum above.
	u8 distanced; // 0 if actors 216-219, 1 if actors 220-223.
	Model model;
	ActiveCollider pillarCollider; // Rectangle ActiveCollider for the Skewer pillar.
	ActiveCollider tipCollider; // Trapezoid (triangle) ActiveCollider for the Skewer tip.
	u8 unused5E8[10]; // Unused.
	bool submerged; // True if the Skewer is currently submerged: used to trigger a splash upon entering/exit a liquid.
	Speed speed; // Speed determines which SkewerMgr a Skewer is assigned to, see enum above.
	fx32 originPos; // Depending on the direction, this can either be the starting position X or Y.
	FormulaFunction expandFormula; // Formula used to calculate the expansion distance from the current time.
	FormulaFunction retractFormula; // Formula used to calculate the retraction distance based on the current time.
	u32 syncTimerOffset; // Timer offset to allow synchronized Skewers to run on a different phase.
	u32 independentTimer; // Timer that governs independent Skewers. Each independent Skewer will run based on when it was first loaded in view.
	u32 retractDuration; // Duration of the Skewer retraction.
	u32 expandDelay; // Delay before the Skewer expansion.
	u32 expandDuration; // Duration of the Skewer expansion.
	u32 retractDelay; // Delay before the Skewer retraction.

};
NTR_SIZE_GUARD(Skewer, 0x620);

class SkewerMgr {
public:

	static constexpr u32 SkewerCount = 12;
	static constexpr u32 ManagerCount = u32(Skewer::SpeedMax);


	SkewerMgr();
	~SkewerMgr();

	bool link(Skewer* skewer);
	bool unlink(Skewer* skewer);
	bool synchronize(u32 unused);

	void updateList();
	void tryActivate();

	static bool isFrameUnlocked();
	static void lockFrame();
	static void unlockFrame();


	static SkewerMgr managers[ManagerCount];
	static bool frameLocked;


	bool active;
	u8 count;
	u32 startTimer;
	Skewer* list[SkewerCount];

};
NTR_SIZE_GUARD(SkewerMgr, 0x38);


class SkewerDown : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 216;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 264;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(SkewerDown, sizeof(Skewer));

class SkewerUp : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 217;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 265;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(SkewerUp, sizeof(Skewer));

class SkewerLeft : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 218;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 266;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(SkewerLeft, sizeof(Skewer));

class SkewerRight : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 219;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 267;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(SkewerRight, sizeof(Skewer));

class DistancedSkewerDown : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 220;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 268;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(DistancedSkewerDown, sizeof(Skewer));

class DistancedSkewerUp : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 221;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 269;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(DistancedSkewerUp, sizeof(Skewer));

class DistancedSkewerLeft : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 222;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 270;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(DistancedSkewerLeft, sizeof(Skewer));

class DistancedSkewerRight : public Skewer { // TODO Remove

	static constexpr u16 ObjectID = 223;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 271;

	static const ActorProfile profile;

};
NTR_SIZE_GUARD(DistancedSkewerRight, sizeof(Skewer));
