#include <SDL2/SDL.h>
#include <iostream>
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

    close();

	return 0;
}

bool init() {
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
		}
    }

    return true;
}

bool loadMedia() {
    helloWorldSurface = SDL_LoadBMP("hello_world.bmp");
    
    return true;
}

void close() {
    SDL_FreeSurface(helloWorldSurface);
    helloWorldSurface = NULL;
	SDL_DestroyWindow(window);
    window = NULL;
	SDL_Quit();
}
