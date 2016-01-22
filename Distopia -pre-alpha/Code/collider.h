#ifndef COLLIDER_H
#define COLLIDER_H

#include <string>

using namespace std;

namespace N_Side
{
    enum Side
    {
        Right,Left,Top,Bottom,Both,None
    };
}

using namespace N_Side;

class Collider
{
public:
  Side vertical;
  Side horizontal;
  float x_depth,y_depth;
  string tag;
  //GameObject* obj;
  Collider();
  Collider(string tag,Side h,Side v);
  Collider(string tag,Side side[]);
};

#endif //COLLIDER_H
