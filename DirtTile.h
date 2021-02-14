#pragma once
#include "tile.h"
#include <vector>
class DirtTile : public Tile {
public:
	DirtTile(int x, int y) {
		this->x = x;
		this->y = y;
		this->type = 1;
	}
	void init();
	void render();
	void tick();
};



