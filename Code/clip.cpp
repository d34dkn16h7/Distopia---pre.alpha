#include "clip.h"

Clip::Clip(sf::Vector2i b,sf::Vector2i e,sf::Vector2f s)
{
    begin = b;end = e;size = s;
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
