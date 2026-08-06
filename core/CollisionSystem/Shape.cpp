#include "Shape.h"

#include <raylib.h>

bool Shape::Collision::operator()(const Shape::Circle form1, const Shape::Circle form2) const {
    return CheckCollisionCircles(
        {pos1.x, pos1.y}, form1.radius, 
        {pos2.x, pos2.y}, form2.radius
    );
}

bool Shape::Collision::operator()(const Shape::AABB form1, const Shape::AABB form2) const {
    return CheckCollisionRecs(
        {pos1.x - form1.width / 2, pos1.y - form1.height / 2, form1.width, form1.height}, 
        {pos2.x - form2.width / 2, pos2.y - form2.height / 2, form2.width, form2.height}
    );
}

bool Shape::Collision::operator()(const Shape::Circle form1, const Shape::AABB form2) const {            
    return CheckCollisionCircleRec(
        {pos1.x, pos1.y}, form1.radius, 
        {pos2.x - form2.width / 2, pos2.y - form2.height / 2, form2.width, form2.height}
    );
}

bool Shape::Collision::operator()(const Shape::AABB form1, const Shape::Circle form2) const {
    return CheckCollisionCircleRec(
        {pos2.x, pos2.y}, form2.radius, 
        {pos1.x - form1.width / 2, pos1.y - form1.height / 2, form1.width, form1.height}
    );
}

void Shape::Drawer::operator()(const Shape::Circle form) const {
    DrawCircleV({pos.x, pos.y}, form.radius, col);
}

void Shape::Drawer::operator()(const Shape::AABB form) const {
    DrawRectangleV({pos.x - form.width / 2, pos.y - form.height / 2}, {form.width, form.height}, col);
}

Shape::AABB Shape::BoundsGetter::operator()(const Shape::Circle form) const {
    return Shape::AABB{
        .width  = form.radius * 2,
        .height = form.radius * 2
    };
}

Shape::AABB Shape::BoundsGetter::operator()(const Shape::AABB form) const {
    return form;
}