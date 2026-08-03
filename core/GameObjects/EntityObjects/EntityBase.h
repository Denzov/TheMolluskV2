#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <memory>
#include <raylib.h>
#include <raymath.h>

#include <vector>

#include "../../GameSystem/GameContext.h"

#include "../Effect/ActiveEffect.h"
#include "../CollisionSystem/Shape.h"

#include "Rotation/RotationCue.h"
#include "Moving/MovingCue.h"

#include "Moving/Model/IMovingModel.h"
#include "Moving/Model/BlankMoving/BlankMovingModel.h"

#include "Moving/Source/IMovingCueSource.h"
#include "Moving/Source/BlankMoving/BlankMovingCueSource.h"

#include "Rotation/Model/IRotationModel.h"
#include "Rotation/Model/BlankRotation/BlankRotationModel.h"

#include "Rotation/Source/IRotationCueSource.h"
#include "Rotation/Source/BlankRotation/BlankRotationCueSource.h"


class EntityBase {
public:
    virtual ~EntityBase() = default;

    virtual void draw() const = 0;
    virtual void update(const GameContext& context) = 0;
    virtual void init(const GameContext& context) = 0;

    virtual bool isAlive() const = 0;
    
    void internalInit(const GameContext& context){
        _moving_model = std::make_unique<BlankMovingModel>(); 
        _rotation_model = std::make_unique<BlankRotationModel>();

        _moving_cue_source = std::make_unique<BlankMovingCueSource>();
        _rotation_cue_source = std::make_unique<BlankRotationCueSource>();

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

    void setMovingCueSource(std::unique_ptr<IMovingCueSource> source){
        _moving_cue_source = std::move(source);
    }
    
    void setMovingModel(std::unique_ptr<IMovingModel> model){
        _moving_model = std::move(model);
    }

    void setRotationCueSource(std::unique_ptr<IRotationCueSource> source){
        _rotation_cue_source = std::move(source);
    }

    void setRotationModel(std::unique_ptr<IRotationModel> model){
        _rotation_model = std::move(model);
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
        const MovingCue cue = _moving_cue_source->get();
        const Vector2 ds = _moving_model->process(cue, dt);
        _position = Vector2Add(_position, ds);
    }

    void _aim_update(const float dt){
        const RotationCue cue = _rotation_cue_source->get();
        const float drot = _rotation_model->process(
            cue, _position, _rotation, dt);
        _rotation += drot;
    }

private:
    Shape::Variant _shape;
    
    Vector2 _position;
    float _rotation;
    
    std::vector<ActiveEffect> _effects;
        
    std::unique_ptr<IMovingModel  > _moving_model;
    std::unique_ptr<IRotationModel> _rotation_model;

    std::unique_ptr<IMovingCueSource  > _moving_cue_source;
    std::unique_ptr<IRotationCueSource> _rotation_cue_source;
};

#endif // !_I_ENTITY_H_