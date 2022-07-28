#pragma once
#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/texture.h"


namespace TextureHelper {

	// 020F5D4C
	void bindTexture(const TextureInfo& info);

	// 020F5D70
	void beginRender(const Vec3& translation, const Vec3& scale);

	// 020F5DDC
	void beginRender(const Vec3& translation, const Vec3& scale, s16 rotationZ);

	// 020F5E48
	void beginRenderNoCulling(const Vec3& translation, const Vec3& scale, s16 rotationZ);

	// 020F5EB4
	void setTextureIndentity();

	// 020F5EE0
	void setDefaultColor();

	// 020F5F08
	void rotateZ(s16 angle);

	// 020F5F38
	TextureInfo* setupTextures(Texture& texture, TextureInfo* info, u32 texParam, u32 beginID, u32 endID);

	// 020F5F90
	void setupTexture(Texture& texture, TextureInfo& info, u32 texParam, u32 texID, u32 palID);

	// 020F5FC4
	u32 getPaletteParams(Texture& texture, u32 palID);

	// 020F5FF0
	u32 getTextureParams(Texture& texture, u32 texID);

}
