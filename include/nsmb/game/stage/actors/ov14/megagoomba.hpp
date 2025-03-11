#pragma once

#include <nsmb/game/stage/entity3danm.hpp>
#include <nsmb/game/physics/segmentplatform.hpp>
#include <nsmb/core/math/math.hpp>
#include <nsmb/core/graphics/3d/animationctrl.hpp>

class MegaGoomba : public StageEntity3DAnm
{
public:
	using StateFunction = bool(MegaGoomba::*)();

	// C1: 0x02132E94
	MegaGoomba();

	// D0: 0x0212F9D0
	// D1: 0x0212F900
	virtual ~MegaGoomba();

	// 0212FD00
	s32 onCreate() override;
	// 0212FAA8
	s32 onDestroy() override;
	// 0212FF24
	bool onPrepareResources() override;

	// 0212FB64
	bool updateMain() override;

	// 02132C80
	void updateFireballWiggle() override;
	// 02131CF0
	void onEntityHit() override;
	// 02131EE8
	void onFireballHit() override;
	// 02131EB4
	void onStarmanHit() override;
	// 02131CEC
	void onSlidingHit() override;
	// 02131CF8
	void onMegaHit() override;
	// 02131CF4
	void onMegaKicked() override;
	// 02131F54
	void onStomped() override;
	// 02131CE8
	void onGroundPound() override;
	// 02131C54
	void onBlueShellHit() override;
	// 02131F58
	void damagePlayer(ActiveCollider& self, Player& player) override;

	// 0212FAF8
	void postRender3D() override;

	// 02132D68
	bool switchState(StateFunction function);
	// 02132D00
	void updateState();
	// 02132C04
	void initHeadPlatform1();
	// 02132B80
	void initHeadPlatform2();
	// 02132AFC
	void initHeadPlatform3();
	// 021329EC
	void giveHeadKnockback(Player* player, bool playerMini);
	// 021328B8
	void damage(bool groundpound);
	// 02132264
	void updateHeadCollision();
	// 02132204
	void linkColliders();
	// 021321A4
	void unlinkColliders();
	// 021320F0
	void updateActiveCollider();
	// 0213209C
	void method0213209C();
	// 02132080
	void method02132080();
	// 02131A18
	void method02131A18();
	// 02131934
	void method02131934();
	// 0213186C
	void method0213186C();
	// 02131684
	void method02131684();
	// 02131650
	bool isPlayerInView();
	// 02131544
	bool waitActivationState();
	// 02131410
	bool activatedState();
	// 0213127C
	bool cutsceneState();
	// 021311E0
	void state021311E0();
	// 02130F30
	bool state02130F30();
	// 02130D60
	bool state02130D60();
	// 02130C10
	bool state02130C10();
	// 02130A44
	bool state02130A44();
	// 02130858
	bool state02130858();
	// 02130700
	bool state02130700();
	// 021305F8
	bool state021305F8();
	// 0213040C
	bool state0213040C();
	// 0213028C
	bool state0213028C();
	// 021300B8
	void defeatedState();
	// 0212FFBC
	void spawnKeyState();

	// 02132E94
	static MegaGoomba* construct();
	// 02132E4C
	static bool loadResources();

	// 021330E8
	static ActorProfile profile;

	AnimationCtrl animationCtrl;
	ActiveCollider activeCollider2;
	FxRect nextActiveColliderRect;
	StateFunction updateFunc;
	StateFunction unkFunc;
	SegmentPlatform headPlatform1;
	SegmentPlatform headPlatform2;
	SegmentPlatform headPlatform3;
	Vec3 unk708;
	Vec3 unk718;
	Vec3 unk728;
	Vec3 unk738;
	fx32 spawnPosX;
	u32 unk74C;
	u32 unk750;
	s32 unk754;
	u32 unk758;
	fx32 playerVelY;
	u32 unk760;
	u8 unk764;
	u8 unk765;
	u8 unk766;
	u8 unk767;
	u32 unk768;
	u32 unk76C;
	u32 unk770;
	u16 unk774;
	u16 unk776;
	u16 unk778;
	u16 unk77A;
	u16 unk77C;
	u16 unk77E;
	u16 unk780;
	u16 unk782;
	u16 unk784;
	u16 unk786;
	u32 unk788;
	u8 unk78C;
	u8 unk78D;
	u8 unk78E;
	u8 unk78F;
	u16 unk790;
	u16 unk792;
	u16 unk794;
	u16 unk796;
	u16 unk798;
	u16 unk79A;
	u16 collidersLinked;
	u16 unk79E;
	u16 unk7A0;
	u16 unk7A2;
	u16 unk7A4;
	u16 growthTimer;
	u16 growsInstantly;
	u16 playerMega;
	u8 unk7AC;
	u8 unk7AD;
	u16 unk7AE;
	u8 playerInView;
	u8 unk7B1;
	u8 unk7B2;
	u8 unk7B3;
	s8 updateStep;
	u8 unk7B5;
	u8 unk7B6;
	u8 unk7B7;
	u32 fogTable[8];
	u8 unk7D8;
	u8 unk7D9;
	u8 unk7DA;
	u8 unk7DB;
	u8 unk7DC;
	u8 unk7DD;
	u8 unk7DE;
	u8 unk7DF;
};

NTR_SIZE_GUARD(MegaGoomba, 0x7E0);
