//
// Created by Keri Southwood-Smith on 10/14/19.
//

#include "Textures.h"

Textures::Textures() {}

Textures::~Textures() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

bool Textures::LoadTexture(SDL_Renderer* rend, const std::string &file) {
    std::cout << "LoadTexture(" << file << ")\n";
    bool loaded = false;
    renderer = rend;
    const std::string file_path = Helpers::GetResourcePath() + file;

    if (renderer != nullptr) {
        SDL_Surface* surface = SDL_LoadBMP(file_path.c_str());
        if (surface != nullptr) {
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if (texture == nullptr) {
                std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
            } else {
                name = file;
                width = surface->w;
                height = surface->h;
                loaded = true;
            }
            SDL_FreeSurface(surface);
        } else {
            std::cerr << "SDL_LoadBMP error: " << SDL_GetError() << std::endl;
        }
    } else {
        std::cerr << "NULL renderer passed in.\n";
    }

    return loaded;
}

void Textures::Render(SDL_Rect dest) {
    std::cout << "Render(" << name << ")\n";
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void Textures::Render(int x, int y) {
    std::cout << "Render(" << name << ")\n";
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

