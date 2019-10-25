//
// Created by Keri Southwood-Smith on 10/25/19.
//

#include "TextureMap.h"

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

void TextureMap::Cleanup() {
    if (texmap.empty() == false) {
        for (auto& tex : texmap) {
            Textures* texture = (Textures*) tex.second;

            if (tex) {
                delete tex;
                tex = nullptr;
            }
        }

        texmap.clear();
    }
}
