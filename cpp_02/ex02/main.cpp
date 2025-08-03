#include "Fixed.hpp"

int main( void )
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << "--- Testing + - * / ---" << std::endl;

    Fixed c(10);
    Fixed d(3.5f);

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    std::cout << "c + d: " << (c + d) << std::endl; // 10 + 3.5
    std::cout << "c - d: " << (c - d) << std::endl; // 10 - 3.5
    std::cout << "c * d: " << (c * d) << std::endl; // 10 * 3.5
    std::cout << "c / d: " << (c / d) << std::endl; // 10 / 3.5

    std::cout << std::endl;

    std::cout << "--- Testing < > <= >= != == ---" << std::endl;

    Fixed e(5);
    Fixed f(5);
    Fixed g(7);

    std::cout << "e: " << e << ", f: " << f << ", g: " << g << std::endl;

    std::cout << "e == f: " << (e == f ? "True" : "False") << std::endl;
    std::cout << "e != g: " << (e != g ? "True" : "False") << std::endl;
    std::cout << "e < g: " << (e < g ? "True" : "False") << std::endl;
    std::cout << "g < f: " << (g < f ? "True" : "False") << std::endl; //false
    std::cout << "g > f: " << (g > f ? "True" : "False") << std::endl;
    std::cout << "e <= f: " << (e <= f ? "True" : "False") << std::endl;
    std::cout << "g >= e: " << (g >= e ? "True" : "False") << std::endl;

    std::cout << std::endl;

 
    std::cout << "--- Tests min/max (no-const) ---" << std::endl;
    Fixed h(15.2f);
    Fixed i(12.8f);
    std::cout << "h: " << h << ", i: " << i << std::endl;
    std::cout << "Min(h, i): " << Fixed::min(h, i) << std::endl;
    std::cout << "Max(h, i): " << Fixed::max(h, i) << std::endl;


    std::cout << "--- Tests min/max (const) ---" << std::endl;
    const Fixed j(20.5f);
    const Fixed k(18.0f);
    std::cout << "j: " << j << ", k: " << k << std::endl;
    std::cout << "Min(j, k): " << Fixed::min(j, k) << std::endl;
    std::cout << "Max(j, k): " << Fixed::max(j, k) << std::endl; 
    return 0;
}
