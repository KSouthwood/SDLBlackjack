//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include <vector>
#include "Renderer.h"

Renderer::Renderer() {
    std::cout << "Renderer()\n";
}

Renderer::~Renderer() {
    std::cout << "~Renderer()\n";

    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

bool Renderer::InitRenderer() {
    // create window
    window = SDL_CreateWindow("SDLBlackjack", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);

    // check for problems
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        is_valid = false;
    } else {
        // create renderer
        renderer = SDL_CreateRenderer(window, -1,
                                      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            is_valid = false;
        }
    }
    std::cout << "window: " << window << " renderer: " << renderer << std::endl;

    return is_valid;
}

void Renderer::LoadTexturesFromDisk() {
    std::cout << "LoadTexturesFromDisk()\n";
    for (auto tx_to_load : tx_table) {
        tx_map.AddTexture(renderer, tx_to_load.first, tx_to_load.second);
    }
}

SDL_Texture *Renderer::LoadTexture(const std::string &file) {
    const std::string file_path = Helpers::GetResourcePath() + file;
    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = SDL_LoadBMP(file_path.c_str());

    if (surface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (texture == nullptr) {
            std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
        } else {
            std::cerr << "SDL_LoadBMP error: " << SDL_GetError() << std::endl;
        }
    }

    return texture;
}

/******************
 *  Summary: Draw our window
 *
 *  Description: Update the window when called after something changes. Also
 *      takes care of hiding the dealers card.
 *
 *  Parameter(s):
 *      N/A
 */
void Renderer::RenderTable() {
    std::cout << "RenderTable()\n";
    // clear the window and fill with a green background
    SDL_SetRenderDrawColor(renderer, col_bkgrd.r, col_bkgrd.g, col_bkgrd.b, col_bkgrd.a);
    SDL_RenderClear(renderer);

    // display all the headings on the table
    SDL_SetRenderDrawColor(renderer, col_badge.r, col_badge.g, col_badge.b, col_badge.a);
    SDL_RenderFillRect(renderer, &box_dealer);
    tx_map.GetID("dealer")->Render(box_dealer);
    SDL_RenderFillRect(renderer, &box_player);
    tx_map.GetID("player")->Render(box_player);
    SDL_RenderFillRect(renderer, &box_ch_two);
    tx_map.GetID("stand")->Render(box_ch_two);
    SDL_RenderFillRect(renderer, &box_ch_one);
    tx_map.GetID("hit")->Render(box_ch_one);
}

void Renderer::RenderHand(bool dealer, std::vector<Card> cards, bool faceup) {
    // set up initial position for cards
    SDL_Rect card_bkgrd = CARD_RECT;
    card_bkgrd.x += dealer ? DEALER_OFFSET.x : PLAYER_OFFSET.x;
    card_bkgrd.y += dealer ? DEALER_OFFSET.y : PLAYER_OFFSET.y;
    SDL_SetRenderDrawColor(renderer, col_card.r, col_card.g, col_card.b, col_card.a);

    for (u_int i = 0; i < cards.size(); ++i) {
        SDL_RenderFillRect(renderer, &card_bkgrd);
        if (faceup || (i != 0)) {
            tx_map.GetID(cards[i].GetRank())->Render(card_bkgrd.x + RANK_OFFSET.x, card_bkgrd.y + RANK_OFFSET.y);
            tx_map.GetID(cards[i].GetSuit())->Render(card_bkgrd.x + SUIT_OFFSET.x, card_bkgrd.y + SUIT_OFFSET.y);
        }
        card_bkgrd.x += 120;
    }
    SDL_RenderPresent(renderer);
}
