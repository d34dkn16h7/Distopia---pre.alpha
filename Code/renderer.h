#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
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
    string name,activeClip;
    void loadClips();
public:
    Renderer();
    Renderer(string tName,GameObject* own);
    void Draw();
    void Update();
    static void Setup(sf::RenderWindow *target,TextureManager *source);
    static void RenderDraw();
    static void RenderUpdate();
    static void DebugRender();
    void Play(string clipName){activeClip = clipName;}
    void SetTexture(sf::Texture& t);
    string GetName(){return name;}
    string GetActiveClip(){return activeClip;}
};

#endif // RENDERER_H
