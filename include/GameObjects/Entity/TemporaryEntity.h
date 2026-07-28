#ifndef _TEMPORARY_ENTITY_H_
#define _TEMPORARY_ENTITY_H_

#include "EntityBase.h"
#include "Module/TimerModule.h"


class TemporaryEntity : 
    public EntityBase,
    public EntityModule::ITemporary
{
public:
    virtual ~TemporaryEntity() = default;

    float getElapsed() const override{
        return _timer.elapsed;
    }

    float getDuration() const override {
        return _timer.elapsed;
    }

    void elapse(const float time) override{
        _timer.elapsed += time;
    }

    bool isAlive() const override {
        return _timer.elapsed <= _timer.duration;
    }

private:
    EntityModule::Timer _timer;
};

#endif // !_TEMPORARY_ENTITY_H_