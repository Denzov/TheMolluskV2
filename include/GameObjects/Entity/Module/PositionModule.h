#ifndef _POSITION_MODULE_H_
#define _POSITION_MODULE_H_

#include <raylib.h>

namespace EntityModule {
    using Position = Vector2;

    class IMovable{
    public:
        virtual ~IMovable() = default;    

        Position getPosition() const;
        void setPosition(const Position new_pos){}
    };
}
#endif // !_POSITION_MODULE_H_