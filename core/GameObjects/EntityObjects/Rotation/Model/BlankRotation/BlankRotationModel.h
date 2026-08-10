#ifndef THEMOLLUSK_BLANK_ROTATION_MODEL_H
#define THEMOLLUSK_BLANK_ROTATION_MODEL_H

#include "../RotationModelBase.h"

class BlankRotationModel :
    public RotationModelBase
{
public:
    BlankRotationModel();
    void process(RotationCue cue, const float dt) override;
};

#endif // !THEMOLLUSK_BLANK_ROTATION_MODEL_H