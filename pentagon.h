#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Pentagon : public Figure<T> {
private:
    Point<T> center_;
    T radius;
    T angle;
    
    void calculateVertices() {
        using namespace std;
        this->vertices.clear();
        for (int i = 0; i < 5; ++i) {
            T currAngle = angle + i * 2 * M_PI / 5;
            this->vertices.push_back(make_unique<Point<T>>(
                center_ + Point<T>(radius * cos(currAngle), radius * sin(currAngle)));
        }
    }
public:
    Pentagon(Point<T> c, T r, T ang = 0) : center_(c), radius(r), angle(ang) {
        calculateVertices();
    }
    
    Point<T> center() const override { return center_; }
    
    double area() const override {
        return 2.5 * radius * radius * sin(2 * M_PI / 5);
    }
    
    void print(std::ostream& os) const override {
        os << "Pentagon vertices: ";
        for (const auto& v : this->vertices) os << *v << " ";
        os << "Center: " << center_ << " Area: " << area();
    }
};
