#pragma once
#include "nitro_if.h"


struct TextureInfo {
	u32 texImageParam;
	u32 texPlttBase;
};


//vtable 0203c49c
class Texture
{
public:

	NNSG3dResTex* texture;

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
	sym bool getTexturePaletteDestination(u32& palDest, u32 palID) __rbody //Calls GFX::getTexturePaletteDestination and returns whether address calculation was successful.

};
