#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>
#include "main.h"
#include "GameObject.h"

using namespace std;

const int WIDTH = 864;
const int HEIGHT = 648;


int main(int argc, char *argv[]) {
	//cout << "Hello, world";
	
    init();

    GameObject mario("mario.png", renderer);

    loadMedia();
    //SDL_BlitSurface(helloWorldSurface,NULL,backgroundSurface,NULL);
    //SDL_UpdateWindowSurface(window);
    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT)
                quit = true;
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
    
        mario.draw();
        //Render objects
        //SDL_RenderCopy(renderer,texture,NULL,&destRect);

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
