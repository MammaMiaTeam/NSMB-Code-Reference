#pragma once

#include <nsmb/core/math/rectangle.hpp>
#include <nsmb/core/math/vector.hpp>

struct StageView {

	struct Rect : public Rectangle<u16> {

		// 0x0201ED98
		static bool overlaps(const Rect& rect, const Rect& viewRect);

		// 0x0201EE60
		static bool contains(const Vec3& position, const Rect& viewRect);

	};

	// 0x0201EF94
	static u8 getAt(const Rect& rect);

	// 0x0201F000
	static u8 getAt(const Vec3& position);

	// 0x0201F06C
	static u16 getHeight(u8 viewID);

	// 0x0201F090
	static u16 getWidth(u8 viewID);

	// 0x0201F0B4
	static u8 getProgressPathID(u8 viewID);

	// 0x0201F0D8
	static u8 getLightType(u8 viewID);

	// 0x0201F0F4
	static u8 getForegroundID(u8 viewID);

	// 0x0201F118
	static u8 getTilesetID(u8 viewID);

	// 0x0201F13C
	static u8 getBackgroundID(u8 viewID);

	// 0x0201F160
	static u8 getCameraSettingsID(u8 viewID);

	// 0x0201F184
	static StageView* get(u8 id, Rectangle<fx32>* outRect);


	Rect rect;
	u8 id;
	u8 cameraSettingsID;
	u8 bgmID;
	u8 backgroundID;
	u8 tilesetID;
	u8 foregroundID;
	u8 lightType;
	u8 progressPathID;

};
NTR_SIZE_GUARD(StageView, 0x10);
