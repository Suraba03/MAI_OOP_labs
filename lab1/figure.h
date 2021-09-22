#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
public:
    virtual void Print(std::ostream& os) = 0;
    virtual ~Figure() {};
};


#endif // FIGURE_H
