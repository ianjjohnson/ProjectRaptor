#include <SDL2/SDL.h>
#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <stdio.h>
#include <string>
#include "main.h"
#include "GameObject.h"
#include "Projectile.h"
#include "Player.h"
#include "TileDrawer.h"
#include "Tile.h"

using namespace std;

const SDL_Rect PAN_RECT = {20,20,WIDTH-40,HEIGHT-40};


int main(int argc, char *argv[]) {
    init();

    Player mario("mario.png", renderer, WIDTH/2, HEIGHT/2);
    TileDrawer tileDrawer(10, 13, renderer);

    loadMedia();

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT)
                quit = true;
            if(e.type == SDL_MOUSEBUTTONDOWN){
                mario.shoot();
            }
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
            mario.move(0,-1);
            if(mario.boundingBox.y < PAN_RECT.y) {
                tileDrawer.panTiles(0,1);
                mario.move(0,1);
            }
        }
        if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
            mario.move(0,1);
            if(mario.boundingBox.y + mario.boundingBox.h > PAN_RECT.y + PAN_RECT.h) {
                tileDrawer.panTiles(0,-1);
                mario.move(0,-1);
            }
        }
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            mario.move(-1,0);
            if(mario.boundingBox.x < PAN_RECT.x) {
                tileDrawer.panTiles(1,0);
                mario.move(1,0);
            }
        }
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
            mario.move(1,0);
            if(mario.boundingBox.x + mario.boundingBox.w > PAN_RECT.x + PAN_RECT.w) {
                tileDrawer.panTiles(-1,0);
                mario.move(-1,0);
            }
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
        printf("Error!\n");

	else {

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
		window = SDL_CreateWindow("Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
            printf("Error!\n");
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
