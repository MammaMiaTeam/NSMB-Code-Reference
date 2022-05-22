#pragma once
#include "nitro_if.h"
#include "nsmb/math/random.h"


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


	// 02088A68
	extern Random random;

	// 02088A48
	extern u8 randomCallCount;

	// 0208885C	
	extern u32 randomBranchAddress;

}
