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
Clip::Clip(sf::Vector2i _chunkSize,sf::Vector2i _begin,sf::Vector2i _end)
{
    begin = _begin;
    end = _end;
    chunkSize = _chunkSize;
    index.x = 0;
    index.y = 0;
}
void Clip::Update()
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
        /* UPDATE IMG RECT - NO NEED? */
    }
}
sf::IntRect Clip::GetRect()
{
    return sf::IntRect(index.x * chunkSize.x,index.y * chunkSize.y,  chunkSize.x,chunkSize.y);
}
/*
void Clip::Draw(sf::RenderWindow *r)
{
    r->draw(mySprite);
}
void Clip::UpdatePos(M_Rect r)
{
    mySprite.setPosition(r.c_x,r.top);
    cout << "index" << index.x << " : " << index.y << endl;
    cout << "chunkSize" << chunkSize.x << " : " << chunkSize.y << endl;
    mySprite.setTextureRect(sf::IntRect(index.x * chunkSize.x,index.y * chunkSize.y,chunkSize.x,chunkSize.y));
}*/
