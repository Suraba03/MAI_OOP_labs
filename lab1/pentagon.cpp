#include "pentagon.h"

#include <cmath>

static Point a_o, b_o, c_o, d_o, e_o;

double triangle_area(double a, double b, double c) {
    double p = (a + b + c);
    double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

Pentagon::Pentagon()
    : len_ab(0.0),
      len_bc(0.0),
      len_cd(0.0),
      len_de(0.0),
      len_ea(0.0),
      d_ac(0.0),
      d_ce(0.0) {
    std::cout << "Default Pentagon created" << std::endl;
}

Pentagon::Pentagon(double ab, double bc, double cd, double de,
                   double ea, double d_ac_, double d_ce_) 
    : len_ab(ab),
      len_bc(bc),
      len_cd(cd),
      len_de(de),
      len_ea(ea),
      d_ac(d_ac_),
      d_ce(d_ce_) {
    std::cout << "Pentagon created" << std::endl;
}


Pentagon::Pentagon(std::istream &is) {

    std::cout << "Enter Data:" << std::endl;
    
    is >> a_o >> b_o >> c_o >> d_o >> e_o;
    
    len_ab = a_o.dist(b_o);
    len_bc = b_o.dist(c_o);
    len_cd = c_o.dist(d_o);
    len_de = d_o.dist(e_o);
    len_ea = e_o.dist(a_o);
    d_ac = a_o.dist(c_o);
    d_ce = c_o.dist(e_o);
    
    std::cout << "Pentagon created via istream" << std::endl;
}

Pentagon::Pentagon(const Pentagon& other)
    : Pentagon(other.len_ab, other.len_bc, other.len_cd, 
               other.len_de, other.len_ea, other.d_ac, other.d_ce) {
    std::cout << "Made copy of Pentagon" << std::endl;
}

size_t Pentagon::VertexesNumber() {
    return 5;
}

double Pentagon::Area() { 
    return triangle_area(len_ab, len_bc, d_ac) + 
           triangle_area(d_ac, d_ce, len_ea) +
           triangle_area(len_cd, len_de, d_ce);
}

void Pentagon::Print(std::ostream& os) {
    std::cout << "Pentagon: ";
    os << a_o; std::cout << " ";
    os << b_o; std::cout << " ";
    os << c_o; std::cout << " ";
    os << d_o; std::cout << " ";
    os << e_o; std::cout << std::endl;
}

Pentagon::~Pentagon() {
    std::cout << "Pentagon deleted" << std::endl;
}