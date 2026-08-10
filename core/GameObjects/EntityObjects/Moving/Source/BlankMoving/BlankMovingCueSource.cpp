#include "BlankMovingCueSource.h"

MovingCue BlankMovingCueSource::get() const {
    return MovingCue {
        .direction_angle = 0.f,
        .is_moving = false
    };
}