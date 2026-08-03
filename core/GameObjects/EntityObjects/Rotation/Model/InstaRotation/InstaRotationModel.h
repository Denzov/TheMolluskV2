#ifndef _INSTA_ROTATION_MODEL_H_
#define _INSTA_ROTATION_MODEL_H_

#include "../IRotationModel.h"

class InstaRotationModel :
    public IRotationModel
{
public:
    float process(const RotationCue cue, 
                  const Vector2 base, 
                  const float rot, const float dt) override;
};

#endif // !_INSTA_ROTATION_MODEL_H_