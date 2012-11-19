#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "textureManager.h"
#include "gameObject.h"
#include "m_rect.h"
#include "clip.h"
using namespace std;
class GameObject;
class Renderer
{
private:
    static vector<Renderer*> m_renders;
    static sf::RenderWindow *rTarget;
    static TextureManager *rSource;
    static bool canDraw;
    map<string,Clip> a_clip;
    GameObject *owner;
    string name;
    void loadClips(string fileName);
public:
    Renderer();
    Renderer(string tName);
    void Draw();
    void Update();
    static void Setup(sf::RenderWindow *target,TextureManager *source);
    static void RenderDraw();
    static void RenderUpdate();
    string GetName(){return name;}
};

#endif // RENDERER_H
