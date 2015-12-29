#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "GameObject.h"
#include <string>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>

using namespace std;

class Projectile : public GameObject{
    public:
	Projectile(string, SDL_Renderer*, double, double);
	
	double xVel, yVel;
	void update();
};

#endif
