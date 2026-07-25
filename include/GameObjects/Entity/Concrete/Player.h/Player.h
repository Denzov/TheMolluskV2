#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Module/HealthModule.h"

class Player :
    public Health, public IDamageable
{

};

#endif // !_PLAYER_H_