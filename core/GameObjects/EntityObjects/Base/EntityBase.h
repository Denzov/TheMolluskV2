#ifndef _I_ENTITY_H_
#define _I_ENTITY_H_

#include <memory>
#include <raylib.h>

#include <vector>

#include "GameObjects/Effect/ActiveEffect.h"
#include "GameObjects/CollisionSystem/Shape.h"

class GameContext;

class IMovingCueSource;
class IMovingModel;

class IRotationCueSource;
class IRotationModel;

class EntityBase {
public:
    virtual ~EntityBase();

    virtual void draw() const = 0;
    virtual void update(const GameContext& context) = 0;
    virtual void init(const GameContext& context) = 0;

    virtual bool isAlive() const = 0;
    
    void internalInit(const GameContext& context);
    void internalUpdate(const GameContext& context);

    Vector2 getPosition() const;
    void setPosition(Vector2 position);

    float getRotation() const;
    void setRotation(const float rotation);

    Shape::Variant getShape() const;
    void setShape(Shape::Variant shape);

    void addEffect(ActiveEffect effect);

    void setMovingCueSource(std::unique_ptr<IMovingCueSource> source);
    void setMovingModel(std::unique_ptr<IMovingModel> model);

    void setRotationCueSource(std::unique_ptr<IRotationCueSource> source);
    void setRotationModel(std::unique_ptr<IRotationModel> model);

private:
    void _effect_update(const float dt);
    void _move_update(const float dt);
    void _aim_update(const float dt);

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