#include "EntityBase.h"

#include <raymath.h>

#include "GameSystem/GameContext.h"

#include "Rotation/RotationCue.h"
#include "Moving/MovingCue.h"

#include "Moving/Model/IMovingModel.h"
#include "Moving/Source/IMovingCueSource.h"

#include "Rotation/Model/IRotationModel.h"
#include "Rotation/Source/IRotationCueSource.h"

#include "Rotation/Source/BlankRotation/BlankRotationCueSource.h"
#include "Rotation/Model/BlankRotation/BlankRotationModel.h"

#include "Moving/Source/BlankMoving/BlankMovingCueSource.h"
#include "Moving/Model/BlankMoving/BlankMovingModel.h"

EntityBase::~EntityBase() = default;

void EntityBase::internalInit(const GameContext& context) {
    _moving_model = std::make_unique<BlankMovingModel>(); 
    _rotation_model = std::make_unique<BlankRotationModel>();

    _moving_cue_source = std::make_unique<BlankMovingCueSource>();
    _rotation_cue_source = std::make_unique<BlankRotationCueSource>();

    init(context);
}

void EntityBase::internalUpdate(const GameContext& context) {
    const float dt = context.tick.getTickPeriod();

    _move_update(dt);
    _aim_update(dt);
    _effect_update(dt);

    update(context);
}

Vector2 EntityBase::getPosition() const { 
    return _position;
}

void EntityBase::setPosition(Vector2 position) { 
    _position = position; 
}

float EntityBase::getRotation() const { 
    return _rotation; 
}

void EntityBase::setRotation(const float rotation) { 
    _rotation = rotation; 
}

Shape::Variant EntityBase::getShape() const { 
    return _shape; 
}

void EntityBase::setShape(Shape::Variant shape) { 
    _shape = shape;
}

void EntityBase::addEffect(ActiveEffect effect) {
    _effects.push_back(std::move(effect));
}

void EntityBase::setMovingCueSource(std::unique_ptr<IMovingCueSource> source) {
    _moving_cue_source = std::move(source);
}
    
void EntityBase::setMovingModel(std::unique_ptr<IMovingModel> model) {
    _moving_model = std::move(model);
}

void EntityBase::setRotationCueSource(std::unique_ptr<IRotationCueSource> source) {
    _rotation_cue_source = std::move(source);
}

void EntityBase::setRotationModel(std::unique_ptr<IRotationModel> model) {
    _rotation_model = std::move(model);
}

void EntityBase::_effect_update(const float dt){
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

void EntityBase::_move_update(const float dt){
    const MovingCue cue = _moving_cue_source->get();
    const Vector2 ds = _moving_model->process(cue, dt);

    _position = Vector2Add(_position, ds);
}

void EntityBase::_aim_update(const float dt){
    const RotationCue cue = _rotation_cue_source->get();
    const float drot = _rotation_model->process(
        cue, _position, _rotation, dt);

    _rotation += drot;
}