#pragma once
#include "nsmb.hpp"

// vtable at 02178AFC (ov66)
class Lakitu : public StageEntity
{
public:

	using StateFunction = bool(Lakitu::*)();

	struct Models : BitFlag<u8> {
		u8 cloud : 1; 	// 0x1
		u8 lakitu : 1;  // 0x2
	};

	enum class Target : u16 {
		Player1,
		Player2,
		FindClosest
	};

	// D0: 021760F0
	// D1: 02176050
	virtual ~Lakitu();

	// 02177064
	s32 onCreate() override; 
	// 02176894
	s32 onDestroy() override;
	// 021769F8
	s32 onRender() override;
	// 0217692C
	void onCleanupResources() override;
	// 021786B0
	bool onPrepareResources() override;

	// 02176FC0
	bool updateMain() override;
	// 02176304
	bool skipRender() override;

	// 02176840
	void onBlockHit() override;
	// 02176750
	void onEntityHit() override;
	// 02176668
	void onFireballHit() override;
	// 02176530
	void onStarmanHit() override;
	// 02176804
	void onStomped() override;
	// 02176440
	void onBlueShellHit() override;
	// 02176C28
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 02176198
	bool checkIfInView(); //returns true and sets lakitu model skipRender if out of player range or outside view 
	// 021779E4
	bool checkCloudTimeout();
	// 02177A40
	bool fallFromCloud();

	// 02176930
	//returns closest player if no player ID is targeted; otherwise it will return the targeted player and get the (floored) distance to it
	Player* getClosestPlayerDistance(s32 playerID, s32* distanceX, s32* distanceY); 

	// 02177CFC
	void throwSpiny();
	// 02177FD8
	void setTargetVelocity(s32 targetPlayerID);

	// 02178598
	void updateState();
	// 021785CC
	bool switchState(StateFunction function); // ?

	// 02177DC8
	bool mainState();
	// 02177260
	bool playerInCloudState();
	// 0217784C
	bool cloudIdleState(); //when no one is riding the cloud
	// 02177AC8
	bool throwSpinyState();
	// 02178088
	bool spawnFromBGState();
	// 02178468
	bool outsideZonestate(); //when spawned with lakitu spawner and outside zone

	inline void cloudSetup() {
		colliderInfo.rect = {0,0,12.0fx,12.0fx};
		colliderInfo.selfGroup = CollisionGroup::Hostile;
		colliderInfo.selfFlag = CollisionFlag::None;
		colliderInfo.checkGroupMask = 3;
		colliderInfo.checkFlagMask = 0;
		colliderInfo.options = 0;
		colliderInfo.callback = StageEntity::damagePlayerCallback;
		activeCollider.init(this,colliderInfo,0);
		activeCollider.link();
		velocity = {0,0,0};
	}

	// 021787AC
	bool loadResources();

	static constexpr u16 objectID = 39;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 53;

	// 02178AF0
	static const ActorProfile profile;

	// 0214E420 (ov42) //part of spiny???
	//static Spiny* spawnSpiny(const Vec3& position, u32 settings);

	// 02178898
	static const s16 rotationsY[2];
	// 0217889C
	static const fx32 velocitiesX[2];


	ModelAnm cloudModel;
	ModelAnm lakituModel;
	AnimationCtrl patternAnimation;
	StateFunction updateFunction;
	StateFunction prevUpdateFunction;
	ActiveColliderInfo colliderInfo;
	Vec3 handPos;
	u32 heldSpinyGUID;
	u32 lakituSpawnerGUID;
	Vec3 lakituPos;
	Vec3s lakituRot;
	fx32 lakituVelY;
	fx32 cloudFlashTimer;
	u16 cooldown; 			// for cloud rotation to camera and spiny throw cooldown 
	u16 cloudFlashes;
	Target targetPlayerID; 
	Models modelsOutOfView;
	s8 updateStep;
	Models activeModels;
	Models skipModelRender;
	s8 mountedPlayerID; 	// ID of a player controlling the cloud

};
NTR_SIZE_GUARD(Lakitu,0x5e4);
