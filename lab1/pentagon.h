#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <iostream>
#include "point.h"


class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(double ab, double bc, double cd, double de,
             double ea, double d_ac_, double d_ce_);
    Pentagon(std::istream &is);
    Pentagon(const Pentagon& other);

    virtual ~Pentagon();

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);
public:
    double len_ab, len_bc, len_cd, len_de, len_ea, d_ac, d_ce;
};

#endif // PENTAGON_H
