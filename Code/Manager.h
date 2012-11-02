#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <SFML\Graphics.hpp>
using namespace std;
typedef void (*CallBack)(void);
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
class m_rect
{
private:
public:
    float c_x,c_y,w,h;
    float left,top,right,bottom;
    m_rect(float center_x = 0,float center_y = 0,float weight = 0,float height = 0)
    {
        c_x = center_x;
        c_y = center_y;
        w = weight;
        h = height;
        calc();
    }
    void calc()
    {
        left = c_x - (w/2);
        right = c_x + (w/2);
        top = c_y - (h/2);
        bottom = c_y + (h/2);
    }
    static bool intersection(m_rect first,m_rect second)
    {
        if(first.left < second.right && first.right > second.left)
        {
            if(first.top < second.bottom && first.bottom > second.top)//
            {
                return true;
            }
        }
        return false;
    }
    static bool contain(m_rect rc,float x,float y)
    {
        if(rc.left < x && rc.right > x)
        {
            if(rc.bottom < y && rc.top > y)
                return true;
        }
        return false;
    }
};
class GameObject //in progress
{
private:
protected:
public:
    m_rect position;
    float rotation;
    string name;
    GameObject(string n = "null",float pos_x = 0,float pos_y = 0,float rot_r = 0,float w = 32,float h = 32)
    {
        cout<<w << ":" << h<<endl;
        position.c_x = pos_x;
        position.c_y = pos_y;
        position.h = w;
        position.w = h;
        position.calc();
        name = n;
        rotation = rot_r;
    }
};
class World //in progress
{
private:
    GameObject tmpObject;
    vector<GameObject> objects;
public:
    World(string source);
    void load(string source);
    void AddObject(GameObject gmo);
    void draw(sf::RenderWindow &r,TextureManager &tManager);
    bool collision(m_rect player);
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
    Animation(int animCount,int frame,sf::Texture t);
    void c_update();
    void draw(sf::RenderWindow &window,m_rect pos);
    void s_scale(float s);
};
#endif
