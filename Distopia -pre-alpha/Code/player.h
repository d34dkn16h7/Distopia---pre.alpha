#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "textureManager.h"
#include "gameObject.h"
#include "M_rect.h"

class Player : public GameObject
{
private:
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
    Player() : Player(0,0) {}
    Player(float xVal,float yVal);
    void draw();
    void Update();
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
    M_Rect getPosition()
    {
        return position;
    }
};

#endif //PLAYER_H
