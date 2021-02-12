#pragma once
#include <iostream>
#include <fstream>
#include<list>
#include<string>
#include "world.h";
using namespace std;
using namespace World;


void saveTileData(string filename, list<tile> tiles);
list<tile> loadTileData(string filename);