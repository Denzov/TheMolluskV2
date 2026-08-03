#ifndef _BLANK_ROTATION_CUE_SOURCE_H_
#define _BLANK_ROTATION_CUE_SOURCE_H_

#include "../IRotationCueSource.h"

class BlankRotationCueSource :
    public IRotationCueSource
{
public:
    RotationCue get() const override;
};

#endif // !_BLANK_ROTATION_CUE_SOURCE_H_