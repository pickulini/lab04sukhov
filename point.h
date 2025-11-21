#pragma once
#include <concepts>
#include <iostream>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    
    T getX() const { return x; }
    T getY() const { return y; }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    Point operator/(T divisor) const {
        return Point(x / divisor, y / divisor);
    }
};
