#pragma once
class Tile
{
public:
	int x;
	int y;
	int type;
	int textureIndex;
	int height; //should technically be dictated by type but i want flexibility :D
};

