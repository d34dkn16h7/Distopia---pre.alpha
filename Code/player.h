#ifndef PLAYER_H
#define PLAYER_H
#include "textureManager.h"
#include "gameObject.h"
#include "animation.h"
#include "m_rect.h"
#include "main.h" //global var
#include <iostream>
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
    float tmp;
    float scale;
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
    void mouseEvent(sf::Vector2i mPos);
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
