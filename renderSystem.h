#pragma once
/*
Defines the render queueobject
*/


struct renderQueueObject {
	int textureID; //the texture ID as per the tile/entity's texture list
	int textureX; //Xpos to render at
	int textureY; //Ypos to render at
};