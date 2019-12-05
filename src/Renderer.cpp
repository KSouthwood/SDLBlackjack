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
    tx_map.Cleanup();
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

/******************
 *  Summary: Initialize the renderer
 *
 *  Description: Initialize the window and renderer for use throughout the program.
 *
 *  Parameter(s):
 *      N/A
 *
 *  Returns:
 *      bool to indicate success or not
 */
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

/******************
 *  Summary: Load textures
 *
 *  Description: Iterate through the list of textures and load each one into a map.
 *
 *  Parameter(s):
 *      N/A
 */
void Renderer::LoadTexturesFromDisk() {
    std::cout << "LoadTexturesFromDisk()\n";
    for (const auto& tx_to_load : tx_table) {
        tx_map.AddTexture(renderer, tx_to_load.first, tx_to_load.second);
    }
}

/******************
 *  Summary: Draw our window
 *
 *  Description: Clear the window and draw the badges on top. Usually called once per hand.
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

/******************
 *  Summary: Place the cards of the player and dealer on the table
 *
 *  Description: Place the cards calculating the offset for each one.
 *
 *  Parameter(s):
 *      dealer - boolean to indicate which offset to use
 *      cards - the vector of Card objects to display
 */
void Renderer::RenderHand(bool dealer, const std::vector<Card>& cards) {
    // set up initial position for cards
    SDL_Rect card_bkgrd = CARD_RECT;
    card_bkgrd.x += dealer ? DEALER_OFFSET.x : PLAYER_OFFSET.x;
    card_bkgrd.y += dealer ? DEALER_OFFSET.y : PLAYER_OFFSET.y;
    SDL_SetRenderDrawColor(renderer, col_card.r, col_card.g, col_card.b, col_card.a);

    for (auto card : cards) {
        SDL_RenderFillRect(renderer, &card_bkgrd);
        if (card.faceup) {
            tx_map.GetID(card.GetRank())->Render(card_bkgrd.x + RANK_OFFSET.x, card_bkgrd.y + RANK_OFFSET.y);
            tx_map.GetID(card.GetSuit())->Render(card_bkgrd.x + SUIT_OFFSET.x, card_bkgrd.y + SUIT_OFFSET.y);
        }
        card_bkgrd.x += 120;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
}

/******************
 *  Summary: Display the result of the hand
 *
 *  Description: Center the texture of the result of the hand in the renderer
 *
 *  Parameter(s):
 *      result - the name of the texture to display
 */
void Renderer::ShowWhoWon(const std::string& result) {
    std::cout << "ShowWhoWon(" << result << ")\n";
    // get the dimensions of our renderer
    int rend_width = 0;
    int rend_height = 0;
    SDL_GetRendererOutputSize(renderer, &rend_width, &rend_height);

    // get the dimensions of the texture
    int tex_width = tx_map.GetID(result)->GetWidth();
    int tex_height = tx_map.GetID(result)->GetHeight();

    SDL_Rect center = {(rend_width / 2) - (tex_width / 2),
                       (rend_height / 2) - (tex_height / 2),
                       tex_width, tex_height};

    tx_map.GetID(result)->Render(center);
    SDL_RenderPresent(renderer);
}
