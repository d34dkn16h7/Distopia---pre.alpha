#include "Manager.h"
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
