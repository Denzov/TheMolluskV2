#ifndef _BLANK_MOVING_CUE_SOURCE_H_
#define _BLANK_MOVING_CUE_SOURCE_H_

#include "IMovingCueSource.h"

class BlankMovingCueSource :
    public IMovingCueSource 
{
public:
    MovingCue get() override{
        const MovingCue blank = {
            .angle = 0.f,
            .is_moving = false
        };

        return blank;
    }
};

#endif // !_BLANK_MOVING_CUE_SOURCE_H_