#include "debug.h"
#include <iostream>
using namespace std;
vector<sf::Text> Debug::messages;
sf::RenderWindow* Debug::msgTarget;
sf::Font Debug::dFont;
int Debug::fontSize;
int Debug::msgMax;
bool Debug::inited;
void Debug::Init(string fontFile,sf::RenderWindow* rW,int fSize,int maxMSG)
{
    msgMax = maxMSG;
    fontSize = fSize;
    msgTarget = rW;
    if(!dFont.loadFromFile(fontFile))
        cout << "FONT INIT FAIL" << endl;
    inited = true;
}
void Debug::Info(string msg)
{
    if(inited)
    {
        sf::Text tmpText("Info : " + msg,dFont,fontSize);
        tmpText.setColor(sf::Color(0,255,0));
        messages.push_back(tmpText);
        if(messages.size() > msgMax)
            messages.erase(messages.begin());
    }
}
void Debug::Warning(string msg)
{
    if(inited)
    {
        sf::Text tmpText("Warning : " + msg,dFont,fontSize);
        tmpText.setColor(sf::Color(255,255,0));
        messages.push_back(tmpText);
        if(messages.size() > msgMax)
            messages.erase(messages.begin());
    }
}
void Debug::Event(string msg)
{
    if(false)
    {
        sf::Text tmpText("Event : " + msg,dFont,fontSize);
        tmpText.setColor(sf::Color(150,150,150));
        messages.push_back(tmpText);
        if(messages.size() > msgMax)
            messages.erase(messages.begin());
    }
}
void Debug::Error(string msg)
{
    if(inited)
    {
        sf::Text tmpText("Error : " + msg,dFont,fontSize);
        tmpText.setColor(sf::Color(255,0,0));
        messages.push_back(tmpText);
        if(messages.size() > msgMax)
            messages.erase(messages.begin());
    }
}
void Debug::Draw()
{
    if(inited)
    {
        for(unsigned int i = 0; i < messages.size(); i++)
        {
            messages[i].setPosition(10.0f + PreSame(i),(float)i * 19.0f);
            msgTarget->draw(messages[i]);
        }
    }
}
float Debug::PreSame(int pos)
{
    string msg = messages[pos].getString();
    int depth = 0;
    for(unsigned int i = pos; i > 1; i--)
    {
        if(msg == messages[i-1].getString())
        {
            depth++;
        }
        else
            break;
    }
    return depth * 5.0f;
}
