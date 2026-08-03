#include "BlankMovingCueSource.h"

MovingCue BlankMovingCueSource::get() const {
    return MovingCue {
        .angle = 0.f,
        .is_moving = false
    };
}