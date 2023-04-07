#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		Contact contacts[8];
		int index;
	public:
		PhoneBook();
		void add();
		void search();
		std::string set_format(std::string s);
};

#endif