#ifndef _I_ROTATION_CUE_SOURCE_
#define _I_ROTATION_CUE_SOURCE_

#include <raylib.h>

#include "../RotationCue.h"

class IRotationCueSource{
public:
    virtual ~IRotationCueSource() = default;

    virtual RotationCue get() const = 0;
};

#endif // !_I_ROTATION_CUE_SOURCE_