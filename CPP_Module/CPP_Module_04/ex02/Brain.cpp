/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:58:36 by yejin             #+#    #+#             */
/*   Updated: 2022/09/12 11:34:26 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "[Brain] Default constructor called\n";
}

Brain::Brain(const Brain& b) {
	std::cout << "[Brain] Copy constructor called\n";
	*this = b;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called\n";
}

const Brain& Brain::operator=(const Brain& b) {
	for (int i=0; i<100; i++) {
		ideas[i] = b.ideas[i];
	}
	return (*this);
}

void Brain::fill(std::string idea) {
	for (int i=0; i<100; i++) {
		ideas[i] = idea;
	}
}

std::string Brain::getIdea() const {
	return ideas[0];
}