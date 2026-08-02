#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <raylib.h>

#include <variant>

namespace Shape {
    struct Circle{
        float radius;
    };

    struct AABB{
        float width;
        float height;
    };

    using Variant = std::variant<
        Shape::Circle,
        Shape::AABB
    >;

    struct Collision{
        const Vector2& pos1;
        const Vector2& pos2;

        bool operator()(const Shape::Circle& form1, const Shape::Circle& form2) const {
            return CheckCollisionCircles(
                pos1, form1.radius, 
                pos2, form2.radius
            );
        }

        bool operator()(const Shape::AABB& form1, const Shape::AABB& form2) const {
            return CheckCollisionRecs(
                {pos1.x, pos1.y, form1.width, form1.height}, 
                {pos2.x, pos2.y, form2.width, form2.height}
            );
        }

        bool operator()(const Shape::Circle& form1, const Shape::AABB& form2) const {
            return CheckCollisionCircleRec(
                pos1, form1.radius, 
                {pos2.x, pos2.y, form2.width, form2.height}
            );
        }

        bool operator()(const Shape::AABB& form1, const Shape::Circle& form2) const {
            return CheckCollisionCircleRec(
                pos2, form2.radius, 
                {pos1.x, pos1.y, form1.width, form1.height}
            );
        }
    };

    inline bool intersect(const Variant& form1, const Vector2& pos1, const Variant& form2, const Vector2& pos2) {
        return std::visit(Collision{pos1, pos2}, form1, form2);
    }

    struct Drawer{
        const Vector2& pos;
        const Color& col;

        void operator()(const Shape::Circle& form) const {
            DrawCircleV(pos, form.radius, col);
        }
        void operator()(const Shape::AABB& form) const {
            DrawRectangleV(pos, {form.width, form.height}, col);
        }
    };

    inline void draw(const Variant& form, const Vector2& pos, const Color& col){
        std::visit(Drawer{.pos = pos, .col = col}, form);
    }
}

#endif // !_SHAPE_H_