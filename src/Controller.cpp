//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include "Controller.h"

Controller::Controller() {
    std::cout << "Controller()\n";
}

bool Controller::GameInit() {
    std::cout << "GameInit()\n";
    if (rend.InitRenderer()) {
        rend.LoadTexturesFromDisk();
        deck.CreateShoe();
    }
    return rend.is_valid;
}

void Controller::GameLoop() {
    std::cout << "GameLoop()\n";
    player.faceup = true;   // TODO: delete when not needed
    dealer.faceup = false;

    rend.RenderTable();
    DealHands();

    SDL_RenderPresent(rend.renderer);
    SDL_Delay(2000);
}

/******************
 *  Summary: Deals initial cards
 *
 *  Description: Deal the initial cards to the player and the dealer.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::DealHands() {
    for (int i = 0; i < 2; ++i) {
        player.cards.push_back(deck.DealCard());
        rend.RenderHand(false, player.cards, player.faceup);
        SDL_Delay(200);

        dealer.cards.push_back(deck.DealCard());
        rend.RenderHand(true, dealer.cards, dealer.faceup);
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
