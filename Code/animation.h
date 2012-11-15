#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include "m_rect.h"
class m_rect;
class Animation
{
private:
    int counter;
    int currentAnimationIndex;
    int animationCount;
    int frameLimit;
    bool updateRecived;
    float chunkSize;
    float scale;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Animation(int animCount,int frame,sf::Texture t);
    void c_update();
    void draw(sf::RenderWindow &window,m_rect pos);
    void s_scale(float s);
};
#endif
