#ifndef THEMOLLUSK_VEC2_H
#define THEMOLLUSK_VEC2_H

namespace Math{
    struct Vec2{
        float x, y;

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator+(const float other) const;
        Vec2& operator+=(const Vec2& other);
        Vec2& operator+=(const float other);

        Vec2 operator-(const Vec2& other) const;
        Vec2 operator-(const float other) const;
        Vec2& operator-=(const Vec2& other);
        Vec2& operator-=(const float other);

        Vec2 operator*(const Vec2& other) const;
        Vec2 operator*(const float other) const;
        Vec2& operator*=(const Vec2& other);
        Vec2& operator*=(const float other);

        Vec2 operator/(const Vec2& other) const;
        Vec2 operator/(const float other) const;
        Vec2& operator/=(const Vec2& other);
        Vec2& operator/=(const float other);

        float length() const;
        float lengthSq() const;

        float x_axis_angle() const;
        
        Vec2 normalize() const;
    };

    // Vec2 operator/(float scalar, const Vec2& vec);

}

#endif // !THEMOLLUSK_VEC2_H