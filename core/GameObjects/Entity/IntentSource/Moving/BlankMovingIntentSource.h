#ifndef _BLANK_MOVING_INTENT_SOURCE_H_
#define _BLANK_MOVING_INTENT_SOURCE_H_

#include "IMovingIntentSource.h"

class BlankMovingIntentSource :
    public IMovingIntentSource 
{
public:
    MovingIntent get() override{
        const MovingIntent blank = {
            .angle = 0.f,
            .is_moving = false
        };

        return blank;
    }
};

#endif // !_BLANK_MOVING_INTENT_SOURCE_H_