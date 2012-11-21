#include "renderer.h"
#include "debug.h"
#include <iostream>
using namespace std;

vector<Renderer*> Renderer::m_renders;
sf::RenderWindow* Renderer::rTarget;
TextureManager* Renderer::rSource;
bool Renderer::canDraw;
Renderer::Renderer()
{
}
Renderer::Renderer(string tName,GameObject* own)
{
    owner = own;
    name = tName;
    activeClip = "default";
    m_renders.push_back(this);
}
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
}
void Renderer::Setup(sf::RenderWindow *target,TextureManager *source)
{
    rTarget = target;
    rSource = source;
    Debug::Info("SETUP REGISTERED NEW SOURCE AND TARGET");
    for(unsigned int i = 0;i < m_renders.size();i++)
    {
        m_renders[i]->loadClips();
        m_renders[i]->SetTexture(rSource->GetTexture(m_renders[i]->GetName()));
    }
    canDraw = true;
}
void Renderer::SetTexture(sf::Texture& t)
{
    a_clip[activeClip].updateTexture(t);
}
void Renderer::Draw()
{
    a_clip[activeClip].draw(rTarget);
}
void Renderer::Update()
{
    a_clip[activeClip].updatePos(owner->position);
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
void Renderer::DebugRender()
{
    if(canDraw)
    {
        for(unsigned int i = 0;i < m_renders.size();i++)
        {
                GameObject* tmpGmo = m_renders[i]->owner;
                std::cout << tmpGmo->position.c_x << std::endl;
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
