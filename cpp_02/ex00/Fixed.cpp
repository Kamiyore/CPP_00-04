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
