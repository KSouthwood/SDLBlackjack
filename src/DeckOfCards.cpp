//
// Created by Keri Southwood-Smith on 9/21/19.
//

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {
    std::cout << "DeckOfCards()\n";
}

DeckOfCards::~DeckOfCards() {
    std::cout << "~DeckOfCards()\n";
    for (int i = 0; i < CARDS_IN_DECK; i++) {
        delete shoe[i];
    }
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

/******************
 *  Summary: Deals a card
 *
 *  Description: Returns the index of the current card to be dealt, then
 *      increments the counter. Also checks if we've hit our re-shuffle point
 *      and sets the shuffle flag to true if we have.
 *
 *  Parameter(s):
 *      N/A
 */
int DeckOfCards::DealCard() {
    int card = card_to_deal++;
    if (card_to_deal == reshuffle) {
        shuffle = true;
    }
    return card;
}