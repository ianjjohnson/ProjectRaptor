#include "TileDrawer.h"
#include <stdio.h>

TileDrawer::TileDrawer(int r, int c, SDL_Renderer* renderer) : rows(r), columns(c),mainRenderer(renderer) {
    //tiles.push_back(Tile("grass.png",mainRenderer,0,0));
    //tiles.push_back(new Tile("grass.png",mainRenderer,0,0));
    for(int i=0;i<rows*columns;i++)
        tiles.push_back(new Tile("grass_border.png",mainRenderer,(i%columns)*64,(i/columns)*64));
}

void TileDrawer::drawTiles() {
    //printf("rows:%d cols:%d",rows,columns);
    for(int i=0;i<rows*columns;i++)
        tiles[i]->draw();
}

void TileDrawer::panTiles(int dx, int dy) {
   for(int i=0;i<rows*columns;i++)
       tiles[i]->move(dx, dy);
}
