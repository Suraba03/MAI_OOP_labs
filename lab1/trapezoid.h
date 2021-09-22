#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <iostream>
#include "point.h"


class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double a, double b, double c, double d);
    Trapezoid(std::istream &is);
    Trapezoid(const Trapezoid& other);

    virtual ~Trapezoid();

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
public:
    double len_ab, len_bc, len_cd, len_da;
};

#endif // TRAPEZOID_H
