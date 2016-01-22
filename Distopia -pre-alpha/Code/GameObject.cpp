#include "gameObject.h"
GameObject::GameObject(string _name,float pos_x,float pos_y,float rot_r)
{
    position.c_x = pos_x;
    position.c_y = pos_y;
    position.h = 32;
    position.w = 32;
    position.calc();
    name = _name;
    rotation = rot_r;
    m_render = new Renderer(name,this);
}
void GameObject::Setup()
{

}
