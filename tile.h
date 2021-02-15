#pragma once
#include <vector>
#include "renderSystem.h"
#include "tile.fwd.h"
#include "world.fwd.h"
class Tile {
public:
	int x;
	int y;
	
	int type;
	int height;
	World* containingWorld;
	virtual void init();
	virtual void tick();
	virtual void render();
};