#ifndef _TEMPORARY_ENTITY_H_
#define _TEMPORARY_ENTITY_H_

#include "GameObjects/EntityObjects/Base/EntityBase.h"
#include "GameObjects/EntityObjects/Module/TimerModule.h"

class TemporaryEntity : 
    public EntityBase,
    public EntityModule::ITemporary
{
public:
    virtual ~TemporaryEntity() = default;

    float getElapsed() const override;
    float getDuration() const override;

    void elapse(const float time) override;

    void setDuration(const float time) override;
    void addDuration(const float time) override;
    
    bool isAlive() const override;

private:
    EntityModule::Timer _timer;
};

#endif // !_TEMPORARY_ENTITY_H_