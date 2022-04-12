#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

/* *********************************************************************************************************************************************
*   Name: Game Class
*   Desc: Here is the primary entry point for the game functions.
*           All of the code here is used to create a 2d engine environtment which utilizes
*           some fundamental game design features, like: entitys component system, texture manager,
*           SDL setup for outputting graphics to the screen. Etc.
*
*           The idea of this class is to be used as a template for future games and as a base engine for 2d development.
*
*           A lot of the code was stripped and inspired by the youtube channel: Let's Make Games (see reference below)
*
*    References: https://www.youtube.com/watch?v=ESNN57ofa3w&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=11&ab_channel=Let%27sMakeGames
*
*   Author: Alex Escatel
*   Version: 0.01
*   Last Updated: 3/10/22
* *********************************************************************************************************************************************/

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());      // player as an entity
auto& wall(manager.addEntity());        // a wall for collision

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)      // initialize SDL subsystems, check for error
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
            printf("Window created\n");

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   // set renderer color to white
            printf("Renderer created\n");
        }
        isRunning = true;
    }
    map = new Map();

    // ecs implementation
    player.addComponent<TransformComponent>(0.0f, 0.0f, 64, 46, 3);
    player.addComponent<SpriteComponent>("assets/mushy-singleframe.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("assets/shitstone.png");
    wall.addComponent<ColliderComponent>("wall");


    // Some examples of using the ecs
    //newPlayer.addComponent<PositionComponent>();    // attach a position component to the player
    //newPlayer.getComponent<PositionComponent()>.setPos(500, 500);   // another example of adjusting a component
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::update()
{
    // each object will have its own update function, this will be a single entrypoint
    manager.refresh();
    manager.update();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, 
                        wall.getComponent<ColliderComponent>().collider))
    
    {
        player.getComponent<TransformComponent>().scale = 1;
        std::cout << "Wall hit!" << std::endl;
    }

    //std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " << newPlayer.getComponent<PositionComponent>().y() << std::endl;   // component system usage example
}

void Game::render() 
{
    // painters algorithm, anything we render first will be on the bottom, anything after comes after it
    SDL_RenderClear(renderer);

    // add more things to render
    map->DrawMap();                 // draw map based on map class
    manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    printf("Game cleaned\n");
}

