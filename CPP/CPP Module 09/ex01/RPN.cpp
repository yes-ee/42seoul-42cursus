#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(const RPN& ref) {
    this->s = ref.s;
}

RPN& RPN::operator=(const RPN& ref) {
    if (this != &ref) {
        this->s = ref.s;
    }
    return *this;
}

void RPN::calculate(char *str) {
    while(*str) {
        char c = *str;
        str++;

        if (c == ' ')
            continue;
        
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (s.size() < 2)
                throw std::runtime_error("Error: bad expression");

            double num2 = s.top();
            s.pop();
            double num1 = s.top();
            s.pop();

            if (c == '+') {
                double res = num1 + num2;
                s.push(res);
            }
            else if (c == '-') {
                double res = num1 - num2;
                s.push(res);
            }
            else if (c == '*') {
                double res = num1 * num2;
                s.push(res);
            }
            else {
                if (num2 == 0)
                    throw std::runtime_error("Error: divide by 0");
                double res = num1 / num2;
                s.push(res);
            }
        }
        else if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } 
        else {
            throw std::runtime_error("Error: wrong input");
        }
    }

    if (s.size() != 1)
        throw std::runtime_error("Error: bad expression");
    
    std::cout << s.top() << std::endl;
}
