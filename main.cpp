#include "include/Game.h"

Game * Solaris = new Game("Solaris");

int main()
{

    Solaris->init();

    Solaris->run();

    return 0;
}
