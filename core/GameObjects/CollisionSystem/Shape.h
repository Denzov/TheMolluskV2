#ifndef THEMOLLUSK_SHAPE_H
#define THEMOLLUSK_SHAPE_H

#include <variant>
#include "Math/Vec2.h"

class Color;

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
        const Math::Vec2& pos1;
        const Math::Vec2& pos2;

        bool operator()(const Shape::Circle& form1, const Shape::Circle& form2) const;
        bool operator()(const Shape::AABB& form1, const Shape::AABB& form2) const;
        bool operator()(const Shape::Circle& form1, const Shape::AABB& form2) const;
        bool operator()(const Shape::AABB& form1, const Shape::Circle& form2) const;
    };

    inline bool intersect(
        const Variant& form1, const Math::Vec2& pos1, 
        const Variant& form2, const Math::Vec2& pos2) 
    {
        return std::visit(Collision{pos1, pos2}, form1, form2);
    }

    struct Drawer{
        const Math::Vec2& pos;
        const Color& col;

        void operator()(const Shape::Circle& form) const;
        void operator()(const Shape::AABB& form) const;
    };

    inline void draw(const Variant& form, const Math::Vec2& pos, const Color& col){
        std::visit(Drawer{.pos = pos, .col = col}, form);
    }
}

#endif // !THEMOLLUSK_SHAPE_H