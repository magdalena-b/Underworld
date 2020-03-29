#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
   int x, y;
   int ch;
   TCODColor color;
   int hp;
   Character(int x, int y, int ch, const TCODColor &color, int hp);
   virtual void render() {};
   virtual void attack() {};

   Character operator-(int);


};





class Hero: public Character
{
public:
  Hero(int x, int y, int ch, const TCODColor &color, int hp);
  void render();
  void attack(Character *);
};





class Monster: public Character
{
public:
  Monster(int x, int y, int ch, const TCODColor &color, int hp);
  void render();
  void attack(Character *);
};



#endif
