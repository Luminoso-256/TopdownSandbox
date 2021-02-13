#pragma once

#include"entity.h"
#include "tile.h"
#include <list>

class World {
public:
	std::list<Tile> worldTiles;
	std::list<Entity> entities;
};

