#include <SDL2/SDL.h>
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <iostream>
#include <string>
#include "main.h"
#include "GameObject.h"
#include "Projectile.h"
#include "Player.h"
#include "TileDrawer.h"
#include "Tile.h"

using namespace std;

const int WIDTH = 832;
const int HEIGHT = 640;


int main(int argc, char *argv[]) {
    init();

    Player mario("mario.png", renderer, 0, 0);
    TileDrawer tileDrawer(10, 5, renderer);

    loadMedia();

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_MOUSEBUTTONDOWN){
                //delete p;
                //p = new Projectile("mario.png", renderer, 0, 0, 1, 1);
                mario.shoot();
            }
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
            mario.boundingBox.y = mario.boundingBox.y - 1;
        }
        if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
            mario.boundingBox.y = mario.boundingBox.y + 1;
        }
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            mario.boundingBox.x = mario.boundingBox.x - 1;
        }
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
            mario.boundingBox.x = mario.boundingBox.x + 1;
        }
        
        SDL_RenderClear(renderer);
   
    tileDrawer.drawTiles();
	mario.draw();

    SDL_RenderPresent(renderer);
    }    


    close();

	return 0;
}


bool init() {

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		cout << "Error!\n";

	else {

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
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

bool loadMedia(){
    return true;
}

void close() {
	SDL_DestroyWindow(window);
    window = NULL;
	SDL_Quit();
}
