//
// Created by Keri Southwood-Smith on 9/23/19.
//

#ifndef SDLBLACKJACK_CARD_H
#define SDLBLACKJACK_CARD_H

#include <string>
#include <iostream>
#include <SDL2/SDL_surface.h>

#include "Helpers.h"

class Card {
public:
    Card(std::string rank_file, std::string suit_file, int value);
    ~Card();

    int GetValue();
    SDL_Surface* GetRank();
    SDL_Surface* GetSuit();

private:
    int value;
    SDL_Surface *rank;
    SDL_Surface *suit;
};


#endif //SDLBLACKJACK_CARD_H
