#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include<list>


//Defines an item in your inventory
struct inventoryItem {
	int type;
	int stackSize;
};

//Defines your inventory
struct inventory {
	inventoryItem hotbar[10]{};
	inventoryItem backpack[30]{};

};

#endif // !INVENTORY_H
