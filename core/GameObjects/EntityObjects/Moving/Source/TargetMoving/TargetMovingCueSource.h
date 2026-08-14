#ifndef THEMOLLUSK_TARGET_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_TARGET_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <memory>

class IVec2Source;
class ITrajectory;

class TargetMovingCueSource : 
    public IMovingCueSource
{
public:
    TargetMovingCueSource(
        std::unique_ptr<ITrajectory> trajectory);

    ~TargetMovingCueSource();

    MovingCue get() const override;

private:
    std::unique_ptr<ITrajectory> _trajectory;
};

#endif // !THEMOLLUSK_TARGET_MOVING_CUE_SOURCE_H