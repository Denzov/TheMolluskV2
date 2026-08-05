#include "InstaRotationModel.h"

#include "Math/Constants.h"
#include <cmath>

float process(const RotationCue cue, 
              const Math::Vec2 base, 
              const float rot, const float dt)
{
    if(!cue.is_rotation) return 0;
    
    const Math::Vec2 abs_target = {
        .x = cue.target.x - base.x,
        .y = cue.target.y - base.y
    };

    const float target_rot = std::atan2(abs_target.y, abs_target.x);
    const float err = std::remainder(target_rot - rot, 2.0f * Math::PI);

    return err;
}