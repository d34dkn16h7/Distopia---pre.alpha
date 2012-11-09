#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
using namespace std;
class Message
{
    static void print()
    {
    }
};
class Warning : public Message
{
};
#endif
