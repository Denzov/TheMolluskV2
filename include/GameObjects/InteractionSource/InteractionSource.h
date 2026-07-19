#ifndef _I_INTERACTION_SOURCE_
#define _I_INTERACTION_SOURCE_

#include "../Entity/EntityBase.h"

namespace InteractionSource
{
    struct collision{ 
        EntityBasePtr entity1, entity2;
    };

    struct timer{
        EntityBasePtr entity;
        float cur_time;
    };

    struct internal{};    
};

struct InteractionSourceValidator
{
    bool operator()(InteractionSource::collision &t){

    }

    bool operator()(InteractionSource::timer &t){
        // if(t.cur_time >= t.finish_time){
        //     return true;
        // }
    }

    bool operator()(InteractionSource::internal &t){
        return true;
    }
    
};

#endif // !_I_INTERACTION_SOURCE_