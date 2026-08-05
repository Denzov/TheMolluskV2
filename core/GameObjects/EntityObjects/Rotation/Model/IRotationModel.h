#ifndef THEMOLLUSK_I_ROTATION_MODEL_H
#define THEMOLLUSK_I_ROTATION_MODEL_H

#include "../RotationCue.h"

class IRotationModel {
public:
    virtual ~IRotationModel() = default;

    virtual float process(RotationCue, Math::Vec2 base, const float rot, const float dt) = 0;
};

#endif // !THEMOLLUSK_I_ROTATION_MODEL_H