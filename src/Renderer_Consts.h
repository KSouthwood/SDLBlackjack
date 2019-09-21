//
// Created by Keri Southwood-Smith on 9/20/19.
//

#ifndef SDLBLACKJACK_RENDERER_CONSTS_H
#define SDLBLACKJACK_RENDERER_CONSTS_H
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

// SDL_Rect's for the positions of the rank and suits
const static SDL_Rect deal_rank = {30, 100, 40, 40};
const static SDL_Rect deal_suit = {30, 140, 40, 40};
const static SDL_Rect play_rank = {30, 340, 40, 40};
const static SDL_Rect play_suit = {30, 380, 40, 40};

// Card positions
const SDL_Rect d_pos[5] = {
        {.x =  20, .y = 90, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 140, .y = 90, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 260, .y = 90, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 380, .y = 90, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 500, .y = 90, .w = CARD_RECT.w, .h = CARD_RECT.h}
};

const SDL_Rect p_pos[5] = {
        {.x =  20, .y = 330, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 140, .y = 330, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 260, .y = 330, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 380, .y = 330, .w = CARD_RECT.w, .h = CARD_RECT.h},
        {.x = 500, .y = 330, .w = CARD_RECT.w, .h = CARD_RECT.h}
};
#endif //SDLBLACKJACK_RENDERER_CONSTS_H
