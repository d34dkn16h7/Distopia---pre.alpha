#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

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
class m_rect //- done NImp
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
    GameObject(string n = "null",float pos_x = 0,float pos_y = 0,float rot_r = 0)
    {
        position.c_x = pos_x;
        position.c_y = pos_y;
        position.h = 32;
        position.w = 32;
        position.calc();
        name = n;
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
        GameObject gmo;
        for(unsigned int i = 0;i < objects.size();i++)
        {
            gmo = objects[i];
            sprite.setTexture(tManager.GetTexture(gmo.name));
            sprite.setPosition(gmo.position.left,gmo.position.top);
            sprite.setRotation(gmo.rotation);
            r.draw(sprite);
        }
    }
    bool collision(m_rect player)
    {
        GameObject gmo;
        for(unsigned int i = 0;i < objects.size();i++)
        {
            gmo = objects[i];
            if(m_rect::intersection(player,gmo.position))
            {
                //cout << "true" << endl;
                return true;
            }
        }
        //cout << "false" << endl;
        return false;
    }
};
class Animation //- done NImp
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
    void draw(sf::RenderWindow &window,m_rect pos)
    {
        sprite.setPosition(pos.left,pos.top);
        window.draw(sprite);
    }
    void s_scale(float s)
    {
        scale = s;
        sprite.setScale(s,s);
    }
};

#endif
