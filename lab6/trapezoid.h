#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <iostream>
#include "point.h"
#include <memory>
#include "TAllocationBlock.h"


class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double a, double b, double c, double d);
    Trapezoid(std::shared_ptr<Trapezoid>& other);

    friend std::istream& operator>>(std::istream& is, Trapezoid& obj);
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& obj);

    Trapezoid& operator=(const Trapezoid& right);
    bool operator==(const Trapezoid& right);

    virtual ~Trapezoid();

    size_t VertexesNumber();
    double Area();

    void *operator new(size_t size);
    void operator delete(void *ptr);

public:
    double len_ab, len_bc, len_cd, len_da;
    Point a_, b_, c_, d_;

private:
    static TAllocationBlock block;
};

#endif // TRAPEZOID_H
