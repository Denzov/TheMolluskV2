#include "Vec2.h"

#include <cmath>

#include "Constants.h"

namespace Math{
    Vec2 Vec2::operator+(const Vec2& other) const {
        return {
            .x = x + other.x, 
            .y = y + other.y
        };
    }

    Vec2 Vec2::operator+(const float other) const {
        return {
            .x = x + other, 
            .y = y + other
        };
    }

    Vec2& Vec2::operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& Vec2::operator+=(const float other) {
        x += other;
        y += other;
        return *this; 
    }

    Vec2 Vec2::operator-(const Vec2& other) const {
        return {
            .x = x - other.x, 
            .y = y - other.y
        };
    }

    Vec2 Vec2::operator-(const float other) const {
        return {
            .x = x - other, 
            .y = y - other
        };
    }

    Vec2& Vec2::operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& Vec2::operator-=(const float other) {
        x -= other;
        y -= other;
        return *this; 
    }

    Vec2 Vec2::operator*(const Vec2& other) const {
        return {
            .x = x * other.x, 
            .y = y * other.y
        };
    }

    Vec2 Vec2::operator*(const float other) const {
        return {
            .x = x * other, 
            .y = y * other
        };
    }

    Vec2& Vec2::operator*=(const Vec2& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vec2& Vec2::operator*=(const float other) {
        x *= other;
        y *= other;
        return *this; 
    }

    Vec2 Vec2::operator/(const Vec2& other) const {
        return {
            .x = x / other.x, 
            .y = y / other.y
        };
    }

    Vec2 Vec2::operator/(const float other) const {
        return {
            .x = x / other, 
            .y = y / other
        };
    }

    Vec2& Vec2::operator/=(const Vec2& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vec2& Vec2::operator/=(const float other) {
        x /= other;
        y /= other;
        return *this; 
    }

    float Vec2::lengthSq() const {
        return x*x + y*y;
    }

    float Vec2::length() const {
        const float sq = lengthSq();

        if(sq < EPSILON) return 0;

        return std::sqrt(sq);
    }

    float Vec2::x_axis_angle() const {
        return std::atan2(y, x);
    }

    Vec2 Vec2::normalize() const {
        if (std::abs(x) < EPSILON && std::abs(y) < EPSILON) 
            return {0, 0};

        const float length = this->length();
        return *this / length;
    }
}