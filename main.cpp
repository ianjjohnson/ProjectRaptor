#include <SDL2/SDL.h>
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
    SDL_BlitSurface(helloWorldSurface,NULL,backgroundSurface,NULL);
    SDL_UpdateWindowSurface(window);
    

    SDL_Delay(5000);
 
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,destRect);

    close();

	return 0;
}

bool init() {

    destRect.x=0;
    destRect.y=0;
    destRect.w=100;
    destRect.h=100;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		cout << "error";

	else {
		window = SDL_CreateWindow("Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
			cout << "Error";
		else {
			backgroundSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(backgroundSurface,NULL,SDL_MapRGB(backgroundSurface->format,0xFF,0xFF,0xFF));
			SDL_UpdateWindowSurface(window);
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);

            int imgFlags = IMG_INIT_PNG;
            IMG_Init(imgFlags);
		}
    }

    return true;
}

bool loadMedia() {
    helloWorldSurface = SDL_LoadBMP("hello_world.bmp");
    texture = loadTexture("texture.png"); 
    return true;
}

SDL_Texture* loadTexture(string texturePath) {
    SDL_Texture* newTexture= NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
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
