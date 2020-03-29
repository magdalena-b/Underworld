#include <vector>
#include <random>
#include "libtcod.hpp"
#include "Map.hpp"
using namespace std;


Tile::Tile(int x, int y) : x(x), y(y)
{

}


Wall::Wall(int x, int y) :
  Tile(x, y)
  {
  }

void Wall::render()
{
  static const TCODColor color(31, 31, 31);
  TCODConsole::root->setCharBackground(x, y, color);
}

bool Wall::canWalk()
{
  return false;
}

Ground::Ground(int x, int y) :
  Tile(x, y)
  {
  }


void Ground::render()
{
  static const TCODColor color(255, 0, 63);
  TCODConsole::root->setCharBackground(x, y, color);
}

bool Ground::canWalk()
{
  return true;
}

Map::Map(int width, int height) : width(width), height(height)
{

for (int x = 0; x < width; x++)
{
  vector <Tile* > wysokosc;
  for(int y = 0; y < height; y++)
  {
    wysokosc.push_back(new Ground(x, y));
  }
  tiles.push_back(wysokosc);
}


for (int i = 0; i < 80; i++)
{
  int x = rand()%width;
  int y = rand()%height;
  tiles[x][y] = new Wall(x, y);
}


}



void Map::render() const
{

  for (int x = 0; x < width; x++)
  {
    for (int y = 0; y < height; y++)
    {
      tiles[x][y]->render();
    }
  }

}
