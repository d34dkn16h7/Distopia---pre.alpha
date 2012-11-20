#include "gameObject.h"
GameObject::GameObject(string n,float pos_x,float pos_y,float rot_r)
{
    position.c_x = pos_x;
    position.c_y = pos_y;
    position.h = 32;
    position.w = 32;
    position.calc();
    name = n;
    rotation = rot_r;
    m_render = new Renderer(name,this);
}
void GameObject::m_event(sf::Vector2i vec)
{
    //std::cout << "Mouse Event!" << std::endl;
    //Send to colliding obj
}
void GameObject::Setup()
{

}
