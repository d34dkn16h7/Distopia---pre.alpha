#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "main.h"
#include "Manager.h"
#include "temp.h"

class Player
{
private:
    int spriteCount;

    int animTimer;

    int animFrontIndex;
    int animRightIndex;
    int animLeftIndex;
    int animJumpIndex;

    int animFrontToNext;
    int animRightToNext;
    int animLeftToNext;
    int animJumpToNext;

    int animFrontLenght;
    int animRightLenght;
    int animLeftLenght;
    int animJumpLenght;

    bool animFrontReset;
    bool animRightReset;
    bool animLeftReset;
    bool animJumpReset;

    sf::Sprite self[4];
    float playerHeight;
    float speed;
    float grav;
    bool right,left,up,down;
    bool jump,grounded;
    Force _force;
public:
    float x,y,targetY;
    Player(TextureManager &tManager,float xVal,float yVal);
    void draw();
    void update();
    void input();
    void setPos(float valX,float valY)
    {
        x = valX;
        y = valY;
    }
};
#endif
