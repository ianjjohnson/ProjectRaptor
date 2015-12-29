#include <SDL2/SDL.h>
#include <iostream>
#include <string>

using namespace std;

class GameObject{
    public:
        GameObject(string fileName);
        ~GameObject();
        SDL_Texture* texture;    
        double xPos,yPos;
};
