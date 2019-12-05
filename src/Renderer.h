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
#include "Card.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    SDL_Renderer *renderer = nullptr;

    bool is_valid = true;

    void RenderTable();
    bool InitRenderer();
    void LoadTexturesFromDisk();
    void RenderHand(bool dealer, const std::vector<Card>& cards);
    void ShowWhoWon(const std::string& result);

private:
    SDL_Window *window = nullptr;
    // Textures for the table headings
    TextureMap tx_map;
};


#endif //SDLBLACKJACK_RENDERER_H
