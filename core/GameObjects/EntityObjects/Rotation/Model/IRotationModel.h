#ifndef _I_ROTATION_STRATEGY_H_
#define _I_ROTATION_STRATEGY_H_

#include "../RotationCue.h"

class IRotationModel {
public:
    virtual ~IRotationModel() = default;

    virtual float process(RotationCue, Vector2 base, const float rot, const float dt) = 0;
};

#endif // !_I_ROTATION_STRATEGY_H_