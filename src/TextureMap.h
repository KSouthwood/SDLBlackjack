//
// Created by Keri Southwood-Smith on 10/25/19.
//

#ifndef SDLBLACKJACK_TEXTUREMAP_H
#define SDLBLACKJACK_TEXTUREMAP_H


#include <SDL2/SDL_render.h>
#include <string>
#include <map>
#include "Textures.h"

class TextureMap {
public:
    void AddTexture(SDL_Renderer* renderer, const std::string& name, const std::string& filename);
    Textures* GetID(const std::string& name);
    void Cleanup();

private:
    std::map<std::string, Textures*> texmap;
};


#endif //SDLBLACKJACK_TEXTUREMAP_H
