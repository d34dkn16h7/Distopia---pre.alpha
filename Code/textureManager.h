#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "gameObject.h"
#include "m_rect.h"
using namespace std;
class TextureManager
{
private:
    map<string,sf::Texture> iList;
    map<string,int> aList;
public:
    TextureManager(string source);
    void load(string source);
    void AddTexture(sf::Texture& img,string key,int animCount);
    sf::Texture& GetTexture(string key);
    sf::Texture GetTextureVar(string key);
    int GetAnimCount(string key);
};
#endif


