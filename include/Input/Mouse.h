#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <raylib.h>

class Mouse{
public:
    Vector2 position(){
        return GetMousePosition();
    }

    Vector2 delta(){
        return GetMouseDelta();
    }

    float wheel(){
        return GetMouseWheelMove();
    }
};

#endif // !_MOUSE_H_