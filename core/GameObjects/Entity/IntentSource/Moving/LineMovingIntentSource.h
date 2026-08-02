#ifndef _LINE_MOVING_INTENT_SOURCE_H_
#define _LINE_MOVING_INTENT_SOURCE_H_

#include <raylib.h>
#include <raymath.h>

#include <cmath>
#include <memory>

#include "IMovingIntentSource.h"

#include "../Vector2Source/IVector2Source.h"

class LineMovingIntentSource : 
    public IMovingIntentSource
{
public:
    LineMovingIntentSource(
        std::unique_ptr<IVector2Source> cur_pos,
        std::unique_ptr<IVector2Source> aim_pos) : 
            _aim_pos(std::move(aim_pos)), _cur_pos(std::move(cur_pos)){}

    MovingIntent get() override {
        const Vector2 sub = Vector2Subtract(_aim_pos->get(), _cur_pos->get());

        const float sq_len = Vector2LengthSqr(sub);

        if(sq_len < EPSILON) return {0.f, false};

        const float angle = std::atan2(sub.y, sub.x);
        return {angle, true};
    }

private:
    std::unique_ptr<IVector2Source> _cur_pos;
    std::unique_ptr<IVector2Source> _aim_pos;

};

#endif // !_LINE_MOVING_INTENT_SOURCE_H_