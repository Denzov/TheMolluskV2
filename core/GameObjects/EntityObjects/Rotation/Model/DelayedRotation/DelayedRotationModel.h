#ifndef THEMOLLUSK_DELAYED_ROTATION_MODEL_H
#define THEMOLLUSK_DELAYED_ROTATION_MODEL_H

#include "../IRotationModel.h"

struct DelayedRotationProperty{
    const float w;
};

class DelayedRotationModel :
    public IRotationModel
{
public:
    DelayedRotationModel(DelayedRotationProperty propery) : 
        _property(propery){}

    float process(const RotationCue cue, 
                  const Vector2 base, 
                  const float rot, const float dt) override;

private:
    const DelayedRotationProperty _property;
};

#endif // !THEMOLLUSK_DELAYED_ROTATION_MODEL_H