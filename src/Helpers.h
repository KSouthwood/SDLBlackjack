//
// Created by Keri Southwood-Smith on 9/23/19.
//

#ifndef SDLBLACKJACK_HELPERS_H
#define SDLBLACKJACK_HELPERS_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "Renderer_Consts.h"

enum CHOICES {NONE, STAND, HIT, PLAY, QUIT, LEFT, RIGHT};

class Helpers {
public:
    static std::string GetResourcePath();
    static CHOICES GetChoice();
};


#endif //SDLBLACKJACK_HELPERS_H
