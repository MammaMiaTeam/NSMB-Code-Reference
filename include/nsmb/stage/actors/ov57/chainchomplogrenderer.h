#pragma once
#include "nsmb.h"


class ChainChompLogRenderer
{
public:

	// 021726C0
	void render(const Vec3& position, fx32 height);

	// 0217278C
	void create();

	// 021727B0
	bool prepareTexture();

	// 021727E0
	void loadTexture();


	Texture texture;
	TextureInfo texInfo;

};
NTR_SIZE_GUARD(ChainChompLogRenderer, 0x10);
