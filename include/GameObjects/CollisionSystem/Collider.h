#ifndef _COLLISION_FORMS_H_
#define _COLLISION_FORMS_H_

#include <raylib.h>

#include <variant>

namespace Collider {
    struct Circle{
        float radius;
    };

    struct AABB{
        float width;
        float height;
    };

};

namespace Collider {
    using Variant = std::variant<
        Collider::Circle,
        Collider::AABB
    >;

    struct Visitor{
        const Vector2& pos1;
        const Vector2& pos2;

        bool operator()(const Collider::Circle& form1, const Collider::Circle& form2) const {
            return CheckCollisionCircles(
                pos1, form1.radius, 
                pos2, form2.radius
            );
        }

        bool operator()(const Collider::AABB& form1, const Collider::AABB& form2) const {
            return CheckCollisionRecs(
                {pos1.x, pos1.y, form1.width, form1.height}, 
                {pos2.x, pos2.y, form2.width, form2.height}
            );
        }

        bool operator()(const Collider::Circle& form1, const Collider::AABB& form2) const {
            return CheckCollisionCircleRec(
                pos1, form1.radius, 
                {pos2.x, pos2.y, form2.width, form2.height}
            );
        }

        bool operator()(const Collider::AABB& form1, const Collider::Circle& form2) const {
            return CheckCollisionCircleRec(
                pos2, form2.radius, 
                {pos1.x, pos1.y, form1.width, form1.height}
            );
        }
    };

    inline bool intersect(const Variant& form1, const Vector2& pos1, const Variant& form2, const Vector2& pos2) {
        return std::visit(Visitor{pos1, pos2}, form1, form2);
    }
}

#endif // !_COLLISION_FORMS_H_