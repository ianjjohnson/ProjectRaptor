
SDL_Window* window = NULL;
SDL_Surface* backgroundSurface = NULL;
SDL_Surface* helloWorldSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect destRect;
SDL_Texture* texture;

bool init();

bool loadMedia();

void close();

SDL_Texture* loadTexture(std::string texturePath);
