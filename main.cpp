#include "Game.h"

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 768

Game* game = nullptr;

int main(int argc, char* argv[])
{
    
    // lines 12-15 are vars used for limiting frame rate, FPS is our target FPS
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("New Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while(game->running()) {

        frameStart = SDL_GetTicks();                    // get the time since SDL was initialized

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;        // get the time again since SDL was initialized

        if(frameDelay > frameTime)                      // check if the delay we intend is greater than the time difference this frame
        {
            SDL_Delay(frameDelay - frameTime);          // if it is, we delay SDL by the difference in time for this frame to maintain our FPS
        }
    }

    game->clean();

    return 0;
}