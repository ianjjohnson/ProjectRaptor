#ifndef _TILE_H_
#define _TILE_H_

#include "GameObject.h"
#include <string>
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <SDL2/SDL.h>

using namespace std;

class Tile : public GameObject{
    public:
	Tile(string name, SDL_Renderer* mainRenderer, double initX, double initY) : GameObject(name,mainRenderer,initX,initY) {};
};

#endif
