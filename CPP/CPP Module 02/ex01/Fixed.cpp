/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:02:47 by yeselee           #+#    #+#             */
/*   Updated: 2023/05/02 06:10:13 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->fraction;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->fraction));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fix.value;
}

Fixed& Fixed::operator=(const Fixed& fix) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fix)
		this->value = fix.value;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

int Fixed::toInt() const {
	return (this->value >> this->fraction);
}

float Fixed::toFloat() const {
	return (float)this->value / (1 << this->fraction);
}

std::ostream& operator << (std::ostream& out, const Fixed& fix) {
	out << fix.toFloat();
	return out;
}
