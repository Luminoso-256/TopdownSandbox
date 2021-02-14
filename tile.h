#pragma once
#include <vector>
#include "renderSystem.h"

//class Tile
//{
//public:
//	//Basic data
//	int x;
//	int y;
//	int type;
//	int height;
//
//	//Lifetime methods
//	virtual void init();
//	virtual void tick();
//	virtual void render();
//	  
//};
class Tile {
public:
	int x;
	int y;
	int type;
	int height;
	virtual void init();
	virtual void tick();
	virtual void render();
};