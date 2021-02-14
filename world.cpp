#include <list>
#include <string>
#include "world.h"
#include <vector>
#include <iostream>

void World::init(void) {
	for (Tile* tile : this->tiles) {
		tile->init();
	}
}

void World::render(void) {
	//Get the queues updated tile side
	for (Tile* tile : this->tiles) {
		tile->render();
	}
	//Update entity queues


	//render everything
	RenderSystemSingleton* rs = rs->getInstance();
	al_draw_bitmap(rs->getTexture(0), 13, 60, 0);
}

void World::tick(void) {
	for (Tile* tile : this->tiles) {
		tile->tick();
	}
}