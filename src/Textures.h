//
// Created by Keri Southwood-Smith on 10/14/19.
//

#ifndef SDLBLACKJACK_TEXTURES_H
#define SDLBLACKJACK_TEXTURES_H

#include <iostream>
#include <string>
#include <SDL2/SDL_render.h>

class Textures {
private:
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

public:
    Textures();
    ~Textures();

    SDL_Texture *LoadTexture(const std::string &file);
    void LoadTextures();
};


#endif //SDLBLACKJACK_TEXTURES_H
