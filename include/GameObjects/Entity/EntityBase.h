#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <raylib.h>

#include <memory>



class EntityBase{
public:
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual bool isAlive() const = 0;

    virtual Vector2 getPosition();
    virtual float getRotation();

private:
    Vector2 _position;
    float _rotation;

};

using EntityBasePtr = std::shared_ptr<EntityBase>;

#endif // !_I_ENTITY_H_