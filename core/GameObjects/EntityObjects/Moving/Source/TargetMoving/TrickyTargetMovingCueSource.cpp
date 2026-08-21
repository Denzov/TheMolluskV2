#include "TrickyTargetMovingCueSource.h"

#include "Moving/Trajectory/ITrajectoryFunction.h"
#include "GameObjects/Vec2Source/IVec2Source.h"

TrickyTargetMovingCueSource::TrickyTargetMovingCueSource(
        TrickyTargetMovingCueProperty property):
            _property(std::move(property))
{
    _property.trajectory.reload(
        _property.start->get(),
        _property.end->get());
}

TrickyTargetMovingCueSource::~TrickyTargetMovingCueSource() = default;

MovingCue TrickyTargetMovingCueSource::get() const {
    if(_property.trajectory.isEnd()) return {0, false};

    _property.trajectory.consume(
        _property.start->get(),
        _property.end->get());
        
    const float direction_angle = _property.trajectory.getDirectionAngle();
    return {direction_angle, true};
}