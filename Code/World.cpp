#include "world.h"

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
        AddObject(GameObject(tag,x,y,r));
        cout << tag <<" : "<< x <<" : "<< y << " : "<< r << endl;
    }
}
void World::AddObject(GameObject gmo)
{
    objects.push_back(gmo);
}
void World::draw(sf::RenderWindow &r,TextureManager &tManager) // need fix
{
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        sf::Sprite sprite;
        tmpObject = objects[i];
        sprite.setTexture(tManager.GetTexture(tmpObject.name));
        sprite.setPosition(tmpObject.position.left,tmpObject.position.top);
        sprite.setRotation(tmpObject.rotation);
        r.draw(sprite);
    }
}
vector<Collider> World::collision(m_rect player)
{
    vector<Collider> vect;
    for(unsigned int i = 0; i < objects.size(); i++)
    {
        tmpObject = objects[i];
        Collider col = m_rect::intersection(player,tmpObject.position);
        if(col.vertical != None || col.horizontal != None)
        {
            col.tag = tmpObject.name;
            vect.push_back(col);
        }
    }
    return vect;
}
