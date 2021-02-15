#include "GrassTile.h"
#include "tile.h"
#include "world.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <iostream>

void GrassTile::init(void) {
	//Load textures
	//std::cout << "INIT!";
	if (this->containingWorld->textures[0] == nullptr) {
		std::cout << "loading grass tex to slot 0 \n";
		this->containingWorld->textures[0] = al_load_bitmap("res/tex/tile/grass.png");
	}
 //   rs->setTexture(0, al_load_bitmap("res/tex/tile/grass.png"));
}

void GrassTile::render(void) {
	//std::cout << "RENDER!";
	//std::cout << "Tile x/y:  " << this->x << "," << this->y << "\n";
	renderQueueObject renderObject = renderQueueObject{
		0,
		this->x*16,
		this->y*16,
		0
	};

	this->containingWorld->renderQueue.push_back(renderObject);
	
}

void GrassTile::tick(void) {
	
}