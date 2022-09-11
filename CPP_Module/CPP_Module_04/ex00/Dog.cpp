/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 16:36:34 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Default constructor called\n";
}

Dog::Dog(const Dog& dog) {
	std::cout << "[Dog] Copy constructor called\n";
	*this = dog;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called\n";
}

const Dog& Dog::operator=(const Dog& dog) {
	type = dog.type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "[Dog] Woof! Woof!\n";
}