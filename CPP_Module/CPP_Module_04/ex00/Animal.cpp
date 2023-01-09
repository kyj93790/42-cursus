/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:05:17 by yejin             #+#    #+#             */
/*   Updated: 2023/01/09 22:50:54 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << "[Animal] Default constructor called\n";
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "[Animal] Constructor with type called\n";
}

Animal::Animal(const Animal& animal) {
	std::cout << "[Animal] Copy constructor called\n";
	(*this) = animal;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called\n";
}

const Animal& Animal::operator=(const Animal& animal) {
	type = animal.type;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "[Animal] How can I make sound ?\n"; 
}

const std::string Animal::getType() const {
	return (type);
}