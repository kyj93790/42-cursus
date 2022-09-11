/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 16:38:08 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "[Cat] Default constructor called\n";
}

Cat::Cat(const Cat& cat) {
	std::cout << "[Cat] Copy constructor called\n";
	*this = cat;
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called\n";
}

const Cat& Cat::operator=(const Cat& cat) {
	type = cat.type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "[Cat] Meow~ Meow~\n";
}