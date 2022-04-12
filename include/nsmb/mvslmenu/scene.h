#pragma once
#include "common.h"
#include "nsmb/entity/scene.h"
#include "nsmb/math/vector.h"


/**
 * The menu right after you click "Mario Vs Luigi" in the titlescreen.
 * In this menu you choose your character and connect to the other console.
 * Depends on overlay 52.
 */
class MvsLMenu : public Scene
{
public:

	class Button
	{
	public:
		enum class AnimType : u8
		{
			Static,
			Lerp,
			SlightMove
		};

		Button(); // C1: 0x0215949C
		~Button(); // D1: 0x02157190

		virtual void update(); // 0x0215734C
		virtual void render(); // 0x021572F0

		void create(s32 bnclRectID, s32 x, s32 y, s32 oamAttrID); // 0x021572C8
		void move(s32 x, s32 y); // 0x021572B4
		void setup(s32 x, s32 y); // 0x02157298
		void click(); // 0x0215727C

		Vec2 position;
		Vec2 endPosition; // Used by AnimType::Lerp
		s32 bnclRectID;
		s32 oamAttrID;
		u8 animFrame; // Used by AnimType::SlightMove
		u8 palette;
		AnimType animType;
		u8 unused;
	};

	class TextButton : public Button
	{
	public:
		TextButton(); // C1: 0x02159464
		~TextButton(); // D1: 0x021571B0

		virtual void update() override; // 0x0215725C
		virtual void render() override; // 0x021571FC

		void setup(s32 x, s32 y, MvsLMenu* owner); // 0x021571DC

		MvsLMenu* owner;
	};

	struct SubMenu
	{
		void (MvsLMenu::*create)();
		void (MvsLMenu::*update)();
		void (MvsLMenu::*render)();
		u32 unused;
	};

	MvsLMenu(); // ctor: 0x02159388
	virtual ~MvsLMenu() override; // D0: 0x0215711C | D1: 0x021570B0

	static void syncInputSchemeWrapper(int aid, MvsLMenu* owner); // 0x02159370
	static void loadMvsLFilesThread(); // 0x0215934C

	virtual s32 onCreate() override; // 0x02158FE8
	virtual s32 onUpdate() override; // 0x02158F40
	virtual s32 onRender() override; // 0x02158EBC
	virtual s32 onDestroy() override; // 0x02158E34

	void scheduleSubMenuChange(SubMenu* subMenu, s32 delay, bool playSound); // 0x02158DE4
	void changeSubMenu(SubMenu *subMenu); // 0x02158D24

	void createSelectModeSM(); // 0x02158BF0
	void updateSelectModeSM(); // 0x021589E0
	void renderSelectModeSM(); // 0x021589DC

	void createCharSelectSM(); // 0x021588C0
	void updateCharSelectSM(); // 0x021586BC
	void renderCharSelectSM(); // 0x0215867C

	void createSearchSM(); // 0x021585E4
	void updateSearchSM(); // 0x021583D8
	void renderSearchSM(); // 0x02158398

	void createConfirmSM(); // 0x021582B8
	void updateConfirmSM(); // 0x02157F24
	void renderConfirmSM(); // 0x02157EE4

	void createWaitHostConfirmSM(); // 0x02157E84
	void updateWaitHostConfirmSM(); // 0x02157CD8
	void renderWaitHostConfirmSM(); // 0x02157C98

	void createPlayerLeftSM(); // 0x02157C2C
	void updatePlayerLeftSM(); // 0x02157BE8
	void renderPlayerLeftSM(); // 0x02157BA8

	void createLoadGameSM(); // 0x02157AE8
	void updateLoadGameSM(); // 0x021577EC
	void renderLoadGameSM(); // 0x02157790

	void createConnectionInterruptedSM(); // 0x02157748
	void updateConnectionInterruptedSM(); // 0x021576D8
	void renderConnectionInterruptedSM(); // 0x02157698

	void selectButton(int id); // 0x0215765C
	void loadSelectModeText(); // 0x02157638
	void updateTextButtonText(); // 0x02157604

	bool startConsoleSearch(); // 0x021575A8
	NicknameInfo* getOpponentNickname(); // 0x021574A4
	void syncInputScheme(int aid); // 0x02157454

	static constexpr u16 objectID = 6;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 14;

	static ObjectProfile profile; // 0x0215BDEC

	/**
	 * selectModeSM = Select if Multi-Card or Download-Play mode
	 * charSelectSM = Select either Mario or Luigi
	 * searchSM = Wait for the search of the other console
	 * confirmSM = Confirm if you want to play with the player you were paired with
	 * waitHostConfirmSM = Wait for the host to confirm if he wants to play with you
	 * playerLeftSM = Shows when other player leaves
	 * loadGameSM = Shows when the game starts loading
	 * connectionInterruptedSM = Shows when the connection is interrupted
	 */

	static SubMenu selectModeSM; // 0x0215CB30
	static SubMenu charSelectSM; // 0x0215CA6C
	static SubMenu searchSM; // 0x022332C4
	static SubMenu confirmSM; // 0x0215CAC0
	static SubMenu waitHostConfirmSM; // 0x0215CB14
	static SubMenu playerLeftSM; // 0x0215CA88
	static SubMenu loadGameSM; // 0x0215CAF8
	static SubMenu connectionInterruptedSM; // 0x0215CADC

	static GXOamAttr* buttonOamAttrs[7]; // 0x0215BEFC

};
