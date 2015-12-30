#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "GameObject.h"
#include <string>
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <SDL2/SDL.h>

using namespace std;

class Projectile : public GameObject{
    public:
	Projectile(string, SDL_Renderer*, double, double, double, double);
	
	double initX, initY, xVel, yVel;
    int lifeTime;
	void update();
};

#endif
