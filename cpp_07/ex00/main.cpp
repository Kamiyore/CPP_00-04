#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::cout << "Original values: a = " << a << ", b = " << b << std::endl;
::swap( a, b );
std::cout << "Swapped values: a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "dog";
std::string d = "cat";
std::cout << "Original values: c = " << c << ", d = " << d << std::endl;
::swap(c, d);
std::cout << "Swapped values: c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

char e = 'e';
char f = 'E';
std::cout << "Original values: e = " << e << ", f = " << f << std::endl;
::swap( e, f );
std::cout << "Swapped values: e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
return 0;
}
