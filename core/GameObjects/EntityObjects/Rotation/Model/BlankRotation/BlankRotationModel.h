#ifndef _BLANK_ROTATION_MODEL_H_
#define _BLANK_ROTATION_MODEL_H_

#include "../IRotationModel.h"

class BlankRotationModel :
    public IRotationModel
{
public:
    float process(const RotationCue cue, 
                  const Vector2 base, 
                  const float rot, const float dt) override;
};

#endif // !_BLANK_ROTATION_MODEL_H_