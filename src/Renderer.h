//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_RENDERER_H
#define SDLBLACKJACK_RENDERER_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "Renderer_Consts.h"
#include "TextureMap.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    SDL_Renderer *renderer = nullptr;

    bool is_valid = true;

    void RenderTable();
    void InitRenderer();
    SDL_Texture *LoadTexture(const std::string &file);

private:

    SDL_Window *window = nullptr;
    // Textures for the table headings
    TextureMap tx_map;
    void RenderHand(bool dealer, std::vector<int> cards, bool faceup);
    void LoadTexturesFromDisk();
};


#endif //SDLBLACKJACK_RENDERER_H
