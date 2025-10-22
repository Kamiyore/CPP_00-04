#include "RPN.hpp"
#include <sstream>
#include <climits>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) {
    *this = src;
}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs) {}
    return *this;
}
// LIFO system
int RPN::evaluate(const std::string& expression) {
    std::stack<int> operandStack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (operandStack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int rs = operandStack.top(); operandStack.pop();
            int ls = operandStack.top(); operandStack.pop();

            if (token == "+") {
                if ((rs > 0 && ls > INT_MAX - rs) || (rs < 0 && ls < INT_MIN - rs)) {
                    throw std::runtime_error("Error");
                }
                operandStack.push(ls + rs);
            } 
            else if (token == "-") {
                if ((rs < 0 && ls > INT_MAX + rs) || (rs > 0 && ls < INT_MIN + rs)) {
                    throw std::runtime_error("Error");
                }
                operandStack.push(ls - rs);
            } 
            else if (token == "*") {
                if (ls == 0 || rs == 0) {
                    operandStack.push(0);
                }
                else if (rs == -1) {
                    if (ls == INT_MIN) {
                        throw std::runtime_error("Error");
                    }
                    operandStack.push(ls * -1);
                }
                else if (rs > 0) {
                    if (ls > INT_MAX / rs || ls < INT_MIN / rs) {
                        throw std::runtime_error("Error");
                    }
                    operandStack.push(ls * rs);
                }
                else {
                    if (ls < INT_MAX / rs || ls > INT_MIN / rs) {
                        throw std::runtime_error("Error");
                    }
                    operandStack.push(ls * rs);
                }
            }
            else if (token == "/") {
                if (rs == 0) {
                    throw std::runtime_error("Error");
                }
                if (ls == INT_MIN && rs == -1) {
                    throw std::runtime_error("Error");
                }
                operandStack.push(ls / rs);
            }
        }
        else if (token.length() == 1 && std::isdigit(token[0])) {
            operandStack.push(token[0] - '0');
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    if (operandStack.size() != 1) {
        throw std::runtime_error("Error");
    }
    return operandStack.top();
}
