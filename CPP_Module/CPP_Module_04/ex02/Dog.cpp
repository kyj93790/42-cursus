/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2023/01/09 22:46:49 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "[Dog] Default constructor called\n";
	brain = new Brain();
	brain->fill("I love my owner");
}

Dog::Dog(const Dog& dog) {
	std::cout << "[Dog] Copy constructor called\n";
	this->brain = NULL;
	(*this) = dog;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called\n";
	delete brain;
}

const Dog& Dog::operator=(const Dog& dog) {
	type = dog.type;
	if (this != &dog) {
		if (this->brain) {
			delete this->brain;
		}
		this->brain = new Brain();
		this->brain->fill(dog.brain->getIdea());
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "[Dog] Woof! Woof!\n";
}

void Dog::think(std::string idea) {
	brain->fill(idea);
}

void Dog::say() const {
	std::cout << brain->getIdea() << '\n';
}
	