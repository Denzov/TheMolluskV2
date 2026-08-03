#include "BlankRotationCueSource.h"

RotationCue BlankRotationCueSource::get() const {
    return {{}, true};
}