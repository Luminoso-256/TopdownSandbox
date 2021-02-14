#pragma once

#include"entity.h"
#include "tile.h"
#include <vector>
#include <string>
#include "renderSystem.h"


class World {
public:
	std::vector<Tile*> tiles;
	//==Insert entity vec here when i have entity class ready==
	std::string worldName; // name for save/load
	void init();
	void tick();
	void render();
};

