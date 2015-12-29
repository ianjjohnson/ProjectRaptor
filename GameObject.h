using namespace std;

class GameObject{
    public:
        GameObject(string, SDL_Renderer*);
        ~GameObject();
        void loadTexture(string texturePath);
        SDL_Texture* texture;  
        SDL_Renderer* mainRenderer;  
        SDL_Rect boundingBox;
        void draw();
};
