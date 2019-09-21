//
// Created by Keri Southwood-Smith on 9/20/19.
//

#include "Renderer.h"

Renderer::Renderer() {
    std::cout << "Renderer()\n";
    // create window
    window = SDL_CreateWindow("SDLBlackjack", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN);

    // check for problems
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        is_valid = false;
    }
    else {
        // create renderer
        renderer = SDL_CreateRenderer(window, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            is_valid = false;
        }
    }

    //move these to separate function when working...
    he_one = LoadTexture("Dealer.bmp");
    he_two = LoadTexture("Player.bmp");
    ch_one = LoadTexture("Hit.bmp");
    ch_two = LoadTexture("Stand.bmp");
}

Renderer::~Renderer() {
    std::cout << "~Renderer()\n";
    SDL_DestroyTexture(he_one);
    SDL_DestroyTexture(he_two);
    SDL_DestroyTexture(ch_one);
    SDL_DestroyTexture(ch_two);

    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
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

    // draw the boxes for the options
    SDL_SetRenderDrawColor(renderer, col_badge.r, col_badge.g, col_badge.b, col_badge.a);

    // draw the headings
    SDL_RenderFillRect(renderer, &box_dealer);
    SDL_RenderFillRect(renderer, &box_player);
    SDL_RenderFillRect(renderer, &box_ch_one);
    SDL_RenderFillRect(renderer, &box_ch_two);
    SDL_RenderCopy(renderer, he_one, nullptr, &box_dealer);
    SDL_RenderCopy(renderer, he_two, nullptr, &box_player);
    SDL_RenderCopy(renderer, ch_one, nullptr, &box_ch_one);
    SDL_RenderCopy(renderer, ch_two, nullptr, &box_ch_two);

    // load and display textures
    SDL_SetRenderDrawColor(renderer, col_card.r, col_card.g, col_card.b, col_card.a);

    // draw hands...
}

std::string Renderer::GetResourcePath() {
#ifdef _WIN32
    const char PATH_SEP = '\\';
#else
    const char PATH_SEP = '/';
#endif
    static std::string baseRes;
    if (baseRes.empty()) {
        char *basePath = SDL_GetBasePath();
        if (basePath) {
            baseRes = basePath;
            SDL_free(basePath);
        } else {
            std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
            return "";
        }
        baseRes = baseRes + "res" + PATH_SEP;
    }
    std::cout << "baseRes: " << baseRes << std::endl;
    return baseRes;
}

SDL_Texture* Renderer::LoadTexture(const std::string &file) {
    const std::string filepath = GetResourcePath() + file;

    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = SDL_LoadBMP(filepath.c_str()); // Load the image
    if (surface != nullptr) {
        // surface created ok, now create texture
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        // check texture created without problem
        if (texture == nullptr) {
            std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
        }
    } else {
        std::cerr << "SDL_LoadBMP error: " << SDL_GetError() << std::endl;
    }

    return texture;
}