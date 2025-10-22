#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


class BitcoinExchange {
private:

    std::map<std::string, float> _data;

    void loadDatabase(const std::string& dbPath);
    bool isValidDate(const std::string& dateStr);
    void validateValue(const std::string& valueStr);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    void processInputFile(const std::string& filename);
};

#endif


