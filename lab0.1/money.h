#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
public:
    Money();
    Money(unsigned long long rub, uint16_t kop);
    Money(const Money &other);
    Money &operator=(const Money &other);
    Money(std::istream &is);

    friend Money operator+(const Money& one, const Money &other);
    friend Money operator-(const Money& one, const Money& other);
    friend double operator/(const Money& one, const Money& other);
    friend Money operator/(const Money& one, double arg);
    friend Money operator*(const Money& one, double arg);

    bool operator==(const Money &other);
    bool operator>(const Money &other);
    bool operator<(const Money &other);
    bool operator<=(const Money &other);
    bool operator>=(const Money &other);
    bool operator!=(const Money &other);

    unsigned long long get_rub() const;
    uint16_t get_kop() const;
    
    friend std::istream &operator>>(std::istream &is, Money &m);
    friend std::ostream &operator<<(std::ostream &os, const Money &m);
    
    virtual ~Money();
private:
    unsigned long long rub_;
    uint16_t kop_;
};

#endif // MONEY_H