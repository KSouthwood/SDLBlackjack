//
// Created by Keri Southwood-Smith on 9/20/19.
//
#include <SDL2/SDL.h>
//#include <SDL2/SDL_timer.h>

#include "Controller.h"

int main(int, char**) {
    bool success = false;

    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER) == 0) {
        std::cout << "Initializing game.\n";
        Controller game;
        if (game.GameInit()) {
            game.GameLoop();
            success = true;
        }
    }

    SDL_Quit();

    return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}