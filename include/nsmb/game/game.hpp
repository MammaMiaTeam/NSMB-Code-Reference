#pragma once

#include <nsmb/core/math/random.hpp>
#include <nsmb/core/math/vector.hpp>
#include <nsmb/core/system/save.hpp>

enum class SceneID : u16;

class Player;

namespace StageGroups
{
	constexpr auto World1 = 0;
	constexpr auto World2 = 1;
	constexpr auto World3 = 2;
	constexpr auto World4 = 3;
	constexpr auto World5 = 4;
	constexpr auto World6 = 5;
	constexpr auto World7 = 6;
	constexpr auto World8 = 7;
	constexpr auto ToadHouse = 8;
	constexpr auto MvsL = 9;
}

namespace StageNodes
{
	constexpr auto Arrow = 0;
	constexpr auto A = 9;
	constexpr auto B = 10;
	constexpr auto C = 11;
	constexpr auto GhostHouse = 12;
	constexpr auto Tower = 13;
	constexpr auto Castle = 14;
	constexpr auto Pipe = 15;
	constexpr auto Cannon = 16;
	constexpr auto RedToadHouse = 17;
	constexpr auto GreenToadHouse = 18;
	constexpr auto YellowToadHouse = 19;
	constexpr auto Fork = 20;
	constexpr auto Tower2 = 21;
	constexpr auto FinalCastle = 22;
	constexpr auto BGChooser = 23;
}

namespace ToadHouses
{
	constexpr auto OneUp = 0;
	constexpr auto Item = 1;
	constexpr auto MegaMushroom = 2;
	constexpr auto BGChooser = 3;
}

namespace MvsLStages
{
	constexpr auto MvsLOverworld = 0;
	constexpr auto MvsLUnderground = 1;
	constexpr auto MvsLIce = 2;
	constexpr auto MvsLPipes = 3;
	constexpr auto MvsLCastle = 4;
}

namespace WrapType
{
	constexpr auto None		 = 0;
	constexpr auto Static	 = 1;
	constexpr auto Scrolling = 2;
}

namespace Game
{

	constexpr s8 DefaultStageEntrance = -1;
	constexpr s8 CheckpointStageEntrance = -2;


	using WrapFunction = void(*)(Vec3&, bool);

	// 02085A18
	extern u8 stageGroup;
	// 02085A14
	extern u8 stageID;
	// 02085A1C
	extern bool checkpointCollected;
	// 02085A4C
	extern u8 stageArea;
	// 02085A50
	extern bool luigiMode;
	// 02085A7C
	extern u32 localPlayerID;
	// 02085A84
	extern u8 vsMode;
	// 02085A88
	extern u32 wrapType;
	// 02085A9C
	extern u32 currentWorldNode;
	// 02085AA4
	extern fx32 wrapX;
	// 02085AA8
	extern fx32 scrollingWrapX;
	// 02085B20
	extern MtxFx43 viewMatrix;
	// 0208B6E8
	extern MtxFx43 modelMatrix;
	// 02039968
	extern WrapFunction wrapFunction;
	// 02088BD4
	extern u32 sceneTimer;
	// 02088BD8
	extern u32 actorTimer;

	NTR_INLINE void wrapPosition(Vec3& position, bool wrapLeft = true) {
		wrapFunction(position, wrapLeft);
	}

	NTR_INLINE void wrapPosition(Vec2& position, bool wrapLeft = true) {
		wrapFunction(reinterpret_cast<Vec3&>(position), wrapLeft);
	}

	NTR_INLINE void wrapPosition(fx32& x, bool wrapLeft = true) {

		if (wrapType == WrapType::None)
			return;

		x &= wrapX;

		if (wrapType == WrapType::Scrolling && wrapLeft) {

			fx32 marginLeft = *reinterpret_cast<fx32*>(0x02085AB0);
			if (x < marginLeft)
				x += wrapX + 1;

		}

	}

	constexpr s32 getStage(u8 group, u8 node) {

		constexpr u8 none = 0xFF;
		constexpr u8 mapping[10][24] =
		{
			/*        0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23	 */
			/*        ^     1     2     3     4     5     6     7     8     A     B     C     GH    TOW   CSTL  PIPE  CANN  RTH   GTH   YTH   FORK  TOW2  FCST  BGCH */
			/* 1 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, none, none, none, 0x05, none, none, none, 0x06, 0x07, none, 0x08, none, none, none, none, none, none, none },
			/* 2 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, none, none, 0x06, none, none, none, 0x07, 0x08, none, 0x09, none, none, none, none, none, none, none },
			/* 3 */ { none, 0x00, 0x01, 0x02, none, none, none, none, none, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, none, 0x09, none, none, none, none, none, none, none },
			/* 4 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, none, none, 0x07, none, none, 0x08, 0x09, 0x0A, none, 0x0B, none, none, none, none, none, none, none },
			/* 5 */ { none, 0x00, 0x01, 0x02, 0x03, none, none, none, none, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, none, 0x0A, none, none, none, none, none, none, none },
			/* 6 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, none, none, 0x06, 0x07, none, none, 0x08, 0x0A, none, 0x0B, none, none, none, none, 0x08, none, none },
			/* 7 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, none, 0x07, none, none, 0x08, 0x09, 0x0A, none, none, none, none, none, none, none, none, none },
			/* 8 */ { none, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, none, none, none, none, 0x08, 0x0A, none, none, none, none, none, none, 0x09, 0x0B, none },
			/* K */ { 0x00, 0x01, 0x02, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, 0x03 },
			/* V */ { 0x00, 0x01, 0x02, 0x03, 0x04, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none, none },
		};

		u8 stage = mapping[group][node];

		return stage == none ? -1 : stage;

	}

	// 02006444
	void setSoundMode(OptionSave::Sound mode);

	// 020064a0
	void loadBackupParams();

	// 0200658c
	void saveBackupParams();

	// 02006674
	void setFrameLength(u8 frames);

	// 02006690
	void setStageCompleted();

	// 020066f8
	void resetStageCheckpoint();

	// 02006740
	void setStageCheckpoint();

	// 02006790
	bool getStageCheckpoint();

	// 0200693C
	u32 getRandom();

	// 0x0200696c
	void loadLevel(u16 scene, u32 vs, u8 group, u8 stage, u8 act, u8 playerID, u8 playerMask, u8 character1, u8 character2, u8 powerup, u8 entrance, u8 flag, u8 unused1, u8 controlOptions, u8 unused2, u8 challengeMode, u32 rngSeed);

	inline void loadLevel(SceneID scene, u32 vs, u8 group, u8 stage, u8 act, u8 playerID, u8 playerMask, u8 character1, u8 character2, u8 powerup, u8 entrance, u8 flag, u8 unused1, u8 controlOptions, u8 unused2, u8 challengeMode, u32 rngSeed) {
		loadLevel(static_cast<u16>(scene), vs, group, stage, act, playerID, playerMask, character1, character2, powerup, entrance, flag, unused1, controlOptions, unused2, challengeMode, rngSeed);
	}

	// 0200dee0
	void stageObjectBankOverlayProc(void* banks, bool load);

	NTR_INLINE void unloadStageObjectBankOverlays(void* banks) {
		stageObjectBankOverlayProc(banks, false);
	}
	NTR_INLINE void loadStageObjectBankOverlays(void* banks) {
		stageObjectBankOverlayProc(banks, true);
	}

	// 02085A70
	extern Random random;

	// 02085A54
	extern u8 randomCallCount;

}
