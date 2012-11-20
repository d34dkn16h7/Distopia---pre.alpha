#ifndef DEBUG_H
#define DEBUG_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
class Debug
{
private:
    static bool inited;
    static int fontSize;
    static int msgMax;
    static sf::Font dFont;
    static sf::RenderWindow* msgTarget;
    static vector<sf::Text> messages;
public:
    static void Info(string msg);
    static void Init(string fontFile,sf::RenderWindow* rW,int fSize,int maxMSG);
    static void Warning(string msg);
    static void Error(string msg);
    static void Event(string msg);
    static void Draw();
    static float PreSame(int pos);
};

#endif // DEBUG_H
