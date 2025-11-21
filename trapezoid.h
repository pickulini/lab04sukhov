#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Trapezoid : public Figure<T> {
private:
    Point<T> center_;
    T radius;
    T angle;
    T alpha, beta;
    
    void calculateVertices() {
        using namespace std;
        this->vertices.clear();
        this->vertices.push_back(make_unique<Point<T>>(
            center_ + Point<T>(radius * cos(angle - alpha), radius * sin(angle - alpha)));
        this->vertices.push_back(make_unique<Point<T>>(
            center_ + Point<T>(radius * cos(angle + alpha), radius * sin(angle + alpha)));
        this->vertices.push_back(make_unique<Point<T>>(
            center_ + Point<T>(radius * cos(angle + M_PI - beta), radius * sin(angle + M_PI - beta)));
        this->vertices.push_back(make_unique<Point<T>>(
            center_ + Point<T>(radius * cos(angle + M_PI + beta), radius * sin(angle + M_PI + beta)));
    }
public:
    Trapezoid(Point<T> c, T r, T ang, T a, T b) 
        : center_(c), radius(r), angle(ang), alpha(a), beta(b) {
        calculateVertices();
    }
    
    Point<T> center() const override { return center_; }
    
    double area() const override {
        T base1 = 2 * radius * sin(alpha);
        T base2 = 2 * radius * sin(beta);
        T height = radius * (cos(alpha) + cos(beta));
        return (base1 + base2) * height / 2;
    }
    
    void print(std::ostream& os) const override {
        os << "Trapezoid vertices: ";
        for (const auto& v : this->vertices) os << *v << " ";
        os << "Center: " << center_ << " Area: " << area();
    }
};
