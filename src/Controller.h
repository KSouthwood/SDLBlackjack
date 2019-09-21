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
    Renderer rend = Renderer();
    DeckOfCards deck = DeckOfCards();

    struct Hand {
        std::vector<int> cards;
        uint score;
        bool faceup;
    };

    void DealHands();
    void PlayPlayerHand();
    void PlayDealerHand();
    void ClearHands();
    void WhoWon();
    void CenterTexture();
};


#endif //SDLBLACKJACK_CONTROLLER_H
