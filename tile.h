#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "renderSystem.h"

class Tile
{
public:
	//Basic data
	int x;
	int y;
	int type;
	int height;

	//Render system
	std::vector<renderQueueObject> renderQueue;
	std::vector<ALLEGRO_BITMAP*> textures;

	//Lifetime methods
	virtual void init();
	virtual void tick();
	virtual void render();

};

