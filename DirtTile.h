#pragma once
#include "tile.h"
class DirtTile : public Tile {
public:
	DirtTile(int x, int y) {
		this->x = x;
		this->y = y;
		this->height = 0; 
		this->type = 1;
		this->textureIndex = 0;
	}
};

