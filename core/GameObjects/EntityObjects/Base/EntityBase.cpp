#include "EntityBase.h"

#include <raylib.h>
#include <raymath.h>

#include "GameSystem/GameContext.h"

#include "Rotation/RotationCue.h"
#include "Moving/MovingCue.h"

#include "Moving/Model/MovingModelBase.h"
#include "Moving/Source/IMovingCueSource.h"

#include "Rotation/Model/RotationModelBase.h"
#include "Rotation/Source/IRotationCueSource.h"

#include "Rotation/Source/BlankRotation/BlankRotationCueSource.h"
#include "Rotation/Model/BlankRotation/BlankRotationModel.h"

#include "Moving/Source/BlankMoving/BlankMovingCueSource.h"
#include "Moving/Model/BlankMoving/BlankMovingModel.h"

EntityBase::~EntityBase() = default;

void EntityBase::_internal_init(const GameContext& context, EntityHandle handle) {
    _moving_model = std::make_unique<BlankMovingModel>(); 
    _rotation_model = std::make_unique<BlankRotationModel>();

    _moving_cue_source = std::make_unique<BlankMovingCueSource>();
    _rotation_cue_source = std::make_unique<BlankRotationCueSource>();

    _handle = handle;

    init(context);
}

void EntityBase::_internal_update(const GameContext& context) {
    const float dt = context.tick.getTickPeriod();

    _move_update(dt);
    _rotation_update(dt);
    _effect_update(dt);

    update(context);
}

EntityHandle EntityBase::getHandle() const {
    return _handle;
}

Shape::Cluster& EntityBase::getShapeCluster(){ 
    return _shape_cluster; 
}

const Shape::Cluster& EntityBase::getShapeCluster() const { 
    return _shape_cluster; 
}

void EntityBase::setShapeCluster(Shape::Cluster&& cluster){
    _shape_cluster = cluster;
}

void EntityBase::addNodeToCluster(Shape::ClusterNode node){
    _shape_cluster.add(node);
}

void EntityBase::addEffect(ActiveEffect effect) {
    _effects.push_back(std::move(effect));
}

void EntityBase::setMovingCueSource(std::unique_ptr<IMovingCueSource> source) {
    _moving_cue_source = std::move(source);
}
    
void EntityBase::setMovingModel(std::unique_ptr<MovingModelBase> model) {
    _moving_model = std::move(model);
}

const MovingModelBase& EntityBase::getMovingModel() const {
    return *_moving_model.get();
}

void EntityBase::setRotationCueSource(std::unique_ptr<IRotationCueSource> source) {
    _rotation_cue_source = std::move(source);
}

void EntityBase::setRotationModel(std::unique_ptr<RotationModelBase> model) {
    _rotation_model = std::move(model);
}

const RotationModelBase& EntityBase::getRotationModel() const {
    return *_rotation_model.get();
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
    _moving_model->process(cue, dt);
}

void EntityBase::_rotation_update(const float dt){
    const RotationCue cue = _rotation_cue_source->get();
    _rotation_model->process(cue, dt);
}