#include "renderer.h"
using namespace std;

vector<Renderer*> Renderer::m_renders;
sf::RenderWindow* Renderer::rTarget;
TextureManager* Renderer::rSource;
bool Renderer::canDraw;
Renderer::Renderer()
{
    //m_renders.push_back(this);
    std::cout << "DEBUG : EMPTY RENDERER" << std::endl;
}
Renderer::Renderer(string tName)
{
    name = tName;
    m_renders.push_back(this);
    //std::cout << "DEBUG : NEW RENDERER FOR: " << name << std::endl;
}
void Renderer::loadClips(string fileName)
{
    if(fileName != "null")
    {
        ifstream file(fileName.c_str());
        string animTag;
        sf::Vector2i b,e;
        while(file >> animTag >> b.y >> b.x >> e.y >> e.x)
        {

        }
    }
}
void Renderer::Setup(sf::RenderWindow *target,TextureManager *source)
{
    rTarget = target;
    rSource = source;
    std::cout << "DEBUG : SETUP REGISTERED NEW SOURCE AND TARGET" << std::endl;
    for(int i = 0;i < m_renders.size();i++)
    {
        //std::cout << "DEBUG : GET NAME OF < " << i << " > RENDERER : " << m_renders[i]->GetName() <<  std::endl;
        m_renders[i]->loadClips(m_renders[i]->GetName());
    }
    canDraw = true;
}
void Renderer::Draw()
{
    std::cout << "INFO : RENDER DRAW CALLED" << std::endl;
}
void Renderer::Update()
{
    std::cout << "INFO : RENDER UPDATE CALLED" << std::endl;
}
void Renderer::RenderDraw()
{
    if(canDraw)
    {
        for(int i = 0;i < m_renders.size();i++)
        {
            m_renders[i]->Draw();
        }
    }
}
void Renderer::RenderUpdate()
{
    for(int i = 0;i < m_renders.size();i++)
    {
        m_renders[i]->Update();
    }
}
