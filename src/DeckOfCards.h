//
// Created by Keri Southwood-Smith on 9/21/19.
//

#ifndef SDLBLACKJACK_DECKOFCARDS_H
#define SDLBLACKJACK_DECKOFCARDS_H

#include <array>

#include "Card.h"

class DeckOfCards {
public:
    DeckOfCards();

    virtual ~DeckOfCards();

    Card** shoe;

private:
    bool shuffle;
    int card_to_deal;
    int reshuffle;

    std::array<int, 13> VALUES = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    const static int CARDS_IN_DECK = 52;

    // filenames
    std::string suits[4] = {"spade.bmp", "club.bmp",
                                         "diamond.bmp", "heart.bmp"};

    std::string blacks[13] = {"black-A.bmp", "black-2.bmp",
                                           "black-3.bmp", "black-4.bmp", "black-5.bmp",
                                           "black-6.bmp", "black-7.bmp", "black-8.bmp",
                                           "black-9.bmp", "black-10.bmp", "black-J.bmp",
                                           "black-Q.bmp", "black-K.bmp"};

    std::string reds[13] = {"red-A.bmp", "red-2.bmp",
                                         "red-3.bmp", "red-4.bmp", "red-5.bmp",
                                         "red-6.bmp", "red-7.bmp", "red-8.bmp",
                                         "red-9.bmp", "red-10.bmp", "red-J.bmp",
                                         "red-Q.bmp", "red-K.bmp"};

    void CreateShoe();
};


#endif //SDLBLACKJACK_DECKOFCARDS_H
