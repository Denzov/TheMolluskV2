#ifndef _KEYBOARD_MOVING_CUE_SOURCE_H_
#define _KEYBOARD_MOVING_CUE_SOURCE_H_

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

#endif // !_KEYBOARD_MOVING_CUE_SOURCE_H_