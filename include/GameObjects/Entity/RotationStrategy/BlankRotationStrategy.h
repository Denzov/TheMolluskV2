#ifndef _BLANK_ROTATION_STRATEGY_
#define _BLANK_ROTATION_STRATEGY_

#include "IRotationStrategy.h"

class BlankRotationStrategy :
    public IRotationStrategy
{
public:
    float process(const AimIntent intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        return 0;
    }

};

#endif // !_BLANK_ROTATION_STRATEGY_