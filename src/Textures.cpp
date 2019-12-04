//
// Created by Keri Southwood-Smith on 10/14/19.
//

#include "Textures.h"

Textures::Textures() = default;

Textures::~Textures() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

/******************
 *  Summary: Load surface from file and create texture
 *
 *  Description: Loads a file from disk, creates a surface from it, then creates a texture from that surface, then
 *      deleting the surface. Aborts the process should an error occur at any point printing what the error was.
 *
 *  Parameter(s):
 *      rend - the renderer to use when we display the texture
 *      file - the filename of the image to be loaded
 *
 *  Returns:
 *      bool indicating the success or failure of the texture loading process
 */
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

/******************
 *  Summary: Render the texture to the window
 *
 *  Description: Copy the texture to render target at the supplied coordinates
 *
 *  Parameter(s):
 *      dest - SDL_Rect with the width, height, x and y of where to place the texture
 */
void Textures::Render(SDL_Rect dest) {
    std::cout << "Render(" << name << ")\n";
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

/******************
 *  Summary: Render the texture to the window
 *
 *  Description: Copy the texture to render target at the supplied x and y coordinates
 *
 *  Parameter(s):
 *      x - x coordinate
 *      y - y coordinate
 */
void Textures::Render(int x, int y) {
    std::cout << "RenderXY(" << name << ")\n";
    SDL_Rect dest = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

