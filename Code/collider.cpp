#include "manager.h"
using namespace std;
Collider::Collider()
{
    tag = "null";
    vertical = None;
    horizontal = None;
}
Collider::Collider(string tag,Side h,Side v)
{
    vertical = v;
    horizontal = h;
}
Collider::Collider(string tag,Side side[2])
{
    vertical = side[0];
    horizontal = side[1];
}
