/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:45:35 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/11 00:26:25 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string cmd;
	std::string tmp;
	PhoneBook phonebook;

	while (!std::cin.eof())
	{
		std::cout << "Enter command(ADD, SEARCH, EXIT) : ";
		std::cin >> cmd;

		if (std::cin.eof())
			break;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
		else {
			std::cout << "Wrong command" << std::endl;
			std::getline(std::cin, tmp);
		}
	}

	return 0;
}
