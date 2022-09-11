/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:42:15 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 16:47:36 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "[WrongCat] Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& c) {
	std::cout << "[WrongCat] Copy constructor called\n";
	*this = c;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called\n";
}

const WrongCat& WrongCat::operator=(const WrongCat& c) {
	type = c.type;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "[WrongCat] Meow~ Meow~\n";
}