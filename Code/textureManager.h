#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "debug.h"
using namespace std;
class TextureManager
{
private:
    int imgCount;
    map<string,sf::Texture> iList;
    map<string,string> clip_files;
public:
    TextureManager(){imgCount = 0;}
    TextureManager(string source);
    void load(string source);
    void AddTexture(sf::Texture& img,string key,string clipFile);
    sf::Texture& GetTexture(string key);
    sf::Texture GetTextureVar(string key);
    string GetClipSource(string key);
    int GetCount()
    {
        return imgCount;
    }
};
#endif
