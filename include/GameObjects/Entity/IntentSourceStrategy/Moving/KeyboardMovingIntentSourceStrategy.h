#ifndef _KEYBOARD_MOVING_INTENT_SOURCE_STRATEGY_H_
#define _KEYBOARD_MOVING_INTENT_SOURCE_STRATEGY_H_

#include <raylib.h>
#include "IMovingIntentSourceStrategy.h"

class KeyboardMovingIntentSourceStrategy :
    public IMovingIntentSourceStrategy 
{
public:
    struct Layout{
        int north;
        int east;
        int west;
        int south;
    };

    KeyboardMovingIntentSourceStrategy(){
        Layout default_layout = {
            .north = KEY_W,
            .east  = KEY_D,
            .west  = KEY_A,
            .south = KEY_S
        };

        _layout = default_layout;
    }

    MovingIntent process() override{
        const MovingIntent intent {
            .move_north = { IsKeyPressed(_layout.north) },
            .move_east  = { IsKeyPressed(_layout.east ) },
            .move_west  = { IsKeyPressed(_layout.west ) },
            .move_south = { IsKeyPressed(_layout.south) }
        };

        return intent;
    }


    void setLayout(Layout layout){
        _layout = layout;
    }


private:
    Layout _layout;
};

#endif // !_KEYBOARD_MOVING_INTENT_SOURCE_STRATEGY_H_