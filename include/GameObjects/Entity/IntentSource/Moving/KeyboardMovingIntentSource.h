#ifndef _KEYBOARD_MOVING_INTENT_SOURCE_H_
#define _KEYBOARD_MOVING_INTENT_SOURCE_H_

#include <cmath>
#include <raylib.h>
#include <raymath.h>

#include "IMovingIntentSource.h"

class KeyboardMovingIntentSource :
    public IMovingIntentSource 
{
public:
    struct Layout{
        int north;
        int east;
        int west;
        int south;
    };

    KeyboardMovingIntentSource(){
        Layout default_layout = {
            .north = KEY_W,
            .east  = KEY_D,
            .west  = KEY_A,
            .south = KEY_S
        };

        _layout = default_layout;
    }

    MovingIntent get() override{
        const bool dirs[] = {
            IsKeyDown(_layout.north),
            IsKeyDown(_layout.east ),
            IsKeyDown(_layout.west ),
            IsKeyDown(_layout.south)
        };

        const Vector2 v = {
            .x = static_cast<float>(dirs[1] - dirs[2]),
            .y = static_cast<float>(dirs[3] - dirs[0])
        };

        if(abs(v.x) < EPSILON && abs(v.y) < EPSILON) 
            return {0.f, false};
        
        const float angle = std::atan2(v.y, v.x);

        return {.angle = angle, .is_moving = true};
    }


    void setLayout(Layout layout){
        _layout = layout;
    }

private:
    Layout _layout;
};

#endif // !_KEYBOARD_MOVING_INTENT_SOURCE_H_