#ifndef THEMOLLUSK_MOVING_MODEL_BASE_H
#define THEMOLLUSK_MOVING_MODEL_BASE_H

#include "Math/Vec2.h"
#include "../MovingCue.h"

class MovingModelBase{
public:
    virtual ~MovingModelBase() = default;
    virtual void process(MovingCue cue, const float dt) = 0;

    MovingModelBase(Math::Vec2 position) :
        _position(position){}    

    Math::Vec2 getPosition() const { 
        return _position; 
    }

protected:
    Math::Vec2 _position;
};

#endif // !THEMOLLUSK_MOVING_MODEL_BASE_H