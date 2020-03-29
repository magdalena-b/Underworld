#include <stdio.h>
#include "libtcod.hpp"
#include "Character.hpp"

Character::Character(int x, int y, int ch, const TCODColor &color, int hp) :
   x(x), y(y), ch(ch), color(color), hp(hp)
{

}


Hero::Hero(int x, int y, int ch, const TCODColor &color, int hp) :
      Character(x, y, ch, color, hp)
{

}


Monster::Monster(int x, int y, int ch, const TCODColor &color, int hp) :
    Character(x, y, ch, color, hp)
{

}


void Hero::render() {
   TCODConsole::root->setChar(x, y, ch);
   TCODConsole::root->setCharForeground(x, y, color);
}

void Monster::render() {
   TCODConsole::root->setChar(x, y, ch);
   TCODConsole::root->setCharForeground(x, y, color);
}



Character Character::operator - (int x)
{
  hp = hp - x;
  return *this;
}


void Hero::attack(Character *character)
{
  *character = *character - 2;
}

void Monster::attack(Character *character)
{
  *character = *character - 4;
}
