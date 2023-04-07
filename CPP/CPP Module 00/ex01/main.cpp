#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string cmd;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter command : ";
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Wrong command" << std::endl;
	}

	return 0;
}
