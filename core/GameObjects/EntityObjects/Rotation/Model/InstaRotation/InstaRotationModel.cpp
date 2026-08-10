#include "InstaRotationModel.h"

InstaRotationModel::InstaRotationModel():
    RotationModelBase(0) {}

void InstaRotationModel::process(RotationCue cue, const float dt) {
    if(cue.is_rotation)
        _rotation = cue.direction_angle;
}