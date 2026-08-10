#ifndef THEMOLLUSK_DELAYED_ROTATION_MODEL_H
#define THEMOLLUSK_DELAYED_ROTATION_MODEL_H

#include "../RotationModelBase.h"

struct DelayedRotationProperty{
    const float w;
};

class DelayedRotationModel :
    public RotationModelBase
{
public:
    DelayedRotationModel(
        float rotation, 
        DelayedRotationProperty property);

    void process(RotationCue cue, const float dt) override;

private:
    const DelayedRotationProperty _property;
};

#endif // !THEMOLLUSK_DELAYED_ROTATION_MODEL_H