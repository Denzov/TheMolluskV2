#ifndef THEMOLLUSK_I_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_I_MOVING_CUE_SOURCE_H

#include "../MovingCue.h"

class IMovingCueSource {
public:
    virtual ~IMovingCueSource() = default;

    virtual MovingCue get() const = 0;
};

#endif // !THEMOLLUSK_I_MOVING_CUE_SOURCE_H