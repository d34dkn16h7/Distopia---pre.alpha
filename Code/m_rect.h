#ifndef MRECT_H
#define MRECT_H
#include <SFML/Graphics.hpp>
#include "collider.h"
class Collider;
class m_rect
{
private:
public:
    float c_x,c_y,w,h;
    float left,top,right,bottom;
    m_rect();
    m_rect(float center_x,float center_y,float weight,float height);
    void calc();
    static Collider intersection(m_rect first,m_rect second);
    static bool contain(m_rect rc,float x,float y);
    bool contain(int x,int y);
    bool contain(sf::Vector2i vec);
};
#endif
