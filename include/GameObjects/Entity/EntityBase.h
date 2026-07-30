#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <memory>
#include <raylib.h>
#include <raymath.h>

#include <vector>
#include <memory.h>

#include "../../GameSystem/GameContext.h"

#include "../Effect/ActiveEffect.h"
#include "../CollisionSystem/Shape.h"

#include "Intent/AimIntent.h"
#include "Intent/MovingIntent.h"

#include "MovingStrategy/IMovingStrategy.h"
#include "MovingStrategy/BlankMovingStrategy.h"

#include "IntentSource/Moving/IMovingIntentSource.h"
#include "IntentSource/Moving/BlankMovingIntentSource.h"

#include "RotationStrategy/IRotationStrategy.h"
#include "RotationStrategy/BlankRotationStrategy.h"

#include "IntentSource/Aim/IAimIntentSource.h"
#include "IntentSource/Aim/BlankAimIntentSource.h"

class EntityBase {
public:
    virtual ~EntityBase() = default;

    virtual void draw() const = 0;
    virtual void update(const GameContext& context) = 0;
    virtual void init(const GameContext& context) = 0;

    virtual bool isAlive() const = 0;
    
    void internalInit(const GameContext& context){
        _moving_strategy = std::make_unique<BlankMovingStrategy>(); 
        _rotation_strategy = std::make_unique<BlankRotationStrategy>();

        _moving_intent_source = std::make_unique<BlankMovingIntentSource>();
        _aim_intent_source = std::make_unique<BlankAimIntentSource>();

        init(context);
    }

    void internalUpdate(const GameContext& context){
        const float dt = context.tick.getTickPeriod();

        _move_update(dt);
        _aim_update(dt);
        _effect_update(dt);

        update(context);
    }

    Vector2 getPosition() const { return _position; }
    void setPosition(Vector2 position) { _position = position; }

    float getRotation() const { return _rotation; }
    void setRotation(const float rotation) { _rotation = rotation; }

    Shape::Variant getShape() const { return _shape; }
    void setShape(Shape::Variant shape){ _shape = shape; }

    void addEffect(ActiveEffect effect){
        _effects.push_back(std::move(effect));
    }

    void setMovingIntentSource(std::unique_ptr<IMovingIntentSource> source){
        _moving_intent_source = std::move(source);
    }
    
    void setMovingStrategy(std::unique_ptr<IMovingStrategy> strategy){
        _moving_strategy = std::move(strategy);
    }

    void setAimIntentSource(std::unique_ptr<IAimIntentSource> source){
        _aim_intent_source = std::move(source);
    }

    void setRotationStrategy(std::unique_ptr<IRotationStrategy> strategy){
        _rotation_strategy = std::move(strategy);
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

        std::erase_if(_effects, [](const ActiveEffect& effect){ 
            return effect.elapsed > effect.duration; });
    }

    void _move_update(const float dt){
        const MovingIntent intent = _moving_intent_source->get();
        const Vector2 ds = _moving_strategy->process(intent, dt);
        _position = Vector2Add(_position, ds);
    }

    void _aim_update(const float dt){
        const AimIntent intent = _aim_intent_source->get();
        const float drot = _rotation_strategy->process(intent, _position, _rotation, dt);
        _rotation += drot;
    }

private:
    Shape::Variant _shape;
    
    Vector2 _position;
    float _rotation;
    
    std::vector<ActiveEffect> _effects;
        
    std::unique_ptr<IMovingStrategy> _moving_strategy;
    std::unique_ptr<IRotationStrategy> _rotation_strategy;

    std::unique_ptr<IMovingIntentSource> _moving_intent_source;
    std::unique_ptr<IAimIntentSource> _aim_intent_source;
};

#endif // !_I_ENTITY_H_