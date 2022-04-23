#pragma once
#include "nitro_if.h"


struct TextureInfo {

	u32 textureParams;
	u32 paletteParams;

};


//vtable 0203c49c
class Texture
{
public:

	//02018c2c
	sym Texture() __body

	//D0:02018bfc
	//D1:02018c1c
	sym virtual ~Texture() __body

	//02018bc8
	sym bool load(void* texFile) __rbody //Loads the texture from the file. returns true if successful, false otherwise.

	//02018b98
	sym bool getTextureParams(u32& texParams, u32 texID) __rbody //Calls GFX::getTextureParams and returns whether parameter fetching was successful.

	//02018b68
	sym bool getPaletteParams(u32& palParams, u32 palID) __rbody //Calls GFX::getTexturePaletteDestination and returns whether address calculation was successful.


	NNSG3dResTex* texture;

};
NTR_SIZE_GUARD(Texture, 0x8);
