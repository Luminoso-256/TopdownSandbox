#pragma once

#include"entity.h"

struct tile {
	int x;
	int y;
	int type;
};
class World {
public:
	list<tile> worldTiles;
	list<Entity> entities;
};

