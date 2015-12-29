#include "Projectile.h"

using namespace std;

Projectile::Projectile(string fileName, SDL_Renderer* r, double x, double y) : GameObject(fileName, r) { 
    xVel = x;
    yVel = y;
}

void Projectile::update(){
    boundingBox.x = (int)(boundingBox.x + xVel);
    boundingBox.y = (int)(boundingBox.y + yVel);
}
