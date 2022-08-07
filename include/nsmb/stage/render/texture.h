#pragma once
#include "nsmb/math/vector.h"
#include "nsmb/graphics/3d/texture.h"


// overlay 10
namespace TextureHelper {

	void bindTexture(const TextureInfo& info);
	void beginRender(const Vec3& translation, const Vec3& scale);
	void beginRender(const Vec3& translation, const Vec3& scale, s16 rotationZ);
	void beginRenderNoCulling(const Vec3& translation, const Vec3& scale, s16 rotationZ);

	void setTextureIndentity();
	void setDefaultColor();
	void rotateZ(s16 angle);

	TextureInfo* setupTextures(Texture& texture, TextureInfo* info, u32 texParam, u32 beginID, u32 endID);
	void setupTexture(Texture& texture, TextureInfo& info, u32 texParam, u32 texID, u32 palID);
	u32 getPaletteParams(Texture& texture, u32 palID);
	u32 getTextureParams(Texture& texture, u32 texID);

}
