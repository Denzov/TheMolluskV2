#ifndef THEMOLLUSK_DIRECT_MOVING_MODEL_H
#define THEMOLLUSK_DIRECT_MOVING_MODEL_H

#include "../MovingModelBase.h"

struct DirectMovingPropery{
    const float velocity;
};

class DirectMovingModel :
    public MovingModelBase
{
public:
    DirectMovingModel(
        Math::Vec2 position, DirectMovingPropery property);

    void process(MovingCue cue, const float dt) override;

private:
    DirectMovingPropery _property;
};

#endif // !THEMOLLUSK_DIRECT_MOVING_MODEL_H