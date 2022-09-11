/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:41:24 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 16:53:37 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
	char temp[10];
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	std::cout << "-----------------compare-----------------\n";
	std::cout << '\n';
	std::cin.getline(temp, 1);

	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongCat();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	std::cout << b->getType() << " " << std::endl;
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	a->makeSound();
	b->makeSound();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	return 0;
}