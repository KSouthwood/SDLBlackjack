//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_RENDERER_H
#define SDLBLACKJACK_RENDERER_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Renderer_Consts.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    SDL_Renderer *renderer;

    bool is_valid = true;

    void RenderTable();

private:
    SDL_Window *window;
    SDL_Texture *he_one;
    SDL_Texture *he_two;
    SDL_Texture *ch_one;
    SDL_Texture *ch_two;

    void RenderHand();
    static std::string GetResourcePath();
    SDL_Texture *LoadTexture(const std::string &file);
};


#endif //SDLBLACKJACK_RENDERER_H
