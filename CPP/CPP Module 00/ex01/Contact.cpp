/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:47:11 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/12 22:21:39 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(std::string first_name) {
	this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name) {
	this->last_name = last_name;
}
void Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number) {
	this->phone_number = phone_number;
}
void Contact::set_secret(std::string secret) {
	this->secret = secret;
}
std::string Contact::get_first_name() {
	return this->first_name;
}
std::string Contact::get_last_name() {
	return this->last_name;
}
std::string Contact::get_nickname() {
	return this->nickname;
}
std::string Contact::get_phone_number() {
	return this->phone_number;
}
std::string Contact::get_secret() {
	return this->secret;
}
