#include "TargetMovingCueSource.h"

#include "../../Trajectory/Base/TrajectoryBase.h"

TargetMovingCueSource::TargetMovingCueSource(
        std::unique_ptr<TrajectoryBase> trajectory) : 
            _trajectory(std::move(trajectory)){}

TargetMovingCueSource::~TargetMovingCueSource() = default;

MovingCue TargetMovingCueSource::get() const {
    if(_trajectory->isEnd()) return {0, false};

    _trajectory->consume();
    const float direction_angle = _trajectory->getDirectionAngle();
    return {direction_angle, true};
}