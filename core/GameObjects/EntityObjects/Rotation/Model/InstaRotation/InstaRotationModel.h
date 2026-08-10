#ifndef THEMOLLUSK_INSTA_ROTATION_MODEL_H
#define THEMOLLUSK_INSTA_ROTATION_MODEL_H

#include "../RotationModelBase.h"

class InstaRotationModel :
    public RotationModelBase
{
public:
    InstaRotationModel();
    void process(RotationCue cue, const float dt) override;
};

#endif // !THEMOLLUSK_INSTA_ROTATION_MODEL_H