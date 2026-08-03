#ifndef THEMOLLUSK_KEYBOARD_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_KEYBOARD_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

class KeyboardMovingCueSource :
    public IMovingCueSource 
{
public:
    struct Layout{
        int north;
        int east;
        int west;
        int south;
    };

    KeyboardMovingCueSource();
    
    MovingCue get() const override;

    void setLayout(Layout layout);

private:
    Layout _layout;
};

#endif // !THEMOLLUSK_KEYBOARD_MOVING_CUE_SOURCE_H