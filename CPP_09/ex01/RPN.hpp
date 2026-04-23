#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>

class RPN {

    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &src);
        ~RPN();

        int evaluate(const std::string &expr);

};

#endif
