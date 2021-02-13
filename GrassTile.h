#pragma once
#include "tile.h"
class GrassTile : public Tile {
public:
	GrassTile(int x, int y) {
		this->x = x;
		this->y = y;
		this->height = 0; //You  can  walk on grass tiles, unlesss you raise em
		this->type = 2;
		this->textureIndex = 1;
	}
};
