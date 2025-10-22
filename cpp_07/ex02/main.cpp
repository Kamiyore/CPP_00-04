#include "Array.hpp"
#include <cstdlib>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }

#include <string>
#include <ctime>


int main(void)
{
    std::cout << "## 1. Test: Default Constructor " << std::endl;
    Array<int> empty_array;
    std::cout << "Size of empty array: " << empty_array.size() << '\n' << std::endl;


    std::cout << "## 2. Test: Constructor and operator[]" << std::endl;
    Array<int> numbers(10);
    std::cout << "Created array with size: " << numbers.size() << std::endl;
    srand(time(NULL));
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = rand() % 100;
    }
    std::cout << "Array 'numbers': ";
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n" << std::endl;


    std::cout << "## 3. Test: Copy Constructor" << std::endl;
    {
        Array<int> copy = numbers;
        std::cout << "Before change -> numbers[0]: " << numbers[0] << ", copy[0]: " << copy[0] << std::endl;
        
        copy[0] = 999;
        std::cout << "After change  -> numbers[0]: " << numbers[0] << ", copy[0]: " << copy[0] << std::endl <<std::endl;
    } 


    std::cout << "## 4. Test: Assignment Operator=" << std::endl;
    {
        Array<int> assigned(3);
        assigned[0] = 1; assigned[1] = 2; assigned[2] = 3;
        
        std::cout << "Before assignment: numbers[0]: " << numbers[0]<< ", numbers[1] " << numbers[1] << ", numbers[2]" << numbers[2] << std::endl;
        std::cout << "Before assignment: assigned[0]: " << assigned[0]<< ", assigned[1] " << assigned[1] << ", assigned[2]" << assigned[2] << std::endl;
        assigned = numbers;

        assigned[1] = 777;
        std::cout << "After assignment: numbers[0]: " << numbers[0]<< ", numbers[1] " << numbers[1] << ", numbers[2]" << numbers[2] << std::endl;
        std::cout << "After assignment: assigned[0]: " << assigned[0]<< ", assigned[1] " << assigned[1] << ", assigned[2]" << assigned[2] << std::endl;
    }


    std::cout << "## 5. Test: Out of Bounds Access" << std::endl;
    try
    {
        std::cout << "Trying to access numbers[" << 10 << "]..." << std::endl;
        numbers[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception successfully caught: OK" << std::endl;
    }
     try
    {
        std::cout << "Trying to access numbers[-2]..." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception successfully caught: OK" << "\n" << std::endl;
    }

    std::cout << "##6. Array string" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "world";
    words[2] = "!";
    Array<std::string> words_copy = words;
    words_copy[0] = "Hi";
    std::cout << "Original: " << words[0] << " " <<words[1] << words[2] << ", Copy: " << words_copy[0] << " "<< words_copy[1] << words_copy[2] <<'\n' << std::endl;
    
    
    std::cout << "##7 Test: Const instance access ##" << std::endl;
    const Array<int> const_numbers = numbers;
    std::cout << "Reading from const_numbers[0]: " << const_numbers[0] << ", const_numbers[1]: " << const_numbers[1] << std::endl;
    return 0;
}

