/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:58:48 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/14 23:15:58 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *pZombies = new Zombie[N];
	
	if (!pZombies) {
		std::cout << "memory allocation failed" << std::endl;
		return 0;
	}
	
	for(int i = 0; i < N; i++)
		pZombies[i].setName(name);

	return pZombies;
}