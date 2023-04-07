#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->index = 0;
}

void PhoneBook::add() {
	std::string a, b, c, d, e;

	if (this->index == 8) {
		for (int i = 1; i < 8; i++)
			this->contacts[i - 1] = this->contacts[i];
		index--;
	}

	std::cin >> a >> b >> c >> d >> e;
	this->contacts[index].set_first_name(a);
	this->contacts[index].set_last_name(b);
	this->contacts[index].set_nickname(c);
	this->contacts[index].set_phone_number(d);
	this->contacts[index].set_secret(e);

	this->index++;
}

std::string PhoneBook::set_format(std::string s) {
	int len = s.length();

	if (len > 10) {
		s[9] = '.';
		s.erase(10);
	}
	else if (len < 10) {
		s.insert(0, 10 - len, ' ');
	}

	return s;
}

void PhoneBook::search() {
	int i;

	if (this->index == 0) {
		std::cout << "No contact" << std::endl;
		return;
	}

	while (1) {
		std::cout << "Choose index number(1 ~ 8) : ";
		std::cin >> i;

		if (i < 1 || i > 8 || this->index < i)
			std::cout << "Wrong index. Try again." << std::endl;
		else 
			break;
	}

	i--;

	std::string first_name = this->contacts[i].get_first_name();
	std::string last_name = this->contacts[i].get_last_name();
	std::string nickname = this->contacts[i].get_nickname();

	first_name = set_format(first_name);
	last_name = set_format(last_name);
	nickname = set_format(nickname);

	std::cout << "         " << i + 1<< "|" << first_name << "|" << last_name << "|" << nickname << std::endl;
}
