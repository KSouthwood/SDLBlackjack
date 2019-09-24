//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include "Controller.h"

Controller::Controller() :
        rend(Renderer()), deck (DeckOfCards()) {
    std::cout << "Controller()\n";
}

bool Controller::GameInit() {
    std::cout << "GameInit()\n";
    return rend.is_valid;
}

void Controller::GameLoop() {
    std::cout << "GameLoop()\n";
    rend.RenderTable();
    SDL_RenderPresent(rend.renderer);
    SDL_Delay(2000);
}