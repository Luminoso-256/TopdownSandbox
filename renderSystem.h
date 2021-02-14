#pragma once
#include "GrassTile.h"
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


class RenderSystemSingleton {
	static RenderSystemSingleton *instance;
	ALLEGRO_BITMAP* textures[1024];
	std::vector<renderQueueObject> renderQueue;
	//private constructor
	RenderSystemSingleton() {
	}

public:
	static RenderSystemSingleton *getInstance() {
		if (!instance) {
			instance = new RenderSystemSingleton;
		}
		return instance;
	}
	//Texture array get/set 
	void setTexture(int slotID, ALLEGRO_BITMAP* texture) {
		textures[slotID] = texture;
	}
	ALLEGRO_BITMAP* getTexture(int slotID) {
		return textures[slotID];
	}
	//render queue
	void addToQueue(renderQueueObject object) {
		renderQueue.push_back(object);
	}
	void clearQueue() {
		renderQueue.clear();
	}

};