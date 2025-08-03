 #include "Fixed.hpp"
 
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


