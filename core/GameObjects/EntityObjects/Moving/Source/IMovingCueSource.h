#ifndef _I_MOVING_CUE_SOURCE_H_
#define _I_MOVING_CUE_SOURCE_H_

#include "../MovingCue.h"

class IMovingCueSource {
public:
    virtual ~IMovingCueSource() = default;

    virtual MovingCue get() = 0;
};

#endif // !_I_MOVING_CUE_SOURCE_H_