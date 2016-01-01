#include "TileDrawer.h"
#include <stdio.h>

TileDrawer::TileDrawer(int r, int c, SDL_Renderer* renderer) : rows(r), comumns(c), mainRenderer(renderer) {
    chunks.push_back(new Chunk(0, 0, rows, columns, mainRenderer));
    numChunks = 1;
}

void TileDrawer::drawTiles() {
    for(int i=0;i<numChunks;i++)
        chunks[i]->drawTiles();
}

void TileDrawer::panTiles(int dx, int dy) {
   for(int i=0;i<numChunks;i++)
       chunks[i]->panTiles(dx, dy);
   //NOTE: fix so the current chunk is found rather than chunks[0]
   if(chunks[0].y > 0)
       chunks.push_back(new Chunk(chunks[0].y-64*rows,chunks[0].x));
   //NOTE: finish
   //if(chunks[0].y + chunks[0].height < 
}
