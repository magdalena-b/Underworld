#include <iostream>
#include "libtcod.hpp"
#include "Character.hpp"
#include "Map.hpp"
#include "Engine.hpp"

Engine engine;

int main()
{
    while ( !TCODConsole::isWindowClosed() )
    {
    	engine.update();
    	engine.render();
		TCODConsole::flush();
    }

    return 0;
}
