#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <iostream>
/*
Defines the render queueobject
*/


struct renderQueueObject {
	int textureID; //the texture ID as per the tile/entity's texture list
	int textureX; //Xpos to render at
	int textureY; //Ypos to render at
	int flags; //render flags
};

