#ifndef THEMOLLUSK_TRICKY_TARGET_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_TRICKY_TARGET_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include "Moving/Trajectory/Trajectory.h"

struct TrickyTargetMovingCueProperty {
    std::unique_ptr<IVec2Source> start;
    std::unique_ptr<IVec2Source> end;
    Trajectory trajectory;
};

class TrickyTargetMovingCueSource:
    public IMovingCueSource
{
public:
    TrickyTargetMovingCueSource(
        TrickyTargetMovingCueProperty property);

    ~TrickyTargetMovingCueSource();

    MovingCue get() const override;

private:
    mutable TrickyTargetMovingCueProperty _property;
};

#endif // !THEMOLLUSK_TRICKY_TARGET_MOVING_CUE_SOURCE_H