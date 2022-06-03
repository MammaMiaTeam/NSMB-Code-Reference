#pragma once
#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/texture.h"


class LargeFlipFenceRenderer
{
public:

	struct VertexPair {

		VecFx16 top;
		VecFx16 bottom;

	};

	// 020F6280
	void init();

	// 020F60F0
	void render();

	// 020F631C
	void computeVertices();

	// 020F601C
	void transformPosition(const Vec3& position, Vec3& out) const;

	// 020F62D4
	bool setupTexture();

	// 020F6304
	static void loadTexture();


	Texture texture;
	VertexPair vertices[3];
	TextureInfo textureInfo;
	s16 rotation;

};
NTR_SIZE_GUARD(LargeFlipFenceRenderer, 0x38);
