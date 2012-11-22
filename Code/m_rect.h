#ifndef MRECT_H
#define MRECT_H
#include <SFML/Graphics.hpp>
#include "collider.h"
class Collider;
class M_Rect
{
private:
public:
    float c_x,c_y,w,h;
    float left,top,right,bottom;
    M_Rect();
    M_Rect(float center_x,float center_y,float weight,float height);
    void calc();
    static Collider Intersection(M_Rect first,M_Rect second); // run for all M_Rect?!
    static Collider Intersections(M_Rect rect);
    static bool Contain(M_Rect rc,float x,float y);
    bool Contain(int x,int y);
    bool Contain(sf::Vector2i vec);
};
#endif
