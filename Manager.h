#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
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
    void AddTexture(sf::Texture& img,string key,int animCount)
    {
        aList[key] = animCount;
        iList[key] = img;
    }
    sf::Texture& GetTexture(string key)
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
    void RemoveFunction(CallBack func)
    {
        //CallBack tmp = uFunc.back();
    }
    void Update()
    {
        for(unsigned int i = 0; i < uFunc.size(); i++)
        {
            uFunc[i]();
        }
    }
};

#endif
