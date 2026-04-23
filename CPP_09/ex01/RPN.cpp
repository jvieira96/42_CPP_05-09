#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) { 
    (void)copy; 
}

RPN &RPN::operator=(const RPN &src)
{
    (void)src;
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr)
{
    std::stack<int> s;

    for (size_t i = 0; i < expr.size(); i++)
    {
        char c = expr[i];
        if (c == ' ')
            continue;
        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (s.size() < 2)
                throw std::runtime_error("Error");
            int b = s.top(); 
            s.pop();
            int a = s.top(); 
            s.pop();
            if (c == '+') 
                s.push(a + b);
            else if (c == '-') 
                s.push(a - b);
            else if (c == '*') 
                s.push(a * b);
            else
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                s.push(a / b);
            }
            continue;
        }
        throw std::runtime_error("Error");
    }
    if (s.size() != 1)
        throw std::runtime_error("Error");
    return s.top();
}
