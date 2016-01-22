#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>

#include "textureManager.h"
#include "gameObject.h"
#include "animation.h"
#include "M_rect.h"

using namespace std;

class GameObject;
class Animation;
class Renderer
{
private:
    static vector<Renderer*> m_renders;
    static sf::RenderWindow *rTarget;
    static TextureManager *rSource;
    static bool canDraw;
    GameObject *owner;
    Animation *anim;
    string name;
public:
    Renderer();
    Renderer(string _name,GameObject *_owner);
    void Draw();
    void DrawSprite(sf::Sprite &_sprite);
    void Update();
    static void Setup(sf::RenderWindow *_rTarget,TextureManager *_rSource);
    static void RenderDraw();
    static void RenderUpdate();
    string GetName(){return name;}
};

#endif // RENDERER_H
