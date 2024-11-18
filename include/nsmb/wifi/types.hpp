#pragma once

#include "nsmb_nitro.hpp"
#include "wireless_shared/mbp.hpp"
#include "wireless_shared/wfs.hpp"
#include "wireless_shared/wh.hpp"

namespace Wifi {

	// TODO: Replace with constant from wireless_shared/wh.hpp
	constexpr u32 MaxConsoleCount = 4;

	constexpr u32 MaxParentScan = 4;

	// TODO: Constant from wireless_shared/wh.hpp
	constexpr u32 SharedDataSize = 0x3E;

	using SharedData = u8[SharedDataSize];

}
