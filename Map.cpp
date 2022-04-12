#include "Map.h"
#include "TextureManager.h"

int lvl1[24][40] = {
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 1 ,1 , 1, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1 ,1 , 1, 1, 1, 1 ,1 , 1, 1, 1, 1 ,1 , 1, 0, 0, 0 ,0 , 0, 0, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 1, 1, 1 ,1 , 1, 1, 0, 0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 1, 1 ,1 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 2, 2, 2, 2 ,2 , 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Map::Map()
{
    dirt = TextureManager::LoadTexture("assets/dirt.png");
    grass = TextureManager::LoadTexture("assets/grass.png");
    water = TextureManager::LoadTexture("assets/water.png");

    LoadMap(lvl1);
    
    src.x = src.y = 0;      // start each texture at 0
    src.w = dest.w = 32;    // set our src and dest rect width and height
    src.h = dest.h = 32;

    dest.x = dest.y = 0;

}

Map::~Map()
{
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(water);
}

void Map::LoadMap(int arr[24][40])
{
    for(int row=0; row < 24; row++)
    {
        for(int column=0; column < 40; column++)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;


    for(int row=0; row < 24; row++)
    {
        for(int column=0; column < 40; column++)
        {
            type = map[row][column];

            dest.x = column * 32;
            dest.y = row * 32;

            switch(type)
            {
                case 0:
                    TextureManager::Draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 2:
                    TextureManager::Draw(dirt, src, dest);
                    break;

                default:
                    break;
            }
        }
    }
}