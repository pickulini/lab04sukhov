#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Rhombus : public Figure<T> {
private:
    Point<T> center_;
    T radius;
    T angle;
    
    void calculateVertices() {
        using namespace std;
        this->vertices.clear();
        for (int i = 0; i < 4; ++i) {
            T currAngle = angle + i * M_PI / 2;
            this->vertices.push_back(make_unique<Point<T>>(
                center_ + Point<T>(radius * cos(currAngle), radius * sin(currAngle)));
        }
    }
public:
    Rhombus(Point<T> c, T r, T ang = 0) : center_(c), radius(r), angle(ang) {
        calculateVertices();
    }
    
    Point<T> center() const override { return center_; }
    
    double area() const override {
        T diagonal1 = 2 * radius;
        T diagonal2 = 2 * radius;
        return diagonal1 * diagonal2 / 2;
    }
    
    void print(std::ostream& os) const override {
        os << "Rhombus vertices: ";
        for (const auto& v : this->vertices) os << *v << " ";
        os << "Center: " << center_ << " Area: " << area();
    }
};
