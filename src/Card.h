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
    Card(const std::string& rank_file, const std::string& suit_file,
            int value);
    ~Card();

    int GetValue();
    std::string GetRank();
    std::string GetSuit();

private:
    int value = 0;
    std::string rank = "";
    std::string suit = "";
};


#endif //SDLBLACKJACK_CARD_H
