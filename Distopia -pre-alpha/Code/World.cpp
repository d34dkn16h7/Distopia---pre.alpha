#include "world.h"

World::World(string source)
{
    if(source != "null")
        Load(source);
}
void World::Load(string source)
{
    ifstream file(source.c_str());
    string tag;
    float x,y,r;
    while(file >> tag >> x >> y >> r)
    {
        AddObject(new GameObject(tag,x,y,r));
    }
}
void World::AddObject(GameObject* gmo)
{
    objects.push_back(gmo);
}
void World::Draw(sf::RenderWindow &r,TextureManager &tManager) // need fix - delete this
{
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        sf::Sprite sprite;
        tmpObject = objects[i];
        sprite.setTexture(tManager.GetTexture(tmpObject->name));
        sprite.setPosition(tmpObject->position.left,tmpObject->position.top);
        sprite.setRotation(tmpObject->rotation);
        r.draw(sprite);
    }
}
vector<Collider> World::collision(M_Rect player)
{
    vector<Collider> vect;
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        tmpObject = objects[i];
        Collider col = M_Rect::Intersection(player,tmpObject->position);
        if(col.vertical != None || col.horizontal != None)
        {
            col.tag = tmpObject->name;
            vect.push_back(col);
        }
    }
    return vect;
}
