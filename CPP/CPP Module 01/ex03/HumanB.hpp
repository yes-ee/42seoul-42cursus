/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:48:00 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/19 00:40:29 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif