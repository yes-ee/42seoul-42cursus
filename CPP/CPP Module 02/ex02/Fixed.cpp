/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:11:22 by yeselee           #+#    #+#             */
/*   Updated: 2023/05/02 06:18:30 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->value = 0;
}

Fixed::Fixed(const int num) {
	this->value = num << this->fraction;
}

Fixed::Fixed(const float num) {
	this->value = roundf(num * (1 << this->fraction));
}

Fixed& Fixed::operator=(const Fixed& fix) {
	if (this != &fix)
		this->value = fix.value;
	return *this;
}

Fixed::Fixed(const Fixed& fix) {
	this->value = fix.value;
}

Fixed::~Fixed() {
}

std::ostream& operator<<(std::ostream& out, const Fixed& fix) {
	out << fix.toFloat();
	return out;
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

int Fixed::toInt() const {
	return this->value >> this->fraction;
}

float Fixed::toFloat() const {
	return (float)this->value / (1 << this->fraction);
}

bool Fixed::operator==(const Fixed &fix) const {
	return (this->getRawBits() ==  fix.getRawBits());
}

bool Fixed::operator!=(const Fixed &fix) const {
	return (this->getRawBits() != fix.getRawBits());
}

bool Fixed::operator<(const Fixed& fix) const {
	return (this->getRawBits() < fix.getRawBits());
}

bool Fixed::operator>(const Fixed& fix) const {
	return (this->getRawBits() > fix.getRawBits());
}

bool Fixed::operator<=(const Fixed& fix) const {
	return (this->getRawBits() <= fix.getRawBits());
}

bool Fixed::operator>=(const Fixed& fix) const {
	return (this->getRawBits() >= fix.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fix) const {
	Fixed ret(this->toFloat() + fix.toFloat());
	return ret;
}

Fixed Fixed::operator-(const Fixed& fix) const {
	Fixed ret(this->toFloat() - fix.toFloat());
	return ret;
}

Fixed Fixed::operator*(const Fixed& fix) const {
	Fixed ret(this->toFloat() * fix.toFloat());
	return ret;
}

Fixed Fixed::operator/(const Fixed& fix) const {
	Fixed ret(this->toFloat() / fix.toFloat());
	return ret;
}

Fixed& Fixed::operator++() {
	this->value++;
	return (*this);
}

Fixed& Fixed::operator--() {
	this->value--;
	return (*this);
}

const Fixed Fixed::operator++(int) {
	const Fixed ret(*this);
	this->value++;
	return ret;
}

const Fixed Fixed::operator--(int) {
	const Fixed ret(*this);
	this->value--;
	return ret;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}
