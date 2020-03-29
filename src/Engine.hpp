using namespace std;

#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public :
    TCODList <Character *> characters;

    Hero *hero;
    Monster *monster1;
    Monster *monster2;
    Monster *monster3;
    Map *map;

    Engine();
    ~Engine()
    {};
    void update();
    void render();
};

extern Engine engine;


#endif
