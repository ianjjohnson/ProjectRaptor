#ifndef _CHUNK_H_
#define _CHUNK_H_
#include <vector>
#include "Tile.h"

class Chunk {
    public:
        Chunk(int, int, int, int, SDL_Renderer*);
        void drawTiles();
        void panTiles(int, int);
    private:
        vector<Tile*> tiles;
        int x, y, width, height, rows, columns;
        SDL_Renderer* mainRenderer;
};

#endif
