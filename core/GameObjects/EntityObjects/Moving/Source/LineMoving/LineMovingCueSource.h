#ifndef THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H
#define THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H

#include "../IMovingCueSource.h"

#include <memory>

class IVec2Source;

class LineMovingCueSource : 
    public IMovingCueSource
{
public:
    LineMovingCueSource(
        std::unique_ptr<IVec2Source> cur_pos,
        std::unique_ptr<IVec2Source> aim_pos);

    ~LineMovingCueSource();

    MovingCue get() const override;

private:
    std::unique_ptr<IVec2Source> _cur_pos;
    std::unique_ptr<IVec2Source> _aim_pos;
};

#endif // !THEMOLLUSK_LINE_MOVING_CUE_SOURCE_H