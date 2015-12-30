#include <SDL2/SDL.h>

#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


#include "GameObject.h"

GameObject::GameObject(string fileName, SDL_Renderer* r, double initX, double initY){
	boundingBox.x = initX;
	boundingBox.y = initY;
	boundingBox.w = 32;
	boundingBox.h = 32;

	mainRenderer = r;

	loadTexture(fileName);
}

void GameObject::loadTexture(string texturePath) {
    SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError() );
    }
    texture = SDL_CreateTextureFromSurface(mainRenderer,loadedSurface);
    if( texture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError() );
    }
    SDL_FreeSurface(loadedSurface);
}

void GameObject::draw(){

	//int x, y;
	//SDL_GetMouseState(&x, &y);

	//double angle = atan2(y-boundingBox.y + boundingBox.h/2, x - boundingBox.x + boundingBox.w/2) * 180 / 3.1415926535897932;

    SDL_RenderCopy(mainRenderer, texture, NULL, &boundingBox);
	//SDL_RenderCopyEx(mainRenderer, texture, NULL, &boundingBox, angle + 90,  NULL, SDL_FLIP_NONE);
}

GameObject::~GameObject(){
	SDL_DestroyTexture(texture);
	texture = NULL;
}
