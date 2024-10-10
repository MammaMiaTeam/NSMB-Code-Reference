#pragma once
#include "nsmb_nitro.hpp"
#include "nsmb/math/random.hpp"

// WARNING: This header is heavily subject to change!

namespace Wifi
{

	// 0200E6A4
	u32 getRandomMG();

	// 0200E6F4
	u32 getRandom();

	// 0200E73C
	u32 syncRandomMG();

	// 0200E748
	u32 syncRandom();

	// 0x02046C34
	u16 getConsoleCount();

	// 020887F0
	extern u8 currentAid;

	// 02088A68
	extern Random random;

	// 02088A48
	extern u8 randomCallCount;

	// 0208885C	
	extern u32 randomBranchAddress;

	// 0x02046C34
	extern u16 consoleCount;

}
