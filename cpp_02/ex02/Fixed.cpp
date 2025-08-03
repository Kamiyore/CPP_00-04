#include "Fixed.hpp"

//ex02
bool Fixed::operator>(const Fixed& other)const
{
    return(_fixed_number > other._fixed_number);
}
bool Fixed::operator<(const Fixed& other)const
{
    return(_fixed_number < other._fixed_number);
}
bool Fixed::operator>=(const Fixed& other)const
{
    return(_fixed_number >= other._fixed_number);
}
bool Fixed::operator<=(const Fixed& other)const
{
    return(_fixed_number<=other._fixed_number);
}
bool Fixed::operator==(const Fixed& other)const
{
    return(_fixed_number==other._fixed_number);
}
bool Fixed::operator!=(const Fixed& other)const
{
    return(_fixed_number!=other._fixed_number);
}
Fixed Fixed::operator+(const Fixed& other)const
{
    int result =_fixed_number + other._fixed_number;
    Fixed plus;
    plus.setRawBits(result);
    return(plus);

}
Fixed Fixed::operator-(const Fixed& other)const
{
    int result = _fixed_number - other._fixed_number;
    Fixed minus;
    minus.setRawBits(result);
    return minus;
}
Fixed Fixed::operator*(const Fixed& other)const
{
    float result= this->toFloat() *other.toFloat();
    return Fixed(result);
}
Fixed Fixed::operator/(const Fixed& other)const
{
    float result = this->toFloat()/other.toFloat();
    return Fixed(result);

}
Fixed& Fixed::operator++()
{
    this->_fixed_number++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixed_number++;
    return temp;
}
Fixed& Fixed::operator--()
{
    this->_fixed_number--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixed_number--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a._fixed_number > b._fixed_number)
    return b;
    else
    return a;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a._fixed_number > b._fixed_number)
    return a;
    else
    return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a._fixed_number > b._fixed_number)
    return b;
    else
    return a;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a._fixed_number > b._fixed_number)
    return a;
    else
    return b;
}
//

 Fixed::Fixed() : _fixed_number(0)
{
    std::cout<<"Default constructor called"<< "\n";
}

 Fixed::Fixed(const Fixed& original)
 {
    std::cout<<"Copy constructor called"<< "\n";
    _fixed_number = original._fixed_number;
 }

 Fixed& Fixed::operator=(const Fixed& original)
 {
    std::cout<<"Copy assignment operator called"<< "\n";
    _fixed_number = original.getRawBits();
    return *this;
 }

Fixed::Fixed(const int integer) : _fixed_number(integer * (1 <<_bits))
{
    std::cout<<"Int constructor called"<<"\n";

}
Fixed::Fixed(const float floating_point) : _fixed_number(roundf(floating_point * (1 <<_bits)))
{
   std::cout<<"Float constructor called"<<"\n";
}


 Fixed::~Fixed()
 {
    std::cout<< "Destructor called"<<std::endl;
 }

 int Fixed::getRawBits(void) const
 {
    std::cout<<"getRawBits member function called"<< "\n";
    return _fixed_number;
 }
 
 void Fixed::setRawBits(int const raw)
 {
    this->_fixed_number = raw;
 }

int Fixed::toInt(void)const
{
    return this->_fixed_number / (1 << Fixed::_bits);
}

float Fixed::toFloat(void)const
{
     return static_cast<float>(this->_fixed_number) / (1 << Fixed::_bits);
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point)
{
    os << fixed_point.toFloat();
    return os;
}
