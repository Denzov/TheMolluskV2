#ifndef THEMOLLUSK_I_ENTITY_H
#define THEMOLLUSK_I_ENTITY_H

#include <memory>
#include <vector>

#include "Math/Vec2.h"

#include "GameObjects/Effect/ActiveEffect.h"
#include "CollisionSystem/ShapeCluster.h"

#include "EntityManager/EntityHandle.h"

#include <raylib.h>

class EntityManager;
class EntitySystem;

class GameContext;

class IMovingCueSource;
class IMovingModel;

class IRotationCueSource;
class IRotationModel;

class EntityBase {
    friend class EntityManager;
    friend class EntitySystem;

public:
    virtual ~EntityBase();

    virtual bool isAlive() const = 0;
    
    float getDesiredVelocity() const ; 
    void setDesiredVelocity(float velocity);

    Math::Vec2 getPosition() const;
    void setPosition(Math::Vec2 position);

    float getRotation() const;
    void setRotation(const float rotation);

    EntityHandle getHandle() const;

    Shape::Cluster& getShapeCluster();
    const Shape::Cluster& getShapeCluster() const;
    void setShapeCluster(Shape::Cluster&&);
    void addNodeToCluster(Shape::ClusterNode);

    void addEffect(ActiveEffect effect);

    void setMovingCueSource(std::unique_ptr<IMovingCueSource> source);
    void setMovingModel(std::unique_ptr<IMovingModel> model);

    void setRotationCueSource(std::unique_ptr<IRotationCueSource> source);
    void setRotationModel(std::unique_ptr<IRotationModel> model);

protected:
    virtual void draw() const = 0;
    virtual void update(const GameContext& context) = 0;
    virtual void init(const GameContext& context) = 0;

private:
    void _internal_init(const GameContext& context, EntityHandle handle);
    void _internal_update(const GameContext& context);

    void _effect_update(const float dt);
    void _move_update(const float dt);
    void _rotation_update(const float dt);

private:
    Shape::Cluster _shape_cluster;
    
    Math::Vec2 _position = {};
    float _desired_velocity = 0;
    float _rotation = 0;
    
    std::vector<ActiveEffect> _effects;
        
    std::unique_ptr<IMovingModel  > _moving_model;
    std::unique_ptr<IRotationModel> _rotation_model;

    std::unique_ptr<IMovingCueSource  > _moving_cue_source;
    std::unique_ptr<IRotationCueSource> _rotation_cue_source;

    EntityHandle _handle;
};

#endif // !THEMOLLUSK_I_ENTITY_H