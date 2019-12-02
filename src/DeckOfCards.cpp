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

/******************
 *  Summary: Deals a card by adding to a vector
 *
 *  Description: Takes a vector of Card and adds a new Card to the end. Also updates the
 *      card_to_deal and checks if we need to set the reshuffle flag.
 *
 *  Parameter(s):
 *      hand - the vector of Cards to add a card to
 */
void DeckOfCards::DealCard(std::vector<Card> &hand) {
    hand.push_back(*shoe[card_to_deal++]);
    if (card_to_deal == reshuffle) {
        shuffle = true;
    }
}

/******************
 *  Summary: Calculate the score of a hand
 *
 *  Description: Iterate over a vector of Card's and calculate the total score of the hand
 *      taking into account whether or not it has aces.
 *
 *  Parameter(s):
 *      hand - the vector of Cards to calculate the score for
 */
int DeckOfCards::ScoreHand(const std::vector<Card>& hand) {
    std::cout << "ScoreHand()....\n";
    int score = 0;

    if (!hand.empty()) {
        bool has_ace = false;
        bool soft_count = false;

        for (Card card : hand) {
            int value = card.GetValue();
            if (value == 11) {
                if (!has_ace) {
                    has_ace = true;
                    soft_count = true;
                    score += value;
                } else {
                    score += 1;
                }
            } else {
                score += value;
            }

            // check if we're over 21 with an ace in the hand (soft_count is true after the first ace)
            // if we are, subtract 10 from the score and set soft_count to false
            if ((score > 21) && (soft_count)) {
                soft_count = false;
                score -= 10;
            }
        }
    }

    std::cout << "ScoreHand(): " << score << std::endl;
    return score;
}
