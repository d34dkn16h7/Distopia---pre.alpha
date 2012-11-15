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
class Info
{
    public:
    Info()
    {
    }
    virtual void info()
    {
        cout << "DEFAULT INFO" << endl;
    }
};
#endif
