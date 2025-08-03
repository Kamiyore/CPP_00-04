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
    ~Fixed();
//ex1
    Fixed(const int integer);
    Fixed(const float floating_point);
    int toInt(void) const;
    float toFloat(void) const;
//
    void setRawBits(int const raw);
    int getRawBits(void) const;


};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point);
#endif
