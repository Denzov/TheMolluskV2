#ifndef _BLANK_ROTATION_STRATEGY_
#define _BLANK_ROTATION_STRATEGY_

#include "IRotationModel.h"

class BlankRotationModel :
    public IRotationModel
{
public:
    float process(const RotationCue intent, 
                  const Vector2 base, 
                  const float rot, const float dt) override 
    {
        return 0;
    }

};

#endif // !_BLANK_ROTATION_STRATEGY_