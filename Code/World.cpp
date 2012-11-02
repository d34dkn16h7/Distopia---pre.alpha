#include "Manager.h"

World::World(string source = "null")
{
    if(source != "null")
        load(source);
}
void World::load(string source)
{
    ifstream file(source.c_str());
    string tag;
    float x,y,r;
    while(file >> tag >> x >> y >> r)
    {
        AddObject(GameObject(tag,x,y,r,32,32));
        cout << tag << x << y << r << endl;
    }
}
void World::AddObject(GameObject gmo)
{
    objects.push_back(gmo);
}
void World::draw(sf::RenderWindow &r,TextureManager &tManager)
{
    sf::Sprite sprite;
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        tmpObject = objects[i];
        sprite.setTexture(tManager.GetTexture(tmpObject.name));
        sprite.setPosition(tmpObject.position.left,tmpObject.position.top);
        sprite.setRotation(tmpObject.rotation);
        r.draw(sprite);
    }
}
bool World::collision(m_rect player)
{
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        tmpObject = objects[i];
        if(m_rect::intersection(player,tmpObject.position))
        {
            //cout << "true" << endl;
            return true;
        }
    }
    //cout << "false" << endl;
    return false;
}
