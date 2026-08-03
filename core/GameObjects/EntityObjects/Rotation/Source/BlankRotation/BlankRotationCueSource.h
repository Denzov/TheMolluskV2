#ifndef THEMOLLUSK_BLANK_ROTATION_CUE_SOURCE_H
#define THEMOLLUSK_BLANK_ROTATION_CUE_SOURCE_H

#include "../IRotationCueSource.h"

class BlankRotationCueSource :
    public IRotationCueSource
{
public:
    RotationCue get() const override;
};

#endif // !THEMOLLUSK_BLANK_ROTATION_CUE_SOURCE_H