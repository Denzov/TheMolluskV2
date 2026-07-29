#ifndef _KEYBOARD_MOVING_INTENT_SOURCE_H_
#define _KEYBOARD_MOVING_INTENT_SOURCE_H_

#include <raylib.h>
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
        const MovingIntent intent {
            .move_north = { IsKeyDown(_layout.north) },
            .move_east  = { IsKeyDown(_layout.east ) },
            .move_west  = { IsKeyDown(_layout.west ) },
            .move_south = { IsKeyDown(_layout.south) }
        };

        // std::cout << intent.move_east.status ;

        return intent;
    }


    void setLayout(Layout layout){
        _layout = layout;
    }

private:
    Layout _layout;
};

#endif // !_KEYBOARD_MOVING_INTENT_SOURCE_H_