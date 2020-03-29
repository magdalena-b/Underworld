#include <stdio.h>
#include "libtcod.hpp"
#include "Character.hpp"
#include "Map.hpp"
#include "Engine.hpp"



Engine::Engine()
{

  TCODConsole::initRoot(100, 100, "Underworld", false);

  hero = new Hero(40, 25, '@', TCODColor::white, 20);
  characters.push(hero);

  monster1 = new Monster(60, 13, 'T', TCODColor::green, 10);
  characters.push(monster1);

  monster2 = new Monster(30, 20, 'T', TCODColor::yellow, 10);
  characters.push(monster2);

  monster3 = new Monster(47, 36, 'T', TCODColor::magenta, 10);
  characters.push(monster3);


  map = new Map(100, 100);


}


void Engine::update() {



    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
    switch(key.vk)
    {

        case TCODK_UP :

            if(hero->y - 1 == monster1->y)
            {
              hero->attack(monster1);
            }

            if(hero->y - 1 == monster2->y)
            {
              hero->attack(monster2);
            }

            if(hero->y - 1 == monster3->y)
            {
              hero->attack(monster3);
            }

            if (map->tiles[hero->x+1][hero->y-1]->canWalk() && !(monster1->y == hero->y-1 && monster1->x == hero->x) && !(monster2->y == hero->y-1 && monster2->x == hero->x)
            && !(monster3->y == hero->y-1 && monster3->x == hero->x))
            {
              hero->y--;
            }
            break;

        case TCODK_DOWN :

          if(hero->y + 1 == monster1->y)
          {
            hero->attack(monster1);
          }

          if(hero->y + 1 == monster2->y)
          {
            hero->attack(monster2);
          }

          if(hero->y + 1 == monster3->y)
          {
            hero->attack(monster3);
          }

          if (map->tiles[hero->x][hero->y+1]->canWalk() && !(monster1->y == hero->y+1 && monster1->x == hero->x) && !(monster2->y == hero->y+1 && monster2->x == hero->x)
          && !(monster3->y == hero->y+1 && monster3->x == hero->x))
          {
            hero->y++;
          }
          break;

        case TCODK_LEFT :

          if(hero->x - 1 == monster1->x)
          {
            hero->attack(monster1);
          }

          if(hero->x - 1 == monster2->x)
          {
            hero->attack(monster2);
          }

          if(hero->x - 1 == monster3->x)
          {
            hero->attack(monster3);
          }

          if (map->tiles[hero->x-1][hero->y]->canWalk() && !(monster1->y == hero->y && monster1->x == hero->x-1) && !(monster2->y == hero->y && monster2->x == hero->x-1)
          && !(monster3->y == hero->y && monster3->x == hero->x-1))
          {
            hero->x--;
          }
          break;

        case TCODK_RIGHT :

          if(hero->x + 1 == monster1->x)
          {
            hero->attack(monster1);
          }

          if(hero->x + 1 == monster2->x)
          {
            hero->attack(monster2);
          }

          if(hero->x + 1 == monster3->x)
          {
            hero->attack(monster3);
          }

          if (map->tiles[hero->x+1][hero->y]->canWalk() && !(monster1->y == hero->y && monster1->x == hero->x+1) && !(monster2->y == hero->y && monster2->x == hero->x+1)
          && !(monster3->y == hero->y && monster3->x == hero->x+1))
          {
            hero->x++;
          }
          break;

        default:

          break;
    }
}

void Engine::render() {
	TCODConsole::root->clear();
	map->render();
	for (Character **iterator=characters.begin();
	    iterator != characters.end(); iterator++) {
	    (*iterator)->render();
	}


}
