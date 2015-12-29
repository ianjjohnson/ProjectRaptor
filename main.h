
SDL_Window* window = NULL;
SDL_Surface* backgroundSurface = NULL;
SDL_Surface* helloWorldSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect destRect;


bool init();

bool loadMedia();

void close();
