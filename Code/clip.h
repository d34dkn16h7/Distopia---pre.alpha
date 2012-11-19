#ifndef CLIP_H
#define CLIP_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class Clip
{
    private:
        sf::Vector2i begin,end,index;
        sf::Vector2f size;
        float timer,tick,timerLimit;
    public:
        Clip(sf::Vector2i b,sf::Vector2i e,sf::Vector2f s);
        void updateIndex();
};
#endif // CLIP_H
