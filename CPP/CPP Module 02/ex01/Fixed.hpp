/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:02:39 by yeselee           #+#    #+#             */
/*   Updated: 2023/05/02 06:07:46 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int value;
		const static int fraction = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& fix);	//복사생성자
		Fixed& operator=(const Fixed& fix);	//복사 대입 연산자
		Fixed(const int num);
		Fixed(const float num);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

};

std::ostream& operator << (std::ostream& out, const Fixed& fix);

#endif