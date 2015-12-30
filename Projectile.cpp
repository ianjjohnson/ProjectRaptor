#include "Projectile.h"

using namespace std;

Projectile::Projectile(string fileName, SDL_Renderer* r, double x, double y, double dx, double dy) : GameObject(fileName, r, x, y) { 
    xVel = dx;
    yVel = dy;
    initX = x;
    initY = y;
    lifeTime = 0;
}

void Projectile::update(){
    lifeTime++;
    boundingBox.x = (int)(lifeTime*xVel) + initX;
    boundingBox.y = (int)(lifeTime*yVel) + initY;
}
