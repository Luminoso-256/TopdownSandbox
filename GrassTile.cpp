#include "GrassTile.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

void GrassTile::init(void) {
	//Load textures
	this->textures.push_back(al_load_bitmap("res/tex/tile/grass.png"));
}

void GrassTile::render(void) {
	renderQueueObject renderObject = renderQueueObject{
		0,
		this->x*16,
		this->y*16
	};
	this->renderQueue.push_back(renderObject);
}

void GrassTile::tick(void) {
	
}