#ifndef MANAGER_H
    #define MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
//#include <SFML/Graphics.hpp>

using namespace std;
typedef void (*CallBack)(void);

class TextureManager
{
private:
    map<string,sf::Texture> iList;
    map<string,int> aList;
public:
    TextureManager() {}
    ~TextureManager() {}
    void load(string source)
    {
        ifstream file(source.c_str());
        string fName,tag;
        int animCount;
        while(file >> fName >> tag >> animCount)
        {
            sf::Texture tempImg;
            tempImg.loadFromFile(fName);
            AddTexture(tempImg,tag,animCount);
            cout << fName << " : has loaded with this tag : " << tag << endl;
        }
    }
    void AddTexture(sf::Texture& img,string key,int animCount)
    {
        aList[key] = animCount;
        iList[key] = img;
    }
    sf::Texture& GetTexture(string key)
        {return iList[key];}
    sf::Texture GetTextureVar(string key)
        {return iList[key];}
    int GetAnimCount(string key)
        {return aList[key];}
};
class UpdateEvent
{
private:
    vector<CallBack> uFunc;
public:
    void AddFunction(CallBack func)
        {uFunc.push_back(func);}
    void Update()
    {
        for(unsigned int i = 0; i < uFunc.size(); i++)
            {uFunc[i]();}
    }
};
class GameObject //in progress
{
private:
protected:
    float x,y,rotation;
public:
};
class World //in progress
{
private:
public:
void load(string source);
};
class Animation //in progress
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
    Animation(int animCount,int frame,sf::Texture t)
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
    void c_update()
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
    void draw(sf::RenderWindow &window,float x,float y)
    {
        sprite.setPosition(x,y);
        window.draw(sprite);
    }
    void s_scale(float s)
    {
        //scale = s;
        //chunkSize = (texture.getSize().x / animationCount) * s;
        sprite.setScale(s,s);
    }
};

#endif
