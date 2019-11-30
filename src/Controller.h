//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_CONTROLLER_H
#define SDLBLACKJACK_CONTROLLER_H

#include <vector>
#include "Renderer.h"
#include "DeckOfCards.h"

class Controller {
public:
    Controller();

    bool GameInit();
    void GameLoop();


private:
    Renderer rend;
    DeckOfCards deck;

    struct Hand {
        std::vector<Card> cards {};
        uint score {0};
        bool faceup {false};
    };

    Hand dealer;
    Hand player;

    void ClearHands();
    void DealHands();
    void PlayPlayerHand();
    void PlayDealerHand();
    void WhoWon();
    void CenterTexture();
};


#endif //SDLBLACKJACK_CONTROLLER_H
