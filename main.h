#ifndef _MAIN_H_
#define _MAIN_H_

const int WIDTH = 832;
const int HEIGHT = 640;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init();

bool loadMedia();

void close();

#endif
