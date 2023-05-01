/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:11:36 by yeselee           #+#    #+#             */
/*   Updated: 2023/05/02 05:30:18 by yeselee          ###   ########.fr       */
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
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fix);	//복사생성자
		Fixed& operator=(const Fixed& fix);	//복사 대입 연산자
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		bool operator==(const Fixed& fix) const;
		bool operator!=(const Fixed& fix) const;
		bool operator<(const Fixed& fix) const;
		bool operator>(const Fixed& fix) const;
		bool operator<=(const Fixed& fix) const;
		bool operator>=(const Fixed& fix) const;
		Fixed operator+(const Fixed& fix) const;
		Fixed operator-(const Fixed& fix) const;
		Fixed operator*(const Fixed& fix) const;
		Fixed operator/(const Fixed& fix) const;
		Fixed& operator++();	//전위 연산자
		Fixed& operator--();	//전위 연산자
		const Fixed operator++(int);	//후위 연산자
		const Fixed operator--(int);	//후위 연산자
		static Fixed& min(Fixed& f1, Fixed& f2);
		const static Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		const static Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator << (std::ostream& out,const Fixed& fix);

#endif