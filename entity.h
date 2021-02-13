#pragma once
class Entity {
public:
	int posX;
	int posY;
	int health;
	int spriteID; //references the list<bitmap*> for sprites
};