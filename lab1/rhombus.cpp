#include "rhombus.h"

#include <cmath>

static Point a_o, b_o, c_o, d_o;

Rhombus::Rhombus()
    : len_a(0.0),
      d_ac(0.0),
      d_bd(0.0) {
    std::cout << "Default Rhombus created" << std::endl;
}

Rhombus::Rhombus(double a_, double d_ac_, double d_bd_) 
    : len_a(a_),
      d_ac(d_ac_),
      d_bd(d_bd_) {
    std::cout << "Rhombus created" << std::endl;
}


Rhombus::Rhombus(std::istream &is) {

    std::cout << "Enter Data:" << std::endl;
    
    is >> a_o >> b_o >> c_o >> d_o;
    
    len_a = a_o.dist(b_o);
    d_ac = a_o.dist(c_o);
    d_bd = b_o.dist(d_o);
    
    std::cout << "Rhombus created via istream" << std::endl;
}

Rhombus::Rhombus(const Rhombus& other)
    : Rhombus(other.len_a, other.d_ac, other.d_bd) {
    std::cout << "Made copy of Rhombus" << std::endl;
}

size_t Rhombus::VertexesNumber() {
    return 4;
}

double Rhombus::Area() {
    return (d_bd * d_ac) / 2;
}

void Rhombus::Print(std::ostream& os) {
    std::cout << "Rhombus: ";
    os << a_o; std::cout << " ";
    os << b_o; std::cout << " ";
    os << c_o; std::cout << " ";
    os << d_o; std::cout << std::endl;
}

Rhombus::~Rhombus() {
    std::cout << "Rhombus deleted" << std::endl;
}