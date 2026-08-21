#ifndef THEMOLLUSK_MERE_TARGET_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_MERE_TARGET_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <memory>

class IVec2Source;

struct MereTargetMovingCueProperty {
    std::unique_ptr<IVec2Source> base;
    std::unique_ptr<IVec2Source> target;
};

class MereTargetMovingCueSource:
    public IMovingCueSource
{
public:
    MereTargetMovingCueSource(
        MereTargetMovingCueProperty property);

    ~MereTargetMovingCueSource();

    MovingCue get() const override;

private:
    MereTargetMovingCueProperty _property;
};

#endif // !THEMOLLUSK_MERE_TARGET_MOVING_CUE_SOURCE_H