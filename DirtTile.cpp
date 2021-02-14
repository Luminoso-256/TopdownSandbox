#include "DirtTile.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "const.h"
#include <vector>

void DirtTile::init(void) {
	//Load textures
	this->textures.push_back(al_load_bitmap("res/tex/tile/dirt.png"));
}

void DirtTile::render(void) {
	al_draw_bitmap(this->textures[0],this->x * 16,this->y * 16, 0);
}

void DirtTile::tick(void) {
	//Empty. Dirt currently has no behavior
}