#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <SDL2/SDL.h>

#include "GameObject.h"
#include "Projectile.h"

using namespace std;

class Player : public GameObject{
    public:
	Player(string name, SDL_Renderer* mainRenderer, double initX, double initY) : GameObject(name,mainRenderer,initX,initY) {p = NULL;};
	
    double angle;
    Projectile* p;
	double xVel, yVel;
	void update();
    void draw();
    void shoot();
};

#endif
