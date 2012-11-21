#include "clip.h"
#include <iostream>
using namespace std;
Clip::Clip()
{
    begin = sf::Vector2i(0,0);
    end = sf::Vector2i(0,0);
    index = sf::Vector2i(0,0);
    chunkSize = sf::Vector2i(32,32);
}
Clip::Clip(sf::Vector2i size,sf::Vector2i b,sf::Vector2i e)
{
    begin = b;end = e;chunkSize = size;
    index.x = 0;
    index.y = 0;
}
void Clip::updateIndex()
{
    timer += tick;
    if(timer >= timerLimit)
    {
        timer = 0.0f;
        index.x++;
        if(index.x > end.x)
        {
            index.x = begin.x;
            index.y++;
            if(index.y > end.y)
            {
                index.y = begin.y;
            }
        }
        /* UPDATE IMG RECT */
    }
}
void Clip::draw(sf::RenderWindow *r)
{
    r->draw(mySprite);
}
void Clip::updatePos(m_rect r)
{
    mySprite.setPosition(r.c_x,r.top);/*
    cout << "index" << index.x << " : " << index.y << endl;
    cout << "chunkSize" << chunkSize.x << " : " << chunkSize.y << endl;*/
    mySprite.setTextureRect(sf::IntRect(index.x * chunkSize.x,index.y * chunkSize.y,chunkSize.x,chunkSize.y));
}
