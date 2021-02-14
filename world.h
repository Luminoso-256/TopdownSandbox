#pragma once

#include"entity.h"
#include "tile.h"
#include <list>
#include <string>

class World {
public:
	std::list<Tile> worldTiles;
	std::list<Entity> entities;
	std::string name;
};

