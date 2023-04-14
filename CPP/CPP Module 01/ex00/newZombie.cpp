/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:10:06 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/14 23:46:46 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie *pZombie = new Zombie(name);
	
	if (!pZombie) {
		std::cout << "memory allocation failed" << std::endl;
		return 0;
	}
	
	return pZombie;
}
