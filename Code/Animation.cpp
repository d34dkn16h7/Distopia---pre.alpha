#include "animation.h"
/*Animation::Animation(int animCount,int frame,sf::Texture t)
{
    scale = 1;
    texture = t;
    counter = 0;
    currentAnimationIndex = 0;
    frameLimit = frame;
    chunkSize = t.getSize().x / animCount;
    animationCount = (int)(t.getSize().x / chunkSize);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(currentAnimationIndex * chunkSize,0,chunkSize,texture.getSize().y));
}
void Animation::c_update()
{
    counter++;
    if(counter > frameLimit)
    {
        currentAnimationIndex++;
        if(currentAnimationIndex >= animationCount)
            currentAnimationIndex = 0;

        counter = 0;
        sprite.setTextureRect(sf::IntRect(currentAnimationIndex * chunkSize,0,chunkSize,texture.getSize().y));
    }
}
void Animation::draw(sf::RenderWindow &window,m_rect pos)
{
    sprite.setPosition(pos.left,pos.top);
    window.draw(sprite);
}
void Animation::s_scale(float s)
{
    scale = s;
    sprite.setScale(s,s);
}
void Animation::loadClips(string fileName)
{
}*/
