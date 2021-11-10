#include "trapezoid.h"

#include <cmath>


Trapezoid::Trapezoid()
    : len_ab(0.0),
      len_bc(0.0),
      len_cd(0.0),
      len_da(0.0) {
}

Trapezoid::Trapezoid(double ab, double bc, double cd, double da) 
    : len_ab(ab),
      len_bc(bc),
      len_cd(cd),
      len_da(da) {
}


Trapezoid::Trapezoid(const Trapezoid& other)
    : Trapezoid(other.len_ab, other.len_bc, other.len_cd, other.len_da) {
}



std::istream& operator>>(std::istream& is, Trapezoid& obj) {
    std::cout << "Enter points: ";

    is >> obj.a_;
    is >> obj.b_;
    is >> obj.c_;
    is >> obj.d_;

    obj.len_ab = obj.a_.dist(obj.b_);
    obj.len_bc = obj.b_.dist(obj.c_);
    obj.len_cd = obj.c_.dist(obj.d_);
    obj.len_da = obj.d_.dist(obj.a_);

    return is;
} //

std::ostream& operator<<(std::ostream& os, const Trapezoid& obj) {
    os << "A = " << obj.a_ << ", B = " << obj.b_ << ", C = " << obj.c_ << ", D = " << obj.d_;
    return os;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other)
        return *this;
    
    len_ab = other.len_ab;
    len_bc = other.len_bc;
    len_cd = other.len_cd;
    len_da = other.len_da;
    a_.x_ = other.a_.x_;
    a_.y_ = other.a_.y_;
    b_.x_ = other.b_.x_;
    b_.y_ = other.b_.y_;
    c_.x_ = other.c_.x_;
    c_.y_ = other.c_.y_;
    d_.x_ = other.d_.x_;
    d_.x_ = other.d_.x_;

    std::cout << "Trapezoid copied" << std::endl;
    
    return *this;  
} //

bool Trapezoid::operator==(const Trapezoid& other) {
    if (this->len_ab == other.len_ab &&
        this->len_bc == other.len_bc &&
        this->len_cd == other.len_cd &&
        this->len_da == other.len_da) {
        std::cout << "Trapezoids are equal" << std::endl;        
        return 1;
    } else {
        std::cout << "Trapezoids are not equal" << std::endl; 
        return 0;
    }
} //

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

Trapezoid::~Trapezoid() {

    std::cout << "Trapezoid deleted" << std::endl;
}