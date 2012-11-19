#ifndef EVENT_H
#define EVENT_H
#include <vector>
using namespace std;
typedef void (*CallBack)(void);

class UpdateEvent
{
private:
    vector<CallBack> uFunc;
public:
    void AddFunction(CallBack func)
    {
        uFunc.push_back(func);
    }
    void Update()
    {
        for(unsigned int i = 0; i < uFunc.size(); i++)
        {
            uFunc[i]();
        }
    }
};

class IEvent
{
    public:
    virtual void Event();
};
#include <iostream>
using namespace std;
class MouseEvent : public IEvent
{
    /*
    Register To Event Mail List
    */
    public:
    static void Event(sf::Vector2i p)
    {
        //cout << "Mouse Event : " << p.x << " : " << p.y << endl;
    }
};
class KeyboardEvent : public IEvent
{
    /*
    Register To Event Mail List
    */
    public:
    static void Event(string n)
    {
        cout << n << endl;
    }
};
#endif
