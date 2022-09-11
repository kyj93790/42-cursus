/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:05:17 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 16:47:54 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "[WrongAnimal] Default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "[WrongAnimal] Constructor with type called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
	std::cout << "[WrongAnimal] Copy constructor called\n";
	(*this) = a;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] Destructor called\n";
}

const WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
	type = a.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "[WrongAnimal] How can I make sound ?\n"; 
}

const std::string WrongAnimal::getType() const {
	return (type);
}