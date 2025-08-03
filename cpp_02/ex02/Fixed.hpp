#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
    int _fixed_number;
    static const int _bits = 8;
    public:
    Fixed();
    Fixed(const Fixed& original);
    Fixed& operator = (const Fixed& original);
    Fixed(const int integer);
    Fixed(const float floating_point);
    ~Fixed();
//ex02
    bool operator>(const Fixed& other)const;
    bool operator<(const Fixed& other)const;
    bool operator>=(const Fixed& other)const;
    bool operator<=(const Fixed& other)const;
    bool operator==(const Fixed& other)const;
    bool operator!=(const Fixed& other)const;
    Fixed operator+(const Fixed& other)const;
    Fixed operator-(const Fixed& other)const;
    Fixed operator*(const Fixed& other)const;
    Fixed operator/(const Fixed& other)const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min (const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
//
    void setRawBits(int const raw);
    int getRawBits(void) const;
    int toInt(void) const;
    float toFloat(void) const;

};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point);
 #endif
