#ifndef THEMOLLUSK_ENTITY_SYSTEM_H
#define THEMOLLUSK_ENTITY_SYSTEM_H

class EntityManager;
class GameContext;

class EntitySystem{
public:
    void update(EntityManager&, GameContext&);
    void draw(EntityManager&) const;

    void cleanup(EntityManager&);
};

#endif // !THEMOLLUSK_ENTITY_SYSTEM_H