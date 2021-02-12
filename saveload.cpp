#include <iostream>
#include <fstream>
#include<list>
#include<string>
#include "world.h";
using namespace std;
using namespace World;

/// <summary>
/// Save a set of tile data to a keystone file
/// </summary>
/// <param name="filename">the name of the file **not a path!**</param>
/// <param name="tiles">the list of the data</param>
void saveTileData(string filename, list<tile> tiles) {
	ofstream saveFile;
	saveFile.open(filename + "_save.keystone");
	//Each row will hold a single tile. This is horrible design. It is also easy design.
	for (const tile tile: tiles) {
		saveFile << tile.x << "|" << tile.y << "|" << tile.type << "|\n";
	}
	saveFile.close();
}

list<tile> loadTileData(string filename) {
	list<tile> tiles;

	//Filestream
	string line;
	ifstream saveStream(filename + "_save.keystone");
	if (saveStream.is_open()) {
		while (getline(saveStream, line)) {

			list<string> components;

			size_t pos = 0;
			std::string token;
			while ((pos = line.find("|")) != std::string::npos) {
				token = line.substr(0, pos);
				components.push_back(token);
				line.erase(0, pos + 1);
			}

			if (components.empty()) {
				cout << "ERROR!!!!! the components list is empty D:";
				return tiles;
			}

			std::list<std::string>::iterator it = components.begin();
			int x = stoi(*it, nullptr);
			advance(it, 1);
			int y = stoi(*it, nullptr);
			advance(it, 1);
			int type = stoi(*it, nullptr);
			
			tiles.push_back(
				tile{
					x,y,type
				}
			);
		}
	}

	return tiles;
}