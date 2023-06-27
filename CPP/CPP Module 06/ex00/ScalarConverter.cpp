#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref){
	*this = ref;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) {
	if (this != &ref) {
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

void ScalarConverter::convert(std::string str) {
	const char *s = str.c_str();
	char *end = NULL;
	int type = 1;

	double value = strtod(s, &end);
	if (value == 0 && end == s)
		type = 0;

	if ((str.length() == 0) || (type == 0 && str.length() != 1) || (end != s && end[0] != '\0' && (end[0] != 'f' || (end[0] == 'f' && end[1] != '\0')))) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (std::isnan(value) || std::isinf(value))
		std::cout << "char: impossible" << std::endl;
	else if (type == 0)
		std::cout << "char: \'" << static_cast<char>(end[0]) << "\'" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(value) << "\'" << std::endl;

	if (std::isnan(value) || std::isinf(value) || value > 2147483647 || value < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else if (type == 0)
		std::cout << "int: " << static_cast<int>(end[0]) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << static_cast<float>(value)  << "f" << std::endl;
	else if (type == 0)
		std::cout << "float: " << static_cast<float>(end[0]) << ".0f" << std::endl;
	else if (static_cast<int>(value) == value)
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

	if (std::isnan(value) || std::isinf(value))
		std::cout << "double: " << value << std::endl;
	else if (type == 0)
		std::cout << "double: " << static_cast<double>(end[0]) << ".0" << std::endl;
	else if (static_cast<int>(value) == value)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}