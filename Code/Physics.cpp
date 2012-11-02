#include "Manager.h"
using namespace std;
m_rect::m_rect()
{
    c_x = 0;
    c_y = 0;
    w = 1;
    h = 1;
    calc();
}
m_rect::m_rect(float center_x,float center_y,float weight,float height)
{
    c_x = center_x;
    c_y = center_y;
    w = weight;
    h = height;
    calc();
}
void m_rect::calc()
{
    left = c_x - (w/2);
    right = c_x + (w/2);
    top = c_y - (h/2);
    bottom = c_y + (h/2);
}
Collider m_rect::intersection(m_rect first,m_rect second)
{
    Collider col;
    if(first.left < second.right && first.right > second.left)
    {
        if(first.top < second.bottom && first.bottom > second.top)//
        {
            col.side = Bottom;
            //return true;
        }
    }
    //return false;
    return col;
}
bool m_rect::contain(m_rect rc,float x,float y)
{
    if(rc.left < x && rc.right > x)
    {
        if(rc.bottom < y && rc.top > y)
            return true;
    }
    return false;
}
Collider::Collider()
{
    tag = "null";
    side = None;
}
Collider::Collider(string tag,Side s)
{
//    obj = &gmo;
    side = s;
}
