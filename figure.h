#pragma once
#include "point.h"
#include <memory>
#include <vector>

template<Scalar T>
class Figure {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices;
public:
    virtual ~Figure() = default;
    
    virtual Point<T> center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }
    
    operator double() const { return area(); }
};
