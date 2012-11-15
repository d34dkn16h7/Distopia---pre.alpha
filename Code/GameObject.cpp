#include "gameObject.h"
GameObject::GameObject()
{
    position.c_x = 0;
    position.c_y = 0;
    position.h = 1;
    position.w = 1;
    position.calc();
    name = "null";
    rotation = 0;
}
GameObject::GameObject(string n,float pos_x,float pos_y,float rot_r)
{
    position.c_x = pos_x;
    position.c_y = pos_y;
    position.h = 32;
    position.w = 32;
    position.calc();
    name = n;
    rotation = rot_r;
}
GameObject::GameObject(string n,float pos_x,float pos_y,float rot_r,float w,float h)
{
    position.c_x = pos_x;
    position.c_y = pos_y;
    position.h = w;
    position.w = h;
    position.calc();
    name = n;
    rotation = rot_r;
}
void GameObject::m_event(sf::Vector2i vec)
{
    //std::cout << "Mouse Event!" << std::endl;
    //Send to colliding obj
}
