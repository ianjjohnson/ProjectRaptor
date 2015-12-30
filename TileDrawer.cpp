#include "TileDrawer.h"
#include <stdio.h>

TileDrawer::TileDrawer(int r, int c, SDL_Renderer* renderer) : rows(r), columns(c),mainRenderer(renderer) {
    //tiles.push_back(Tile("grass.png",mainRenderer,0,0));
    //tiles.push_back(new Tile("grass.png",mainRenderer,0,0));
    for(int i=0;i<rows*columns;i++)
        tiles.push_back(new Tile("grass.png",mainRenderer,(i%columns)*35,(i/columns)*35));
}

void TileDrawer::drawTiles() {
    //printf("rows:%d cols:%d",rows,columns);
    for(int i=0;i<rows*columns;i++)
        tiles[i]->draw();
}
