//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_RENDERER_CONSTS_H
#define SDLBLACKJACK_RENDERER_CONSTS_H

#include <map>

// window variables
const int WINDOW_WIDTH  = 620;
const int WINDOW_HEIGHT = 570;

// card variables
const static SDL_Rect  CARD_RECT     = {20, 90, 100, 150}; // position of upper left-most card 
const static SDL_Point DEALER_OFFSET = {0,   0};
const static SDL_Point PLAYER_OFFSET = {0, 240};
const static SDL_Point RANK_OFFSET   = {10, 10};  // amount to offset the rank when we output it
const static SDL_Point SUIT_OFFSET   = {10, 50};  // amount to offset the suit when we output it

// set our colors
const static SDL_Color col_bkgrd = {0x00, 0xA1, 0x00, 0xFF};
const static SDL_Color col_card  = {0xFF, 0xFF, 0xFF, 0xFF};
const static SDL_Color col_badge = {0x00, 0xBF, 0xFF, 0xFF};

// SDL_Rects for the positions of the boxes
const static SDL_Rect box_dealer = {220,  20, 175, 50};
const static SDL_Rect box_player = {220, 260, 175, 50};
const static SDL_Rect box_ch_one = {135, 500, 175, 50};
const static SDL_Rect box_ch_two = {330, 500, 175, 50};

const static std::map<std::string, std::string> tx_table = {
        {"dealer", "Dealer.bmp"},
        {"player", "Player.bmp"},
        {"hit", "Hit.bmp"},
        {"stand", "Stand.bmp"},
        {"play", "Play.bmp"},
        {"quit", "Quit.bmp"},
        {"spade", "spade.bmp"},
        {"club", "club.bmp"},
        {"diamond", "diamond.bmp"},
        {"heart","heart.bmp"},
        {"black-A", "black-A.bmp"},
        {"black-2", "black-2.bmp"},
        {"black-3", "black-3.bmp"},
        {"black-4", "black-4.bmp"},
        {"black-5", "black-5.bmp"},
        {"black-6", "black-6.bmp"},
        {"black-7", "black-7.bmp"},
        {"black-8", "black-8.bmp"},
        {"black-9", "black-9.bmp"},
        {"black-10", "black-10.bmp"},
        {"black-J", "black-J.bmp"},
        {"black-Q", "black-Q.bmp"},
        {"black-K", "black-K.bmp"},
        {"red-A", "red-A.bmp"},
        {"red-2", "red-2.bmp"},
        {"red-3", "red-3.bmp"},
        {"red-4", "red-4.bmp"},
        {"red-5", "red-5.bmp"},
        {"red-6", "red-6.bmp"},
        {"red-7", "red-7.bmp"},
        {"red-8", "red-8.bmp"},
        {"red-9", "red-9.bmp"},
        {"red-10", "red-10.bmp"},
        {"red-J", "red-J.bmp"},
        {"red-Q", "red-Q.bmp"},
        {"red-K", "red-K.bmp"},
};

#endif //SDLBLACKJACK_RENDERER_CONSTS_H
