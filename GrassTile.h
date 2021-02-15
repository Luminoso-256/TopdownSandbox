#pragma once
#include "tile.h"
#include <vector>
class GrassTile : public Tile {
public:
	GrassTile(int x, int y, World* containingWorld) {
		this->x = x;
		this->y = y;
		this->type = 1;
		this->containingWorld = containingWorld;
	}
	void init() override;
	void render() override;
	void tick() override;
};
