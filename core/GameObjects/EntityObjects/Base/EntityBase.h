#ifndef THEMOLLUSK_I_ENTITY_H
#define THEMOLLUSK_I_ENTITY_H

#include <memory>
#include <raylib.h>

#include <vector>

#include "GameObjects/Effect/ActiveEffect.h"
#include "GameObjects/CollisionSystem/Shape.h"

#include "EntityManager/EntityHandle.h"

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
    
    Vector2 getPosition() const;
    void setPosition(Vector2 position);

    float getRotation() const;
    void setRotation(const float rotation);

    EntityHandle getHandle() const;

    Shape::Variant getShape() const;
    void setShape(Shape::Variant shape);

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
    Shape::Variant _shape;
    
    Vector2 _position = {};
    float _rotation = 0;
    
    std::vector<ActiveEffect> _effects;
        
    std::unique_ptr<IMovingModel  > _moving_model;
    std::unique_ptr<IRotationModel> _rotation_model;

    std::unique_ptr<IMovingCueSource  > _moving_cue_source;
    std::unique_ptr<IRotationCueSource> _rotation_cue_source;

    EntityHandle _handle;
};

#endif // !THEMOLLUSK_I_ENTITY_H