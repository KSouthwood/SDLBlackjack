//
// Created by Keri Southwood-Smith on 10/14/19.
//

#include "Textures.h"

SDL_Texture *Textures::LoadTexture(const std::string &file) {
    return nullptr;
}

Textures::Textures() {}

Textures::~Textures() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
