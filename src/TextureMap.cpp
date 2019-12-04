//
// Created by Keri Southwood-Smith on 10/25/19.
//

#include "TextureMap.h"

/******************
 *  Summary: Add texture to texture map
 *
 *  Description: Adds a texture to the texture map with a specific name
 *
 *  Parameter(s):
 *      renderer - renderer in use
 *      name - the name of the texture
 *      filename - filename of texture to load
 */
void TextureMap::AddTexture(SDL_Renderer *renderer, std::string name, std::string filename) {
    if (name != "") {
        Textures* new_tex = new Textures();
        if (new_tex->LoadTexture(renderer, filename) == false) {
            std::cerr << "Couldn't load texture: " << filename << std::endl;
        } else {
            texmap[name] = new_tex;
        }
    }
}

/******************
 *  Summary: Frees all memory associated with the textures
 *
 *  Description: Iterates through the texture map freeing all memory associated with the textures
 *
 *  Parameter(s):
 *      N/A
 */
void TextureMap::Cleanup() {
    if (texmap.empty() == false) {
        for (auto& tex : texmap) {
            Textures* texture = (Textures*) tex.second;

            if (texture) {
                delete texture;
                texture = nullptr;
            }
        }

        texmap.clear();
    }
}

/******************
 *  Summary: Return a texture of a specific ID
 *
 *  Description:
 *
 *  Parameter(s):
 *      name - ID to get texture of
 *
 *  Returns:
 *      texture of the requested ID or nullptr if the ID is not in the map
 */
Textures *TextureMap::GetID(std::string name) {
    return (texmap.find(name) == texmap.end()) ? nullptr : texmap[name];
}
