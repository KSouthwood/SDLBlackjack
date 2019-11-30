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
    std::string name {};
    int width {0};
    int height {0};

public:
    Textures();
    ~Textures();

    bool LoadTexture(SDL_Renderer* rend, const std::string &file);
    void Render(SDL_Rect dest);
    void Render(int x, int y);
};


#endif //SDLBLACKJACK_TEXTURES_H
