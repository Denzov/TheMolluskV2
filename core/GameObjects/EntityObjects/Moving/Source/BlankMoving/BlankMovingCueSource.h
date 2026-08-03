#ifndef _BLANK_MOVING_CUE_SOURCE_H_
#define _BLANK_MOVING_CUE_SOURCE_H_

#include "../IMovingCueSource.h"

class BlankMovingCueSource :
    public IMovingCueSource 
{
public:
    MovingCue get() const override;
};

#endif // !_BLANK_MOVING_CUE_SOURCE_H_