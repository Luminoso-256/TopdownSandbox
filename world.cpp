#include <list>
#include <string>
using namespace std;

struct tile
{
    int x;
    int y;
    int type;
};

class World {
public:
    list<tile> worldTiles;
    
};