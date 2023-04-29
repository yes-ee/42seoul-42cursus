/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:54:34 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/19 00:40:39 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

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