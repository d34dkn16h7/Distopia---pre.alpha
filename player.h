#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "main.h"
#include "Manager.h"
#include "temp.h"

class Player : GameObject
{
private:
    //sf::Sprite self[4];
    Animation* self[4];
    float playerHeight;
    float speed;
    float grav;
    bool right,left,up,down;
    bool jump,grounded;
    Force _force;
    float tmp;
public:
    float targetY;
    Player(TextureManager &tManager,float xVal,float yVal);
    void draw();
    void update();
    void input();
    void setPos(float valX,float valY)
    {
        position.c_x = valX;
        position.c_x = valY;
    }
    void groundedUpdate(bool val)
    {
        grounded = val;
    }
    m_rect getPosition()
    {
        return position;
    }
    float gX()
    {
        return position.c_x;
    }
    float gY()
    {
        return position.c_x;
    }
};
#endif
