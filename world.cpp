#include <list>
#include <string>
#include "world.h"
#include <vector>
#include <iostream>
#include "tile.h"

void World::init(void) {
	for (Tile tile : this->tiles) {
		tile.init();
	}
}

void World::render(void) {
	//Get the queues updated tile side
	for (int i = 0; i < this->tiles.size(); i++) {
		this->tiles[i].render();
		//std::cout << "tile at index " << i << " has UUID " << this->tiles[i]->UUID << "\n";
	}
	//Update entity queues


	//render everything
	for (renderQueueObject queueObject: this->renderQueue)
	{
		
		al_draw_bitmap(this->textures[queueObject.textureID], queueObject.textureX, queueObject.textureY, queueObject.flags);
	}
}

void World::tick(void) {
	for (Tile tile : this->tiles) {
		tile.tick();
	}
}