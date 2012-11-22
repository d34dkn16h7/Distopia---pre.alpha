#include "renderer.h"
#include "debug.h"
#include <iostream>
using namespace std;

vector<Renderer*> Renderer::m_renders;
sf::RenderWindow *Renderer::rTarget;
TextureManager *Renderer::rSource;
bool Renderer::canDraw;
Renderer::Renderer()
{
}
Renderer::Renderer(string _name,GameObject *_owner)
{
    owner = _owner;
    name = _name;
    anim = new Animation(this);
    m_renders.push_back(this);
}
void Renderer::Setup(sf::RenderWindow *_rTarget,TextureManager *_rSource)
{
    rTarget = _rTarget;
    rSource = _rSource;
    Debug::Info("SETUP REGISTERED NEW SOURCE AND TARGET");
    for(unsigned int i = 0;i < m_renders.size();i++)
    {
        //m_renders[i]->loadClips();
    }
    canDraw = true;
}
void Renderer::Draw()
{
    anim->Draw();
    //a_clip[activeClip].Draw(rTarget);
}
void Renderer::DrawSprite(sf::Sprite &_sprite)
{
    rTarget->draw(_sprite);
}
void Renderer::Update()
{
    anim->Update();
    //a_clip[activeClip].UpdatePos(owner->position);
}
void Renderer::RenderDraw()
{
    if(canDraw)
    {
        for(unsigned int i = 0;i < m_renders.size();i++)
        {
            m_renders[i]->Draw();
        }
    }
}
void Renderer::RenderUpdate()
{
    for(unsigned int i = 0;i < m_renders.size();i++)
    {
        m_renders[i]->Update();
    }
}
/*
void Renderer::loadClips()
{
    string fileName = rSource->GetClipSource(name);
    if(fileName != "null")
    {
        ifstream file(fileName.c_str());
        if(file.is_open())
        {
            string animTag;
            sf::Vector2i b,e;
            sf::Vector2i chunkSize;
            file >> chunkSize.x;
            file >> chunkSize.y;
            while(file >> animTag >> b.y >> b.x >> e.y >> e.x)
            {
                a_clip[animTag] = Clip(chunkSize,b,e);
            }
            Debug::Info("Clip File -" + name + " -" + fileName);
        }
    }
}*/
