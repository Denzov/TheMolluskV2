#ifndef THEMOLLUSK_ROTATION_MODEL_BASE_H
#define THEMOLLUSK_ROTATION_MODEL_BASE_H

#include "../RotationCue.h"

class RotationModelBase {
public:
    virtual ~RotationModelBase() = default;
    virtual void process(RotationCue cue, const float dt) = 0;

    RotationModelBase(float rotation):
        _rotation(rotation) {}

    float getRotation() const {
        return _rotation;
    }

protected:
    float _rotation;
};

#endif // !THEMOLLUSK_ROTATION_MODEL_BASE_H