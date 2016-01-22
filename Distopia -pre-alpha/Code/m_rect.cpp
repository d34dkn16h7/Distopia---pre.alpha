#include "M_rect.h"

M_Rect::M_Rect()
{
    c_x = 0;
    c_y = 0;
    w = 1;
    h = 1;
    calc();
}
M_Rect::M_Rect(float center_x,float center_y,float weight,float height)
{
    c_x = center_x;
    c_y = center_y;
    w = weight;
    h = height;
    calc();
}

void M_Rect::calc()
{
    left = c_x - (w/2);
    right = c_x + (w/2);
    top = c_y - (h/2);
    bottom = c_y + (h/2);
}
Collider M_Rect::Intersection(M_Rect first/* PLAYER */,M_Rect second/* OBJECT */)
{
    Collider col;
    if(first.left == second.left && first.right == second.right)
    {
        col.horizontal = N_Side::Both;
        if(first.bottom == second.bottom && first.top == second.top)
        {
            col.vertical = N_Side::Both;
        }
    }
    else if(first.left < second.left && first.right > second.left)
    {
        if(first.bottom > second.top && first.bottom < second.bottom)
        {
            col.horizontal = N_Side::Left;
            col.vertical = N_Side::Bottom;
            col.x_depth = first.left - second.right;
        }
        else if(first.top < second.bottom && first.top > second.top)
        {
            col.horizontal = N_Side::Left;
            col.vertical = N_Side::Top;
            col.x_depth = first.left - second.right;
        }
    }
    else if(first.right > second.right && first.left < second.right)
    {
        if(first.bottom > second.top && first.bottom < second.bottom)
        {
            col.horizontal = N_Side::Right;
            col.vertical = N_Side::Bottom;
            col.x_depth = second.right - first.left;
        }
        else if(first.top < second.bottom && first.top > second.top)
        {
            col.horizontal = N_Side::Left;
            col.vertical = N_Side::Top;
            col.x_depth = second.right - first.left;
        }
    }
    return col;
}
bool M_Rect::Contain(M_Rect rc,float x,float y)
{
    if(rc.left < x && rc.right > x)
    {
        if(rc.bottom > y && rc.top < y)
            return true;
    }
    return false;
}
bool M_Rect::Contain(int x,int y)
{
    if(left < x && right > x)
    {
        if(bottom > y && top < y)
        {
            return true;
        }
    }
    return false;
}
bool M_Rect::Contain(sf::Vector2i vec)
{
    if(left < vec.x && right > vec.x)
    {
        if(bottom > vec.y && top < vec.y)
        {
            return true;
        }
    }
    return false;
}
