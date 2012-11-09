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
namespace N_Side
{
    enum Side
    {
        Right,Left,Top,Bottom,Both,None
    };
}
using namespace N_Side;
class Collider
{
public:
  Side vertical;
  Side horizontal;
  float x_depth,y_depth;
  string tag;
  //GameObject* obj;
  Collider();
  Collider(string tag,Side h,Side v);
  Collider(string tag,Side side[]);
};
class m_rect
{
private:
public:
    float c_x,c_y,w,h;
    float left,top,right,bottom;
    m_rect();
    m_rect(float center_x,float center_y,float weight,float height);
    void calc();
    static Collider intersection(m_rect first,m_rect second);
    static bool contain(m_rect rc,float x,float y);
};
class GameObject
{
private:
protected:
public:
    m_rect position;
    float rotation;
    string name;
    GameObject();
    GameObject(string n,float pos_x,float pos_y,float rot_r,float w,float h);
};
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
class World
{
private:
    GameObject tmpObject;
    vector<GameObject> objects;
public:
    World(string source);
    void load(string source);
    void AddObject(GameObject gmo);
    void draw(sf::RenderWindow &r,TextureManager &tManager);
    vector<Collider> collision(m_rect player);
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
class Body
{
private:
public:
};
#endif
