#include "Vector2RotationCueSource.h"

RotationCue Vector2RotationCueSource::get() const {
    if(!_cue) return {{}, false};

    return {_cue->get(), true};
}