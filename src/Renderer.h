//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_RENDERER_H
#define SDLBLACKJACK_RENDERER_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Renderer_Consts.h"
#include "Helpers.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    SDL_Renderer *renderer;

    bool is_valid = true;

    void RenderTable();

private:
    SDL_Window *window;

    // Textures for the table headings
    SDL_Texture *dealer;
    SDL_Texture *player;
    SDL_Texture *hit;
    SDL_Texture *stand;
    SDL_Texture *play;
    SDL_Texture *quit;


    void RenderHand();
    SDL_Texture *LoadTexture(const std::string &file);
    void LoadTexturesFromDisk();
};


#endif //SDLBLACKJACK_RENDERER_H
