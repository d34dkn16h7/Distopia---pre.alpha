#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include <string>
#include "textureManager.h"
#include "gameObject.h"
#include "M_rect.h"
using namespace std;
class GameObject;
class Collider;
class M_Rect;
class World
{
private:
    GameObject* tmpObject;
    vector<GameObject*> objects;
public:
    World(string source);
    void Load(string source);
    void AddObject(GameObject* gmo);
    void Draw(sf::RenderWindow &r,TextureManager &tManager);
    vector<Collider> collision(M_Rect player);
};
#endif

