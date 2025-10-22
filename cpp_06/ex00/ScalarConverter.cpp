#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    if(literal.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if(literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if(literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    else
    {
        std::stringstream ss(literal);
        double value = 0.0;
        if(!(ss >> value))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossiblle" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        std::string remainder;
        ss >> remainder;
        if ((remainder.empty() || remainder == "f"))
        {
            if(value < 0 || value > 127 || value != value)
                std::cout << "char: impossible" << std::endl;
            else if (!std::isprint(static_cast<char>(value)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(value) << "'"<< std::endl;
            if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(value) << std::endl;
        
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << value << std::endl; 
        }
        else
        {
             std::cout << "char: impossible" << std::endl;
             std::cout << "int: impossible" << std::endl;
             std::cout << "float: impossible" << std::endl;
             std::cout << "double: impossible" << std::endl;
        }
    }
}

