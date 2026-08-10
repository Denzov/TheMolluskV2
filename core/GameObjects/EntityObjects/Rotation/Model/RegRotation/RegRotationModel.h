#ifndef THEMOLLUSK_REG_ROTATION_MODEL_H
#define THEMOLLUSK_REG_ROTATION_MODEL_H

#include "../RotationModelBase.h"

struct RegRotationProperty {
    const float kp_rot;
    
    const float kp_speed;
    const float ki_speed;

    const float max_w;
};

class RegRotationModel :
    public RotationModelBase
{
public:
    RegRotationModel(
        float rotation, RegRotationProperty property);

    void process(RotationCue cue, const float dt) override;

private:
    RegRotationProperty _property;

    float _speed_integrator = 0;
    float _w = 0;
};

#endif // !THEMOLLUSK_REG_ROTATION_MODEL_H