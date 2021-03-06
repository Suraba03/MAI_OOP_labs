#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual size_t VertexesNumber() = 0;
    virtual double Area() = 0;
    virtual ~Figure() {};
};


#endif // FIGURE_H
