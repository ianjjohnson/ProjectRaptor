#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#ifdef __linux__
    #include <SDL2/SDL_image.h>
#elif __APPLE__
    #include <SDL2_image/SDL_image.h>
#endif
#include <string>

using namespace std;

class GameObject{
    public:
        GameObject(string, SDL_Renderer*, double, double);
        ~GameObject();
        void loadTexture(string texturePath);
        SDL_Texture* texture;  
        SDL_Renderer* mainRenderer;  
        SDL_Rect boundingBox;
        void move(int, int);
        virtual void draw();
};

#endif
