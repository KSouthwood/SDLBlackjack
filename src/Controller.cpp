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
    ClearHands();

    rend.RenderTable();
    DealHands();

    SDL_RenderPresent(rend.renderer);
    SDL_Delay(2000);
}

/******************
 *  Summary: Set hands to initial values
 *
 *  Description: Set the player and dealer hands to initial values for starting play. Set score to 0,
 *      ensure the vector of Cards is empty, set faceup boolean to false.
 *
 *  Parameter(s):
 *      N/A
 */
void Controller::ClearHands() {
    std::cout << "ClearHands()\n";

    // re-set scores to 0
    player.score = 0;
    dealer.score = 0;

    // clear vectors
    player.cards.clear();
    dealer.cards.clear();

    // set boolean
    player.faceup = true;
    dealer.faceup = false;
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
        rend.RenderHand(false, player.cards);
        SDL_Delay(200);

        dealer.cards.push_back(deck.DealCard());
        if (i == 0) {
            dealer.cards.front().faceup = false;
        }
        rend.RenderHand(true, dealer.cards);
        SDL_Delay(200);
    }
}

void Controller::PlayPlayerHand() {

}

void Controller::PlayDealerHand() {

}

void Controller::WhoWon() {

}

void Controller::CenterTexture() {

}
