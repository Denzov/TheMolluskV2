#ifndef _COLLISION_FORMS_H_
#define _COLLISION_FORMS_H_

#include <raylib.h>

#include <variant>

namespace Collider {
    struct Circle{
        Vector2 position;
        float radius;
    };

    using AABB = Rectangle;

};

struct CollisionVisitor{
    bool operator()(const Collider::Circle& c1, const Collider::Circle& c2) const{
        return CheckCollisionCircles(c1.position, c1.radius, c2.position, c2.radius);
    }

    bool operator()(const Collider::AABB& c1, const Collider::AABB& c2) const {
        return CheckCollisionRecs(c1, c2);
    }

    bool operator()(const Collider::AABB& c1, const Collider::Circle& c2) const {
        return CheckCollisionCircleRec(c2.position, c2.radius, c1);
    }

    bool operator()(const Collider::Circle& c1, const Collider::AABB& c2) const {
        return CheckCollisionCircleRec(c1.position, c1.radius, c2);
    }
};

namespace Collider {
    using Variant = std::variant<
        Collider::Circle,
        Collider::AABB
    >;

    inline bool intersect(const Variant& form1, const Variant& form2){
        return std::visit(CollisionVisitor{}, form1, form2);
    }
}

#endif // !_COLLISION_FORMS_H_