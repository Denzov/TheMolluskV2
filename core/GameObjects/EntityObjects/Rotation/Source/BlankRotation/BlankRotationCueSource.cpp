#include "BlankRotationCueSource.h"

RotationCue BlankRotationCueSource::get() const {
    return {0, false};
}