#ifndef THEMOLLUSK_INSTA_ROTATION_MODEL_H
#define THEMOLLUSK_INSTA_ROTATION_MODEL_H

#include "../IRotationModel.h"

class InstaRotationModel :
    public IRotationModel
{
public:
    float process(const RotationCue cue, 
                  const Vector2 base, 
                  const float rot, const float dt) override;
};

#endif // !THEMOLLUSK_INSTA_ROTATION_MODEL_H