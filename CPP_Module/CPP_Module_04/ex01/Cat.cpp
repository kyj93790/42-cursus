/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2022/09/12 11:51:19 by yejin            ###   ########.fr       */
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
	type = cat.type;
	brain = new Brain();
	for (int i=0; i<100; i++) brain[i] = cat.brain[i];
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called\n";
	delete brain;
}

const Cat& Cat::operator=(const Cat& cat) {
	type = cat.type;
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