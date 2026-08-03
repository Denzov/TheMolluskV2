#ifndef _DELAYED_ROTATION_MODEL_H_
#define _DELAYED_ROTATION_MODEL_H_

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

#endif // !_DELAYED_ROTATION_MODEL_H_