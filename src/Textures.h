//
// Created by Keri Southwood-Smith on 10/14/19.
//

#ifndef SDLBLACKJACK_TEXTURES_H
#define SDLBLACKJACK_TEXTURES_H

#include <iostream>
#include <string>
#include <SDL2/SDL_render.h>
#include "Helpers.h"

class Textures {
private:
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

public:
    Textures();
    ~Textures();

    bool LoadTexture(SDL_Renderer* rend, const std::string &file);
    void Render(SDL_Rect dest);
};


#endif //SDLBLACKJACK_TEXTURES_H
