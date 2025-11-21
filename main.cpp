#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

int main() {
    Array<shared_ptr<Figure<double>>> figures;
    
    cout << "=== Testing Figures (Variant 20) ===" << endl;
    
    figures.push_back(make_shared<Trapezoid<double>>(
        Point<double>(0, 0), 5.0, 0.0, M_PI/6, M_PI/4));
    
    figures.push_back(make_shared<Rhombus<double>>(
        Point<double>(1, 1), 3.0));
    
    figures.push_back(make_shared<Pentagon<double>>(
        Point<double>(2, 2), 4.0));
    
    cout << "\nAll figures:" << endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        cout << "Figure " << i << ": " << *figures[i] << endl;
    }
    
    double total_area = 0;
    for (const auto& fig : figures) {
        total_area += fig->area();
    }
    cout << "\nTotal area of all figures: " << total_area << endl;
    
    cout << "\nDeleting figure at index 1..." << endl;
    figures.erase(1);
    
    cout << "After deletion:" << endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        cout << "Figure " << i << ": " << *figures[i] << endl;
    }
    
    cout << "\n=== Testing with different types ===" << endl;
    Array<shared_ptr<Figure<float>>> float_figures;
    float_figures.push_back(make_shared<Rhombus<float>>(
        Point<float>(0.5f, 0.5f), 2.5f));
    
    for (size_t i = 0; i < float_figures.size(); ++i) {
        cout << "Float figure " << i << ": " << *float_figures[i] << endl;
    }
    
    return 0;
}
