//
// Created by Keri Southwood-Smith on 9/23/19.
//

#include "Card.h"

Card::Card(const std::string rank_file, const std::string suit_file, int value) :
    value(value), rank(nullptr), suit(nullptr) {
    std::cout << "Card()\n";
    std::string basepath = Helpers::GetResourcePath();
    std::string rank_path = basepath + rank_file;
    std::string suit_path = basepath + suit_file;

    // load BMP for rank
    rank = SDL_LoadBMP(rank_path.c_str());
    if (rank == nullptr) {
        std::cerr << "LoadBMP error: " << rank_file << SDL_GetError() << std::endl;
    }

    suit = SDL_LoadBMP(suit_path.c_str());
    if (suit == nullptr) {
        std::cerr << "LoadBMP error: " << suit_file << SDL_GetError() << std::endl;
    }
}

Card::~Card() {
    std::cout << "Rank: " << rank << "Suit: " << suit << std::endl;
    SDL_FreeSurface(rank);
    SDL_FreeSurface(suit);
}

int Card::GetValue() {
    return value;
}

SDL_Surface *Card::GetRank() {
    return rank;
}

SDL_Surface *Card::GetSuit() {
    return suit;
}

