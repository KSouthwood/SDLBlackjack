//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include "Controller.h"

Controller::Controller() {
    std::cout << "Controller()\n";
    rend.InitRenderer();
    deck.CreateShoe();
}

bool Controller::GameInit() {
    std::cout << "GameInit()\n";
    return rend.is_valid;
}

void Controller::GameLoop() {
    std::cout << "GameLoop()\n";

    DealHands();

    rend.RenderTable();
    SDL_RenderPresent(rend.renderer);
    SDL_Delay(2000);
}

void Controller::DealHands() {
    for (int i = 0; i < 2; ++i) {
        player.cards.push_back(deck.DealCard());
        // show table...
        SDL_Delay(200);

        dealer.cards.push_back(deck.DealCard());
        // show table...
        SDL_Delay(200);
    }
}

void Controller::PlayPlayerHand() {

}

void Controller::PlayDealerHand() {

}

void Controller::ClearHands() {

}

void Controller::WhoWon() {

}

void Controller::CenterTexture() {

}
