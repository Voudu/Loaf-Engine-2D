#pragma once
#include "SDL2/SDL.h"

class Collision
{
public:
    // access aligned bounding box collision detection
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};