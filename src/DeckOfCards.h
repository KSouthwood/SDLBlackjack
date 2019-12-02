//
// Created by Keri Southwood-Smith on 9/21/19.
//

#ifndef SDLBLACKJACK_DECKOFCARDS_H
#define SDLBLACKJACK_DECKOFCARDS_H

#include <array>
#include <random>

#include "Card.h"

class DeckOfCards {
public:
    DeckOfCards();

    virtual ~DeckOfCards();

    Card** shoe = nullptr;

    bool shuffle = false;

    void CreateShoe();
    Card DealCard();
    void ShuffleCards();

private:
    int card_to_deal = 0;

    int reshuffle = 0;
    std::array<int, 13> VALUES = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    const static int CARDS_IN_DECK = 52;

    // filenames
    std::string suits[4] = {"spade", "club",
                                         "diamond", "heart"};

    std::string blacks[13] = {"black-A", "black-2",
                                           "black-3", "black-4", "black-5",
                                           "black-6", "black-7", "black-8",
                                           "black-9", "black-10", "black-J",
                                           "black-Q", "black-K"};

    std::string reds[13] = {"red-A", "red-2",
                                         "red-3", "red-4", "red-5",
                                         "red-6", "red-7", "red-8",
                                         "red-9", "red-10", "red-J",
                                         "red-Q", "red-K"};

};


#endif //SDLBLACKJACK_DECKOFCARDS_H
