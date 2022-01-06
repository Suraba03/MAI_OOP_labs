#include "money.h"

Money::Money()
    : rub_(0), kop_(0) {}

Money::Money(unsigned long long rub, uint16_t kop)
    : rub_(rub), kop_(kop) {}

Money::Money(const Money &other)
    : Money(other.rub_, other.kop_) {}

Money::Money(std::istream &is)
{
    is >> rub_ >> kop_;
}

unsigned long long Money::get_rub() const {
    return rub_;
}

uint16_t Money::get_kop() const {
    return kop_;
}

Money &Money::operator=(const Money &other)
{
    if (this == &other) {
        return *this;
    }
    rub_ = other.rub_;
    kop_ = other.kop_;
    return *this;
}

Money operator+(const Money& left, const Money& other) {
    Money t;
    t.rub_ = left.rub_ + other.rub_;
    t.kop_ = left.kop_ + other.kop_;
    if (t.kop_ >= 100) {
        t.rub_;
        t.kop_ -= 100;
    }
    return t;
}

Money operator-(const Money& left, const Money& other) {
    Money t;
    Money r = left;
    t.rub_ = left.rub_ - other.rub_;
    if (left.kop_ < other.kop_) {
        t.rub_--;
        r.kop_ = left.kop_ + 100;
        t.kop_ = left.kop_ - other.kop_;
        r.kop_ -= 100;
    }
    else t.kop_ = left.kop_ - other.kop_;
    return t;
}

double operator/(const Money& left, const Money& other) {
    double t, a, b;
    a = (left.rub_ * 100 + left.kop_);
    b = (other.rub_ * 100 + other.kop_);
    t = a / b;
    return t;
}

Money operator/(const Money& left, double arg) {
    Money t;
    double t2;
    t2 = ((left.rub_ * 100 + left.kop_) / arg) / 100;
    t.rub_ = (int)t2;
    t.kop_ = (t2 - (int)t2) * 100;
    return t;
}

Money operator*(const Money& left, double arg) {
    Money t;
    double t2;
    t2 = ((left.rub_ * 100 + left.kop_) * arg);
    t.rub_ = (int)(t2 / 100);
    t.kop_ = (t2 / 100 - (int)(t2 / 100)) * 100;
    return t;
}

bool Money::operator==(const Money& other) {
    return (this->rub_ == other.rub_ && this->kop_ == other.kop_);
}

bool Money::operator>(const Money& other) {
    return (this->rub_ > other.rub_ || (this->rub_ == other.rub_ && this->kop_ > other.kop_));
}

bool Money::operator<(const Money& other) {
    return (this->rub_ < other.rub_ || (this->rub_ == other.rub_ && this->kop_ < other.kop_));
}

bool Money::operator<=(const Money& other) {
    return (this->rub_ <= other.rub_ && this->kop_ <= other.kop_);
}

bool Money::operator>=(const Money& other) {
    return (this->rub_ >= other.rub_ && this->kop_ >= other.kop_);
}

bool Money::operator!=(const Money& other) {
    return (this->rub_ != other.rub_ || this->kop_ !=other.kop_);
}

std::istream& operator>>(std::istream& is, Money& m)
{
    is >> m.rub_ >> m.kop_;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
    os << m.rub_ << ",";
    if(m.kop_ <= 0) {
        os << "00" << std::endl;
    }
    else os << m.kop_ << std::endl;
    return os;
}

long double operator""_toCop(long double cop) {
    return (cop / 100);
}

Money::~Money() {}