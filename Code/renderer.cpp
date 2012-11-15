#include "renderer.h"
using namespace std;

vector<Renderer*> Renderer::m_renders;
Renderer::Renderer()
{
    m_renders.push_back(this);
    std::cout << "New Renderer Source" << std::endl;
}
Renderer::Renderer(string tag)
{
    m_renders.push_back(this);
    std::cout << "New Renderer For : " << tag << std::endl;
}
