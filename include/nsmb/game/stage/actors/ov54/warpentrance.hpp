#pragma once

#include <nsmb/game/stage/entity.hpp>

// vtable at 0216D290 (ov54)
class WarpEntrance : public StageEntity
{
public:

	using StateFunction = bool(WarpEntrance::*)();

	struct Settings : BitFlag<u32>
	{
		u32 entranceID : 4;
		u32 height : 4;
		u32 width : 4;
		u32 unused0b12 : 4;
		u32 warpMode : 3;
		u32 wavyTransition : 1;
		u32 stageArea : 4;
		u32 silent : 4;
		u32 allowMega : 4;
	};

	enum class WarpMode : u16
	{
		Normal = 0,
		ClimbingVine = 1,
		Unused2 = 2,
		Delayed = 3
	};

	enum class WarpState : u16
	{
		None = 0,
		Unused1 = 1,
		PlayerShot = 2,
		Normal = 3
	};

	// D0: 02155F60
	// D1: 02155F04
	virtual ~WarpEntrance();

	// 02155FEC
	s32 onCreate() override;
	// 02155FC4
	s32 onRender() override;

	// 02155FCC
	bool updateMain() override;

	// 021565AC
	bool switchState(const StateFunction& function);
	// 02156564
	void updateState();

	// 02156124
	bool mainState();

	// 021564C0
	void warpPlayer(Player* player);
	// 02156274
	bool updateWarpTrigger();

	// 02156638
	static WarpEntrance* construct();

	static constexpr u16 ObjectID = 87;

	static constexpr u16 UpdatePriority = ObjectID;
	static constexpr u16 RenderPriority = 110;

	// 0216D284
	static const ActorProfile profile;

	// 02171760
	static const StateFunction sMain;



	fx32 offsetX;
	fx32 offsetY;
	fx32 sizeX;
	fx32 sizeY;
	Player* collidedPlayer;
	const StateFunction* updateFunction;
	bool32 allowMega;
	u8 entranceID;
	u8 stageArea;
	u16 width;
	u16 height;
	WarpMode warpMode;
	u16 wavyTransition;
	u16 warpCountdown;
	WarpState warpState;
	bool16 changeArea; // not sure about this one
	u16 warpTriggered;
	s8 updateStep;


#if NTR_EXT_EXISTS(WarpEntrance)
	#include NTR_EXT_INCLUDE(WarpEntrance)
#endif

};
#if !NTR_EXT_EXISTS(WarpEntrance)
NTR_SIZE_GUARD(WarpEntrance, 0x424);
#endif
