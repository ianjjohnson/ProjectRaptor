#include "TileDrawer.h"
#include <stdio.h>

//NOTE: change to global variables
const int HEIGHT = 640;
const int WIDTH = 832;

TileDrawer::TileDrawer(int r, int c, SDL_Renderer* renderer) : rows(r), columns(c), mainRenderer(renderer) {
    chunks.push_back(new Chunk(0, 0, rows, columns, mainRenderer));
    numChunks = 1;
    currentChunk = currentChunk;
}

void TileDrawer::drawTiles() {
    for(int i=0;i<numChunks;i++)
        chunks[i]->drawTiles();
}

void TileDrawer::panTiles(int dx, int dy) {
   for(int i=0;i<numChunks;i++)
       chunks[i]->panTiles(dx, dy);
   //NOTE: fix so the current chunk is found rather than currentChunk

   loadChunks();


}

void TileDrawer::loadChunks() {
   //top left chunk
   if(currentChunk->y > 0 && currentChunk->x > 0 && !currentChunk->hasNeighbor[0]) {
       chunks.push_back(new Chunk(currentChunk->x-64*columns,currentChunk->y-64*rows,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[0] = true;
   }

   //top right chunk
   if(currentChunk->y > 0 && currentChunk->x + currentChunk->width < WIDTH && !currentChunk->hasNeighbor[1]) {
       chunks.push_back(new Chunk(currentChunk->x + currentChunk->width,currentChunk->y-64*rows,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[1] = true;
   }

   //top chunk
   if(currentChunk->y > 0 && !currentChunk->hasNeighbor[2]) {
       chunks.push_back(new Chunk(currentChunk->x,currentChunk->y-64*rows,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[2] = true;
   }
   
   //bottom left chunk
   if(currentChunk->y + currentChunk->height < HEIGHT && currentChunk->x > 0 && !currentChunk->hasNeighbor[3]) {
       chunks.push_back(new Chunk(currentChunk->x-64*columns,currentChunk->y + currentChunk->height,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[3] = true;
   }

   //bottom right chunk
   if(currentChunk->y + currentChunk->height < HEIGHT && currentChunk->x + currentChunk->width < WIDTH && !currentChunk->hasNeighbor[4]) {
       chunks.push_back(new Chunk(currentChunk->x + currentChunk->width,currentChunk->y + currentChunk->height,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[4] = true;
   }

   //bottom chunk
   if(currentChunk->y + currentChunk->height < HEIGHT && !currentChunk->hasNeighbor[5]) {
       chunks.push_back(new Chunk(currentChunk->x,currentChunk->y + currentChunk->height,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[5] = true;
   }

   //left chunk
   if(currentChunk->x > 0 && !currentChunk->hasNeighbor[6]) {
       chunks.push_back(new Chunk(currentChunk->x-64*columns,currentChunk->y,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[6] = true;
   }

   //right chunk
   if(currentChunk->x + currentChunk->width < WIDTH && !currentChunk->hasNeighbor[7]) {
       chunks.push_back(new Chunk(currentChunk->x + currentChunk->width,currentChunk->y,rows,columns,mainRenderer));
       numChunks++;
       currentChunk->hasNeighbor[7] = true;
   }
}
