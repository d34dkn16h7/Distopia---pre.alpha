#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "renderer.h"
#include "clip.h"
using namespace std;
class Renderer;
class Animation
{
private:
    Renderer* owner;
    sf::Sprite anim;
    map<string,Clip> clip;
    string currentClip;
public:
    Animation(Renderer* _owner);
    void AddClip(string _name,Clip _clip);
    void Draw();
    void Update();
    void Play(string _animName);
    void Setup();
    void Load(string _fileName);
};
#endif // ANIMATION_H
