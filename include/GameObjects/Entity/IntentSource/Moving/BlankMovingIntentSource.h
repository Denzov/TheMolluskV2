#ifndef _BLANK_MOVING_INTENT_SOURCE_H_
#define _BLANK_MOVING_INTENT_SOURCE_H_

#include "IMovingIntentSource.h"

class BlankMovingIntentSource :
    public IMovingIntentSource 
{
public:
    MovingIntent get() override{
        const MovingIntent blank = {
            .move_north = { false },
            .move_east  = { false },
            .move_west  = { false },
            .move_south = { false }
        };

        return blank;
    }
};

#endif // !_BLANK_MOVING_INTENT_SOURCE_H_