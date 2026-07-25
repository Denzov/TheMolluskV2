#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <raylib.h>

#include <vector>

#include "../Effect/ActiveEffect.h"
#include "../CollisionSystem/Collider.h"

class EntityBase{
public:
    virtual ~EntityBase() = default;

    virtual void draw() const = 0;
    virtual void update(const float dt) = 0;

    virtual bool isAlive() const = 0;
    
    Vector2 getPosition() const { return _position; }
    Collider::Variant getCollider() const { return _collider; }
    float getRotation() const { return _rotation; }

    void setPosition(const Vector2 new_pos){ _position = new_pos; }
    void setRotation(const float new_rot) { _rotation = new_rot; }

    void addPosition(const Vector2 add_pos) { 
        _position = {
            _position.x + add_pos.x, 
            _position.y + add_pos.y
        };
    }
    void addRotation(const float add_rot){ _rotation += add_rot; }

    void addEffect(ActiveEffect effect){
        _effects.push_back(std::move(effect));
    }

    void effectUpdate(float dt){
        for(auto& effect : _effects){
            effect.elapsed += dt;

            if(effect.elapsed >= effect.next_apply){
                effect.effect->apply(*this);
                effect.next_apply += effect.interval;
            }
        }

        std::erase_if(_effects, [](const ActiveEffect& effect){ return effect.elapsed >= effect.duration; });
    }

private:
    Collider::Variant _collider;
    
    Vector2 _position;
    float _rotation;
    
    std::vector<ActiveEffect> _effects;
};

#endif // !_I_ENTITY_H_