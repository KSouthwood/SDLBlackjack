//
// Created by Keri Southwood-Smith on 9/23/19.
//

#include "Card.h"

Card::Card(const std::string& rank_file, const std::string& suit_file, int value) :
    value(value), rank(rank_file), suit(suit_file) {
    std::cout << "Card(): " << rank_file << " " << suit_file << std::endl;
}

Card::~Card() {
    std::cout << "~Card(): Rank - " << rank << ", Suit - " << suit << std::endl;
}

int Card::GetValue() {
    return value;
}

std::string Card::GetRank() {
    return rank;
}

std::string Card::GetSuit() {
    return suit;
}

