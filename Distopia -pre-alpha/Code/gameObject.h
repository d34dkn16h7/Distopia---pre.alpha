#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream> // tmp
#include <string>
#include <vector>

#include "M_rect.h"
#include "event.h"
#include "renderer.h"

using namespace std;

class Renderer;
class GameObject
{
private:
protected:
    void Setup();
public:
    Renderer *m_render;
    M_Rect position;
    float rotation;
    string name;
    GameObject(){}
    GameObject(string _name,float pos_x,float pos_y,float rot_r);
};
#endif
