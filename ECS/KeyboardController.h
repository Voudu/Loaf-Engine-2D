#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"
#include <iostream>


class KeyboardController : public Component
{
public:
    TransformComponent *transform;

    void init() override
    {
        std::cout << "KeyboardController added and initialized";
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        if(Game::event.type == SDL_KEYDOWN) // when a key is pressed
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = -1;
                break;
            case SDLK_a:
                transform->velocity.x = -1;
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                break;
            case SDLK_s:
                transform->velocity.y = 1;
                break;
            default:
                break;
            }
        }
        if(Game::event.type == SDL_KEYUP) // when a key is pressed
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                break;
            default:
                break;
            }
        }
    }
};
