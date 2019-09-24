//
// Created by keri on 9/23/19.
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