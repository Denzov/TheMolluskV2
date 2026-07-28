#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <memory>
#include <raylib.h>
#include <raymath.h>

#include <vector>
#include <memory.h>

#include "../Effect/ActiveEffect.h"
#include "../CollisionSystem/Collider.h"

#include "MovingStrategy/IMovingStrategy.h"
#include "MovingStrategy/BlankMovingStrategy.h"
#include "Intent/MovingIntent.h"

class EntityBase {
public:
    virtual ~EntityBase() = default;

    virtual void draw() const = 0;
    virtual void update(const float dt) = 0;
    virtual void init() = 0;

    virtual bool isAlive() const = 0;
    
    void internalInit(){
        _moving_strategy = std::make_unique<BlankMovingStrategy>(); 

        init();
    }

    void internalUpdate(const float dt){
        _move_update(dt);
        _effect_update(dt);

        update(dt);
    }

    void addEffect(ActiveEffect effect){
        _effects.push_back(std::move(effect));
    }
private:
    void _effect_update(const float dt){
        for(auto& effect : _effects){
            effect.elapsed += dt;

            if(effect.elapsed >= effect.next_apply){
                effect.effect->apply(*this);
                effect.next_apply += effect.interval;
            }
        }

        std::erase_if(_effects, [](const ActiveEffect& effect){ return effect.elapsed > effect.duration; });
    }

    void _move_update(const float dt){
        const Vector2 ds = _moving_strategy->process(_moving_intent, dt);
        _position = Vector2Add(_position, ds);
    }

private:
    Collider::Variant _collider;
    
    Vector2 _position;
    float _rotation;
    
    std::vector<ActiveEffect> _effects;
    
    std::unique_ptr<IMovingStrategy> _moving_strategy;
    MovingIntent _moving_intent;
};

#endif // !_I_ENTITY_H_