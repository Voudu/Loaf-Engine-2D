#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);                                      // create a surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);   // create a texture from a surface args: renderer, surface
    SDL_FreeSurface(tempSurface);                                                       // once we've created a texture, we no longer need the surface

    return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}