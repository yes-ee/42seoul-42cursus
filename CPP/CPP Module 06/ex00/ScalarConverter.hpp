#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>

class ScalarConverter {
	private:
		ScalarConverter();

	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter& operator=(const ScalarConverter& ref);

		static void convert(std::string str);
};

#endif
