#ifndef CLIP_H
#define CLIP_H
#include <SFML/Graphics.hpp>
#include <string>
#include "M_rect.h"
using namespace std;
class Clip
{
private:
    sf::Vector2i begin,end,index;
    sf::Vector2i chunkSize;
    float timer,tick,timerLimit;
public:
    bool active;
    Clip();
    Clip(sf::Vector2i _chunkSize,sf::Vector2i _begin,sf::Vector2i _end);
    void Update();
    sf::IntRect GetRect();
};
#endif // CLIP_H
