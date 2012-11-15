#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics.hpp>
#include <string>
#include "textureManager.h"
#include "gameObject.h"
#include "m_rect.h"
using namespace std;
class GameObject;
class Collider;
class m_rect;
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
#endif

