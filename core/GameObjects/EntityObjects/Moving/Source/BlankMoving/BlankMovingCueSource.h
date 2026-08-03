#ifndef THEMOLLUSK_BLANK_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_BLANK_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

class BlankMovingCueSource :
    public IMovingCueSource 
{
public:
    MovingCue get() const override;
};

#endif // !THEMOLLUSK_BLANK_MOVING_CUE_SOURCE_H