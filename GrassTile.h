#pragma once
#include "tile.h"
#include <vector>
class GrassTile : private Tile {
public:
	GrassTile(int x, int y) {
		this->x = x;
		this->y = y;
		this->type = 1;
	}
	void init();
	void render();
	void tick();
};
