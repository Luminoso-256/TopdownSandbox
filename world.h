#pragma once

#include"entity.h"
#include <vector>
#include <string>
#include "renderSystem.h"
#include "world.fwd.h"
#include "tile.fwd.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class World {
public:
	ALLEGRO_BITMAP* textures[1024];
	std::vector<renderQueueObject> renderQueue;
	std::vector<Tile*> tiles;
	//==Insert entity vec here when i have entity class ready==
	std::string worldName; // name for save/load
	void init();
	void tick();
	void render();
};

