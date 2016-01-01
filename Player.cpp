#include "Player.h"
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <SDL2/SDL.h>
#include <stdio.h>


void Player::draw(){
	int x, y;
	SDL_GetMouseState(&x, &y);

	angle = atan2(y-(boundingBox.y + ((double)boundingBox.h)/2.0), x - (boundingBox.x + (double)(boundingBox.w)/2.0)) * 180 / 3.1415926535897932;

	SDL_RenderCopyEx(mainRenderer, texture, NULL, &boundingBox, angle + 90,  NULL, SDL_FLIP_NONE);

    if(p!=NULL) {
        p->update();
        p->draw();
    }
}

void Player::shoot() {
    delete p;
    double radians = 3.1415926535897932*angle/180;
    p = new Projectile("fireball.png", mainRenderer, boundingBox.x, boundingBox.y, 2*cos(radians), 2*sin(radians));
}
