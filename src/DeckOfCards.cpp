//
// Created by Keri Southwood-Smith on 9/21/19.
//

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() :
        shuffle(true), card_to_deal(0), reshuffle(0), shoe(nullptr) {
    std::cout << "DeckOfCards()\n";
    CreateShoe();
}

DeckOfCards::~DeckOfCards() {

}

void DeckOfCards::CreateShoe() {
    std::cout << "CreateShoe()\n";
    shoe = new Card *[CARDS_IN_DECK];

    int rank = 0;
    for (int i = 0; i < CARDS_IN_DECK; i++) {
        rank = i / 26;
        shoe[i] = new Card(rank % 2 ? reds[i % 13] : blacks[i % 13],
                suits[i / 13],
                VALUES[i % 13]);
    }
}