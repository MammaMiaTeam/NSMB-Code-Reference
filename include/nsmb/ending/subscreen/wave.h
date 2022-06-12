#pragma once

#include "nitro_if.h"


namespace End {

	using CharT = u8;


	class Wave {

	public:

		// 020DEC3C
		Wave();
		// 020DEC38
		~Wave();

		// 020DEA18
		void init(u32 x, u32 y);
		// 020DEC04
		void reset();

		// 020DEA8C
		bool isActive();
		// 020DEAA0
		bool isInactive();

		// 020DE914
		void affectChar(s32 charID);
		// 020DE9F0
		bool charAffected(s32 charID);
		// 020DEB8C
		void unaffectString(u32 stringID);

		// 020DE938
		u32 updateChar(u32 x, u32 y, s32 charID, u32 waveID);

		// 020DEB2C
		void updateDistance();
		// 020DEAFC
		void updateBlink();

		// 020DEAB4
		bool getBlink(s32 charID);
		// 020DE770
		s32 getSFXID();
		// 020DE844
		s32 getCharID(u32 x, u32 y);

		// 020DE72C
		static void playSFX(u32 x, u32 y, s32 sfxID);

		// 020E4114
		static u32 standardSFXIDs[26];
		// 020E40BC
		static u32 diacriticsSFXIDs[22];
		// 020E40A0
		static s32 symbolsSFXIDs[7];


		u32 affectDistance;
		u32 affectDistanceSq;
		u32 charAccelleration;
		bool32 active;
		u32 originX;
		u32 originY;
		s32 charID;
		s32 blinkTimer;
		u32 affectedChars[4]; // Bitfield for each wave in the array

	};
	NTR_SIZE_GUARD(Wave, 0x30);


	// 020EEAA4
	extern Wave waves[4];

}
