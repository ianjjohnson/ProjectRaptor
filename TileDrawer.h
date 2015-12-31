#ifndef _TILE_DRAWER_H_
#define _TILE_DRAWER_H_
#include <vector>
#include "Tile.h"

using namespace std;

class TileDrawer {
    public:
        TileDrawer(int r, int c, SDL_Renderer*);
        void drawTiles();
        void panTiles(int, int);
    private:
        vector<Tile*> tiles;
        int rows,columns;
        SDL_Renderer* mainRenderer;
};
#endif
