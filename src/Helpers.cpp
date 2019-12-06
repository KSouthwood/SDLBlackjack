//
// Created by Keri Southwood-Smith on 9/23/19.
//

#include "Helpers.h"

std::string Helpers::GetResourcePath() {
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
    return baseRes;
}

/******************
 *  Summary: Get a choice from player
 *
 *  Description: Reads the input queue through SDL and returns appropriate enum depending on the key
 *      pressed or which button was clicked.
 *
 *  Parameter(s):
 *      N/A
 */
CHOICES Helpers::GetChoice() {
    SDL_Event e;
    CHOICES choice = NONE;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            choice = QUIT;
        }

        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_h:
                    choice = HIT;
                    break;
                case SDLK_s:
                    choice = STAND;
                    break;
                case SDLK_p:
                    choice = PLAY;
                    break;
                case SDLK_q:
                    choice = QUIT;
                    break;
                default:
                    break;
            }
        }

        if (e.type == SDL_MOUSEBUTTONUP) {
            int x = e.button.x;
            int y = e.button.y;

            if ((x >= box_ch_one.x) && (x <= box_ch_one.x + box_ch_one.w) &&
                    (y >= box_ch_one.y) && (y <= box_ch_one.y + box_ch_one.h)) {
                choice = LEFT;
            }

            if ((x >= box_ch_two.x) && (x <= box_ch_two.x + box_ch_two.w) &&
                (y >= box_ch_two.y) && (y <= box_ch_two.y + box_ch_two.h)) {
                choice = RIGHT;
            }
        }
    }

    return choice;
}
