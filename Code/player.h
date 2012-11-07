#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "main.h"
#include "manager.h"
#include "temp.h"

class Player : GameObject
{
private:
    Animation* self[4];
    float playerHeight;
    float speed;
    float grav;
    bool right,left,up,down;
    bool c_right,c_left,c_up,c_down;
    bool jump,grounded;
    Force _force;
    float tmp;
public:
    float targetY;
    Player(TextureManager &tManager,float xVal,float yVal);
    void draw();
    void update();
    void input();
    void GravityUpdate();
    void groundedUpdate(bool val)
    {
        grounded = val;
    }
    void reRect()
    {
        position.calc();
    }
    m_rect getPosition()
    {
        return position;
    }
};
#endif
