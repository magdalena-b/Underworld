#include <vector>
using namespace std;

#ifndef MAP_H
#define MAP_H


class Tile
{
public:
  int x, y;
  Tile(int x, int y);
  virtual ~Tile() {};
  virtual bool canWalk() = 0;
  virtual void render() {};
};


class Wall : public Tile
{
public:
  Wall(int x, int y);
  bool canWalk();
  void render();

};



class Ground : public Tile
{
public:
  Ground(int x, int y);

  bool canWalk();
  void render();
};


class Map
{
public:
   int width, height;

   Map(int width, int height);
   ~Map();

   void render() const;

  vector < vector < Tile* >  > tiles;

};



#endif
