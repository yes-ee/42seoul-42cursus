#ifndef RPN_HPP
# define RPN_HPP

# include <map>
# include <string>
# include <stdexcept>
# include <iostream>
# include <stack>

class RPN {
	private:
        std::stack<double> s;
	public:
		RPN();
		~RPN();
		RPN(const RPN& ref);
		RPN& operator=(const RPN& ref);

        void calculate(char *str);
};

#endif