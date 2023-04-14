/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:58:19 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/14 23:18:34 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *horde = zombieHorde(5, "zom");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}
