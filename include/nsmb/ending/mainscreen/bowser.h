#pragma once

#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/blendmodelanm.h"
#include "nsmb/graphics/3d/animation.h"
#include "nsmb/graphics/fader.h"


namespace End {

	class alignas(4) Bowser {

	public:

		using StateFunction = void(Bowser::*)();
		using TransitStateFunction = bool(Bowser::*)();


		inline Bowser() {}

		inline ~Bowser() {}

		// 020E1070
		bool setup();
		// 020E1058
		bool update();
		// 020E0FA0
		bool render();
		// 020E0F98
		bool destroy();
		// 020E10CC
		bool prepareResources();

		// 020E0EC0
		bool switchState(s32 stateID);
		// 020E0DF4
		void callState();

		// 020E0DBC
		void waitState();
		// 020E0D24
		void draggedState();
		// 020E0CB0
		void complainState();
		// 020E0A7C
		void endState();

		// 020E0DEC
		bool waitTransitState();
		// 020E0D80
		bool draggedTransitState();
		// 020E0CE8
		bool complainTransitState();
		// 020E0C74
		bool endTransitState();

		// 020F1590
		static const StateFunction stateFunctions[4];
		// 020F1530
		static const TransitStateFunction transitStateFunctions[4];


		BlendModelAnm model;
		Vec3 position;
		bool startedFading;
		u8 endTimer;
		bool cutsceneEnd;
		u8 unusedD7;
		s32 stateID;
		Fader fader;

	};
	NTR_SIZE_GUARD(Bowser, 0x6A4);

}
