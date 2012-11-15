#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream> // tmp
#include "m_rect.h"
#include "event.h"
#include "renderer.h"
using namespace std;
class GameObject
{
private:
protected:
    Renderer *m_render;
public:
    m_rect position;
    float rotation;
    string name;
    GameObject();
    GameObject(string n,float pos_x,float pos_y,float rot_r);
    GameObject(string n,float pos_x,float pos_y,float rot_r,float w,float h);
    static void m_event(sf::Vector2i vec);
    void AddComponent()
    {

    }
};
#endif
