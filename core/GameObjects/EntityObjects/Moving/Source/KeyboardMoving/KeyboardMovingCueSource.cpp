#include "KeyboardMovingCueSource.h"

#include "Math/Vec2.h"
#include "Math/Constants.h"

#include <raylib.h>
#include <cmath>

KeyboardMovingCueSource::KeyboardMovingCueSource():
    _layout{
        .north = KEY_W,
        .east  = KEY_D,
        .west  = KEY_A,
        .south = KEY_S
    } {}

KeyboardMovingCueSource::KeyboardMovingCueSource(Layout layout):
    _layout(layout) {}

MovingCue KeyboardMovingCueSource::get() const {
    const bool dirs[] = {
        IsKeyDown(_layout.north),
        IsKeyDown(_layout.east ),
        IsKeyDown(_layout.west ),
        IsKeyDown(_layout.south)
    };

    const Math::Vec2 v = {
        .x = static_cast<float>(dirs[1] - dirs[2]),
        .y = static_cast<float>(dirs[3] - dirs[0])
    };

    if(std::abs(v.x) < Math::EPSILON && std::abs(v.y) < Math::EPSILON) 
        return {0.f, false};
    
    const float angle = std::atan2(v.y, v.x);

    return {.direction_angle = angle, .is_moving = true};
}
