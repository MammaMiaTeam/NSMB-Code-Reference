#pragma once
#include "texture.h"


class PipeRenderer
{
public:

	using RenderFunction = void(PipeRenderer::*)(const Vec3& translation, s16 rotation);

	struct Color {

		static constexpr u32 Green	= 0;
		static constexpr u32 Red	= 1;
		static constexpr u32 Yellow	= 2;

	};

	struct Flags {

		static constexpr u32 Horizontal	= 1;
		static constexpr u32 Mini		= 2;

	};

	struct EndType {

		static constexpr u32 PipeExit	= 0;
		static constexpr u32 PipeBody	= 1;
		static constexpr u32 BrokenPipe	= 2;

	};


	// 020F6528
	void setup(fx32 length, u32 color, u32 flags, u32 topLeftEnd, u32 bottomRightEnd, u32 unused1EB = 0);

	// 020F64AC
	void render(const Vec3& position, s16 rotation = 0);

	// 020F6640
	bool setupTextures();

	// 020F671C
	static void loadTextures();


	// 020F6798
	void renderHorizontal(const Vec3& position, s16 rotation);

	// 020F6B7C
	void renderVertical(const Vec3& position, s16 rotation);

	// 020F6D44
	void renderHorizontalMini(const Vec3& position, s16 rotation);

	// 020F6E80
	void renderVerticalMini(const Vec3& position, s16 rotation);

	// 020F6FB4
	void renderQuad(const Vec2& vertex, const TextureInfo& info, s32 width, s32 height, const Vec2& texCoords);

	// 020F7158
	void assignTextures(u32 color, u32 miniFlag, u32 horizontalFlag, u32 topLeftEnd, u32 bottomRightEnd);


	/*
	*	Texture IDs in the loaded textures array
	*
	*	TL	= Top/Left tile
	*	BR	= Bottom/Right tile
	*	H	= Horizontal tiles
	*	V	= Vertical tiles
	*	C	= Color
	*/

	// 021225B8
	static const u8 miniPipeExitTLTexIDs[2];	// [TL/BR]

	// 021225BC
	static const u8 miniPipeExitBRTexIDs[2];	// [TL/BR]

	// 021225C0
	static const u8 miniPipeBodyTexIDs[2];		// [TL/BR]

	// 021225C4
	static const u8 brokenPipeTLTexIDs[3][2];	// [C]-[TL/BR]

	// 021225CC
	static const u8 brokenPipeBRTexIDs[3][2];	// [C]-[TL/BR]

	// 021225D4
	static const u8 pipeExitBRTexIDs[3][2][2];	// [C] - [H/V] - [TL/BR]

	// 021225E0
	static const u8 pipeExitTLTexIDs[3][2][2];	// [C] - [H/V] - [TL/BR]

	// 021225EC
	static const u8 pipeBodyTexIDs[3][2][2];	// [C] - [H/V] - [TL/BR]


	TextureInfo loadedTextures[56];
	TextureInfo* activeTextures[6];
	TextureInfo** lastActiveTexture;

	RenderFunction renderFunction;

	fx32 length;
	u8 flags;
	u8 topLeftEnd;
	u8 bottomRightEnd;
	u8 unused1EB;

};
NTR_SIZE_GUARD(PipeRenderer, 0x1EC);
