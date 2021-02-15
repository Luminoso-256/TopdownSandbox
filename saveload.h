#pragma once
#include <iostream>
#include <fstream>
#include<list>
#include<string>
#include "world.h"
using namespace std;


void saveTileData(string filename, list<Tile> tiles);
list<Tile> loadTileData(string filename);