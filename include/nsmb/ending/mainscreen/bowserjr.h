#pragma once

#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/blendmodelanm.h"
#include "nsmb/graphics/3d/animation.h"


namespace End {

	class BowserJr {

	public:

		using StateFunction = void(BowserJr::*)();
		using TransitStateFunction = bool(BowserJr::*)();


		inline BowserJr() {}

		inline ~BowserJr() {}

		// 020E09C8
		bool setup();
		// 020E09AC
		bool update();
		// 020E0914
		bool render();
		// 020E090C
		bool destroy();
		// 020E0A24
		bool prepareResources();

		// 020E0834
		bool switchState(s32 stateID);
		// 020E0768
		void callState();

		// 020E0730
		void waitState();
		// 020E0634
		void dragState();
		// 020E0590
		void complainState();
		// 020E0558
		void endState();

		// 020E0760
		bool waitTransitState();
		// 020E06F4
		bool dragTransitState();
		// 020E05EC
		bool complainTransitState();
		// 020E0564
		bool endTransitState();

		// 020E0528
		static Vec3* getPosition();
		// 020E0534
		static void setPosition(const Vec3& position);

		// 020F1570
		static const StateFunction stateFunctions[4];
		// 020F1550
		static const TransitStateFunction transitStateFunctions[4];


		BlendModelAnm model;
		Animation animation; // Unused
		Vec3 position;
		u32 unusedF4;
		s32 stateID;

	};
	NTR_SIZE_GUARD(BowserJr, 0xFC);

}
