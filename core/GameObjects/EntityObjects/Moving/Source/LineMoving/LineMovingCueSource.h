#ifndef THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"
#include "GameObjects/Vector2Source/IVector2Source.h"

#include <memory>

class LineMovingCueSource : 
    public IMovingCueSource
{
public:
    LineMovingCueSource(
        std::unique_ptr<IVector2Source> cur_pos,
        std::unique_ptr<IVector2Source> aim_pos) : 
            _aim_pos(std::move(aim_pos)), _cur_pos(std::move(cur_pos)){}

    MovingCue get() const override;

private:
    std::unique_ptr<IVector2Source> _cur_pos;
    std::unique_ptr<IVector2Source> _aim_pos;

};

#endif // !THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H