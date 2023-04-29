/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:06:58 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/30 01:04:24 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int value;
		const static int fraction = 8;
	public:
		Fixed();
		Fixed(const Fixed& fix);	//복사생성자
		Fixed& operator=(const Fixed& fix);	//복사 대입 연산자
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif