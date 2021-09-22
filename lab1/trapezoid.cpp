#include "trapezoid.h"

#include <cmath>

static Point a_o, b_o, c_o, d_o;

Trapezoid::Trapezoid()
    : len_ab(0.0),
      len_bc(0.0),
      len_cd(0.0),
      len_da(0.0) {
    std::cout << "Default Trapezoid created" << std::endl;
}

Trapezoid::Trapezoid(double ab, double bc, double cd, double da) 
    : len_ab(ab),
      len_bc(bc),
      len_cd(cd),
      len_da(da) {
    std::cout << "Trapezoid created" << std::endl;
}


Trapezoid::Trapezoid(std::istream &is) {

    std::cout << "Enter Data:" << std::endl;
    
    is >> a_o >> b_o >> c_o >> d_o;
    
    len_ab = a_o.dist(b_o);
    len_bc = b_o.dist(c_o);
    len_cd = c_o.dist(d_o);
    len_da = d_o.dist(a_o);
    
    std::cout << "Trapezoid created via istream" << std::endl;
}

Trapezoid::Trapezoid(const Trapezoid& other)
    : Trapezoid(other.len_ab, other.len_bc, other.len_cd, other.len_da) {
    std::cout << "Made copy of Trapezoid" << std::endl;
}

size_t Trapezoid::VertexesNumber() {
    return 4;
}

double Trapezoid::Area() {
    double p = (len_ab + len_bc + len_cd + len_da) / 2;
    return (len_bc + len_da) *
           std::sqrt((p - len_bc) *
                     (p - len_da) *
                     (p - len_da - len_ab) *
                     (p - len_da - len_cd)) /
           std::abs(len_bc - len_da);
}

void Trapezoid::Print(std::ostream& os) {
    std::cout << "Trapezoid: ";
    os << a_o; std::cout << " ";
    os << b_o; std::cout << " ";
    os << c_o; std::cout << " ";
    os << d_o; std::cout << std::endl;
}

Trapezoid::~Trapezoid() {
    std::cout << "Trapezoid deleted" << std::endl;
}