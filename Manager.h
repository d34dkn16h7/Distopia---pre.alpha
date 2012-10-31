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
    TextureManager(string source = "null")
    {
        if(source != "null")
            load(source);
    }
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
    {
        return iList[key];
    }
    sf::Texture GetTextureVar(string key)
    {
        return iList[key];
    }
    int GetAnimCount(string key)
    {
        return aList[key];
    }
};
class UpdateEvent
{
private:
    vector<CallBack> uFunc;
public:
    void AddFunction(CallBack func)
    {
        uFunc.push_back(func);
    }
    void Update()
    {
        for(unsigned int i = 0; i < uFunc.size(); i++)
        {
            uFunc[i]();
        }
    }
};
class GameObject //in progress
{
private:
protected:
public:
    float x,y,rotation;
    string name;
    GameObject(string n = "null",float pos_x = 0,float pos_y = 0,float rot_r = 0)
    {
        name = n;
        x = pos_x;
        y = pos_y;
        rotation = rot_r;
    }
};
class World //in progress
{
private:
    vector<GameObject> objects;
public:
    World(string source = "null")
    {
        if(source != "null")
            load(source);
    }
    void load(string source)
    {
        ifstream file(source.c_str());
        string tag;
        float x,y,r;
        while(file >> tag >> x >> y >> r)
        {
            AddObject(GameObject(tag,x,y,r));
            cout << tag << x << y << r << endl;
        }
    }
    void AddObject(GameObject gmo)
    {
        objects.push_back(gmo);
    }
    void draw(sf::RenderWindow &r,TextureManager &tManager)
    {
        sf::Sprite sprite;
        for(int i = 0;i < objects.size();i++)
        {
            GameObject gmo = objects[i];
            sprite.setTexture(tManager.GetTexture(gmo.name));
            sprite.setPosition(gmo.x,gmo.y);
            sprite.setRotation(gmo.rotation);
            r.draw(sprite);
        }
    }
};
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
        scale = s;
        sprite.setScale(s,s);
    }
};

#endif
