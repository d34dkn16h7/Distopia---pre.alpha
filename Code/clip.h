#ifndef CLIP_H
#define CLIP_H
#include <SFML/Graphics.hpp>
#include <string>
#include "m_rect.h"
using namespace std;
class Clip
{
private:
    sf::Vector2i begin,end,index;
    sf::Vector2i chunkSize;
    float timer,tick,timerLimit;
    sf::Sprite mySprite;
public:
    bool active;
    Clip();
    Clip(sf::Vector2i size,sf::Vector2i b,sf::Vector2i e);
    void updateTexture(sf::Texture &t)
    {
        mySprite.setTexture(t);
    }
    void updateIndex();
    void updatePos(m_rect r);
    void draw(sf::RenderWindow *r);
};
#endif // CLIP_H
