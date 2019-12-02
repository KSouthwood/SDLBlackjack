//
// Created by Keri Southwood-Smith on 9/21/19.
//

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {
    std::cout << "DeckOfCards()\n";
}

DeckOfCards::~DeckOfCards() {
    std::cout << "~DeckOfCards()\n";
    for (int i = 0; i < CARDS_IN_DECK; ++i) {
        delete shoe[i];
    }
}

/******************
 *  Summary: Create the shoe of cards
 *
 *  Description: Creates an array containing the names of the textures for the ranks and suits along with
 *          the value for each card.
 *
 *  Parameter(s):
 *      N/A
 */
void DeckOfCards::CreateShoe() {
    std::cout << "CreateShoe()\n";
    shoe = new Card *[CARDS_IN_DECK];

    int rank = 0;
    for (int i = 0; i < CARDS_IN_DECK; ++i) {
        rank = i / 26;
        shoe[i] = new Card(rank % 2 ? reds[i % 13] : blacks[i % 13],
                suits[i / 13],
                VALUES[i % 13]);
    }

    shuffle = true;
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
Card DeckOfCards::DealCard() {
    Card deal_card = *shoe[card_to_deal++];
    if (card_to_deal == reshuffle) {
        shuffle = true;
    }
    return deal_card;
}

/******************
 *  Summary: Shuffle the deck of cards
 *
 *  Description: Use the Fisher-Yates algorithm to shuffle the deck of cards.
 *
 *  Parameter(s):
 *      N/A
 */
void DeckOfCards::ShuffleCards() {
    std::cout << "ShuffleCards()\n";
    // random number generator set-up
    std::random_device ran_dev;
    std::mt19937 ran_engine(ran_dev());
    std::uniform_int_distribution<int> card_to_swap(0, 51);
    std::uniform_int_distribution<int> reshuffle_card(35, 42);

    Card *temp;
    int swap;

    // Fisher-Yates shuffle algorithm
    for (int card = CARDS_IN_DECK - 1; card > 0; --card) {
        swap = card_to_swap(ran_engine) % card;

        temp = shoe[swap];
        shoe[swap] = shoe[card];
        shoe[card] = temp;
    }

    card_to_deal = 0;
    reshuffle = reshuffle_card(ran_engine);
    shuffle = false;
}
