#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>

class Fixed
{
    private:
    int _fixed_number;
    static const int _bits = 8;
    public:
    Fixed();
    Fixed(const Fixed& original); //copy constructor
    Fixed& operator= (const Fixed& original); //assignment, it needs the =
    ~Fixed();
    void setRawBits(int const raw);
    int getRawBits(void) const;
};
//copy constructor is used when I am creating completely new object based on another object
// assigment operater is used when I am replacing values  of already existing object
//Fixed(const Fixed& original); because reference changes the value in the original, we put here const to make sure the values in original wont change.
#endif
