/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:18:03 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/19 02:47:24 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl harl;

	if (argc != 2) {
		std::cout << "Wrong argument" << std::endl;
		return 1;
	}

	harl.complain(argv[1]);

	return 0;

}