#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

int main(int argc, char *argv[]) {
	//cout << "Hello, world";
	
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		cout << "error";
	else {
		window = SDL_CreateWindow("Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
			cout << "Error";
		else {
			surface = SDL_GetWindowSurface(window);
			SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0xFF,0xFF,0xFF));
			SDL_UpdateWindowSurface(window);

			SDL_Delay(5000);
		}
    }

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
