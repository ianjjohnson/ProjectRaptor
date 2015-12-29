#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>
#include "main.h"

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;


int main(int argc, char *argv[]) {
	//cout << "Hello, world";
	
    init();

    loadMedia();
    //SDL_BlitSurface(helloWorldSurface,NULL,backgroundSurface,NULL);
    //SDL_UpdateWindowSurface(window);
    

    SDL_Delay(2000);
 
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,&destRect);
    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    close();

	return 0;
}

bool init() {

    destRect.x=0;
    destRect.y=0;
    destRect.w=100;
    destRect.h=100;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		cout << "Error!\n";

	else {

        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

		window = SDL_CreateWindow("Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
			cout << "Error\n";
		else {

            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            }

            SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);

            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            }
		}
    }

    return true;
}

bool loadMedia() {
    helloWorldSurface = SDL_LoadBMP("hello_world.bmp");
    texture = loadTexture("texture.png"); 
    if( texture == NULL )
    {
        printf( "Failed to load texture image!\n" );
    }
    return true;
}

SDL_Texture* loadTexture(string texturePath) {
    SDL_Texture* newTexture= NULL;
    SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError() );
    }
    newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
    if( newTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError() );
    }
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

void close() {
    SDL_FreeSurface(helloWorldSurface);
    helloWorldSurface = NULL;
	SDL_DestroyWindow(window);
    window = NULL;
	SDL_Quit();
}
