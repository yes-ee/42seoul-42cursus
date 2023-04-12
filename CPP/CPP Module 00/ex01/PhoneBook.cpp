/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:46:30 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/12 23:29:17 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->index = 0;
}

void PhoneBook::add() {
	std::string a, b, c, d, e;
	std::string tmp;

	std::getline(std::cin, tmp);

	if (this->index == 8) {
		for (int i = 1; i < 8; i++)
			this->contacts[i - 1] = this->contacts[i];
		index--;
	}

	std::cout << "(" << this->index + 1 <<") first name, last name, nickname, phone number, darkest secret" << std::endl;
	std::cin >> a >> b >> c >> d >> e;
	std::getline(std::cin, tmp);

	if (std::cin.eof())
		return;
	if (d.length() != 11) {
		std::cout << "Wrong input" << std::endl;
		return;
	}
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
	return s;
}

void PhoneBook::search() {
	int i;
	std::string l;
	std::string tmp;

	std::getline(std::cin, tmp);

	if (this->index == 0) {
		std::cout << "No contact" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "firstname" << "|" << std::setw(10) << "lastname" << "|" <<std::setw(10) << "nickname" << std::endl;


	for (int i = 0; i < index; i++) {
		std::string first_name = this->contacts[i].get_first_name();
		std::string last_name = this->contacts[i].get_last_name();
		std::string nickname = this->contacts[i].get_nickname();

		std::cout << std::setw(10) << i + 1 << "|" << std::setw(10) << set_format(first_name) << "|" << std::setw(10) << set_format(last_name) << "|" <<std::setw(10) << set_format(nickname) << std::endl;
	}

	while (1) {
		std::cout << "Choose index number(1 ~ 8) : ";
		std::cin >> l;

		if (std::cin.eof())
			return;

		if (l.length() != 1)
			std::cout << "Wrong index. Try again." << std::endl;
		else {
			try {
				i = stoi(l);
				if (i < 1 || i > 8 || index < i)
					std::cout << "Wrong index. Try again." << std::endl;
				else
					break;
			}
			catch (...) {
				std::cout << "Wrong index. Try again." << std::endl;
			}
		}
		std::getline(std::cin, tmp);
	}

	i--;

	std::string first_name = this->contacts[i].get_first_name();
	std::string last_name = this->contacts[i].get_last_name();
	std::string nickname = this->contacts[i].get_nickname();
	std::string phone_number = this->contacts[i].get_phone_number();
	std::string secret = this->contacts[i].get_secret();

	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone number : " << phone_number << std::endl;
	std::cout << "darkest secret : " << secret << std::endl;
}
