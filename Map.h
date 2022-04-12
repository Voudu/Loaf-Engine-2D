#pragma once
#include "Game.h"

class Map {

public:
    Map();
    ~Map();

    void LoadMap(int arr[24][40]);
    void DrawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[24][40];

};