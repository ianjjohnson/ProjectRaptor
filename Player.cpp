#include "Player.h"
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <SDL2/SDL.h>
#include <iostream>


void Player::draw(){
	int x, y;
	SDL_GetMouseState(&x, &y);

	angle = atan2(y-boundingBox.y + boundingBox.h/2, x - boundingBox.x + boundingBox.w/2) * 180 / 3.1415926535897932;

	SDL_RenderCopyEx(mainRenderer, texture, NULL, &boundingBox, angle + 90,  NULL, SDL_FLIP_NONE);

    if(p!=NULL) {
        p->update();
        p->draw();
    }
}

void Player::shoot() {
    delete p;
    p = new Projectile("mario.png", mainRenderer, boundingBox.x, boundingBox.y, 1, 3.1415926535897932*angle/180);
}
