#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <iostream>
#include "point.h"


class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(double a_, double d_ac_, double d_bd_);
    Rhombus(std::istream &is);
    Rhombus(const Rhombus& other);

    virtual ~Rhombus();

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
public:
    double len_a, d_ac, d_bd;
};

#endif // RHOMBUS_H
