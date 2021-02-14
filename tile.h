#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

class Tile
{
public:
	int x;
	int y;
	int type;
	int height;
	virtual void init();
	virtual void tick();
	virtual void render();
protected:
	std::vector<ALLEGRO_BITMAP*> textures;
};

