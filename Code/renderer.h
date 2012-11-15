#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Renderer
{
    static vector<Renderer*> m_renders;
    public:
    Renderer();
    Renderer(string tag);
};

#endif // RENDERER_H
