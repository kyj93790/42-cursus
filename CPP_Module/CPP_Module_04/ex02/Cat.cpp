/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2023/01/09 22:46:26 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called\n";
	brain = new Brain();
	brain->fill("My servant loves me");
}

Cat::Cat(const Cat& cat) {
	std::cout << "[Cat] Copy constructor called\n";
	this->brain = NULL;
	(*this) = cat;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called\n";
	delete brain;
}

const Cat& Cat::operator=(const Cat& cat) {
	type = cat.type;
	if (this != &cat) {
		if (this->brain) {
			delete this->brain;
		}
		this->brain = new Brain();
		this->brain->fill(cat.brain->getIdea());
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "[Cat] Meow~ Meow~\n";
}

void Cat::think(std::string idea) {
	brain->fill(idea);
}

void Cat::say() const {
	std::cout << brain->getIdea() << '\n';
}