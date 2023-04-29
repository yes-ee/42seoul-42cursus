/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:44:51 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/19 02:53:05 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. " << std::endl << "I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl << "You didn’t put enough bacon in my burger! " << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	int index = 4;
	std::string lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == lv[i]) {
			index = i;
			break;
		}
	}

	switch (index)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
