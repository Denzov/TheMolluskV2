#include "Shape.h"

#include <raylib.h>

bool Shape::Collision::operator()(const Shape::Circle& form1, const Shape::Circle& form2) const {
    return CheckCollisionCircles(
        {.x=pos1.x, .y=pos1.y}, form1.radius, 
        {.x=pos2.x, .y=pos2.y}, form2.radius
    );
}

bool Shape::Collision::operator()(const Shape::AABB& form1, const Shape::AABB& form2) const {
    return CheckCollisionRecs(
        {pos1.x, pos1.y, form1.width, form1.height}, 
        {pos2.x, pos2.y, form2.width, form2.height}
    );
}

bool Shape::Collision::operator()(const Shape::Circle& form1, const Shape::AABB& form2) const {            
    return CheckCollisionCircleRec(
        {.x=pos1.x, .y=pos1.y}, form1.radius, 
        {pos2.x, pos2.y, form2.width, form2.height}
    );
}

bool Shape::Collision::operator()(const Shape::AABB& form1, const Shape::Circle& form2) const {
    return CheckCollisionCircleRec(
        {.x=pos2.x, .y=pos2.y}, form2.radius, 
        {pos1.x, pos1.y, form1.width, form1.height}
    );
}

void Shape::Drawer::operator()(const Shape::Circle& form) const {
    DrawCircleV({.x=pos.x, .y=pos.y}, form.radius, col);
}

void Shape::Drawer::operator()(const Shape::AABB& form) const {
    DrawRectangleV({.x=pos.x, .y=pos.y}, {form.width, form.height}, col);
}