#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "world.h"
#include "player.h"
#include "event.h"
#include "debug.h"

using namespace std;
using namespace sf;

class Game
{
public:
    RenderWindow *window;
    RenderWindow *dbgWindow; //
    TextureManager *textureManager;
    World *world;
    Player *player;
    Game();
    int Run();
    void Draw();
    void Update();
    virtual ~Game();
};

#endif // GAME_H
