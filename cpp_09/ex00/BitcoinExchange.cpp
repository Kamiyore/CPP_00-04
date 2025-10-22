#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {
    this->loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& srcs) {
    if (this != &srcs) {
        this->_data = srcs._data;
    }
    return *this;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) {

    if (dateStr.length() != 10) return false;
    if (dateStr[4] != '-' || dateStr[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(dateStr[i])) return false;
    }
    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    if (month < 1 || month > 12) 
        return false;
    if (day < 1) 
        return false;

    if (month == 2) {
        if (isLeap(year)) {
            if (day > 29) return false;
        } else {
            if (day > 28) return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    } else {
        if (day > 31) return false;
    }
    return true;
}

// loads the database
void BitcoinExchange::loadDatabase(const std::string& dbPath) {
    std::ifstream dbFile(dbPath.c_str());
    if (!dbFile.is_open()) {
        throw std::runtime_error("Fatal: Database file could not be opened.");
    }
    std::string line;
    std::getline(dbFile, line);
    while (std::getline(dbFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos || commaPos == 0 || commaPos == line.length() - 1) {
            continue;
        }
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        
        char* end = NULL;
        float rate = std::strtof(rateStr.c_str(), &end);
        if (*end == '\0') {
            this->_data[date] = rate;
        }
    }
}

void BitcoinExchange::validateValue(const std::string& valueStr) {
    char* end = NULL;
    float value = std::strtof(valueStr.c_str(), &end);
    if (end == valueStr.c_str() || *end != '\0') {
        throw std::runtime_error("not a valid number.");
    }
    if (value < 0) {
        throw std::runtime_error("not a positive number.");
    }
    if (value > 1000) {
        throw std::runtime_error("too large a number.");
    }
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    if (inputFile.peek() == EOF) {
        throw std::runtime_error("file is empty.");
    }
    std::string line;
    std::getline(inputFile, line); 
    if (line != "date | value")
        std::cerr << "Error: Invalid file header. Expected 'date | value'." << std::endl;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            std::cerr << "Error: line is empty" << std::endl;
            continue;
        }
        size_t separatorPos = line.find(" | ");
        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = line.substr(0, separatorPos);
        std::string valueStr = line.substr(separatorPos + 3);
        if (!isValidDate(dateStr)) {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        try {
            validateValue(valueStr);
            float value = std::strtof(valueStr.c_str(), NULL);
            std::map<std::string, float>::iterator it = this->_data.upper_bound(dateStr); 
            if (it == this->_data.begin()) {
                 if(this->_data.empty() || dateStr < this->_data.begin()->first){
                     throw std::runtime_error("no data for this date.");
                 }
                 it = this->_data.begin();
            } else {
                 --it; 
            }
             if (this->_data.empty()){
                 throw std::runtime_error("database is empty.");
            }
            float exchangeRate = it->second;
            float result = value * exchangeRate;
            if (result > static_cast<float>(INT_MAX)|| result < static_cast<float>(INT_MIN)) {
                std::cerr << "Error: calculated result exceeds INT." << std::endl;
                continue; 
            }
            std::cout << dateStr << " => " << valueStr << " = ";
            if (std::fmod(result, 1.0f) == 0.0f) { 
                std::cout << static_cast<int>(result) << std::endl; 
            } else {
                std::ostringstream oss;
                oss << std::setprecision(7) << result; 
                std::cout << oss.str() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

//We use upper bond because it will always find a number bigger than it, lower bond can find the same number or bigger, 
//so we would have to implement when to di --it and when no. With upper we can do it always.
