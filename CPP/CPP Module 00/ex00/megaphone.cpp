/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:01:13 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/10 22:01:15 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	(void)argv;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
	}
	std::cout << std::endl;

	return 0;
}