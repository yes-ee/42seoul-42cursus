/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:54:34 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/16 04:04:31 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string);
		const std::string &getType();
		void setType(std::string type);
};

#endif