#ifndef TEMP_H
#define TEMP_H
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include "player.h"
using namespace std;

class Force
{
private:
    map<int,float> tForce;
    map<int,float> sForce;
    map<string,float> EventType;
public:
    static float Push(float mTarget,float speed = 1,float time = 0)
    {
        return mTarget - speed;
    }
    void AddEvent(int key,string type,float target,float speed)
    {
        //tForce.insert(map<int,float>::value_type(key,target));
        tForce[key] = target;
        //sForce.insert(map<int,float>::value_type(key,speed));
        sForce[key] = speed;
    }
    float GetEvent(int key)
    {
        return tForce[key];
    }
    void DeleteEvent(int key)
    {
        tForce.erase(key);
    }
    float GetUpdate(int key)
    {
        //int *tmp = (int *)key;
        //float val = *(int *)tmp;
        //cout << val << endl;
        //val -= tForce[key];
        return tForce[key] - sForce[key];
    }
};

#endif
