/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:41:24 by yejin             #+#    #+#             */
/*   Updated: 2023/01/09 22:48:44 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void) {
	char temp[10];
	
	std::cout << "----- Up Casting (virtual) -----\n\n";

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	delete j;
	delete i;
	std::cout << '\n';
	std::cin.getline(temp, 1);

	std::cout << "----- Function -----\n\n";

	Animal *animals[10];
	
	for (int i=0; i<5; i++) animals[i] = new Dog();
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	for (int i=5; i<10; i++) animals[i] = new Cat();
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	for (int i=0; i<5; i++) animals[i]->say();
	for (int i=5; i<10; i++) animals[i]->say();
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	for (int i=0; i<10; i++) delete animals[i];
	std::cout << '\n';
	std::cin.getline(temp, 1);

	std::cout << "----- Deep Copy in copy constructor -----\n\n";
	Cat a;
	a.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	Cat b(a);
	b.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	b.think("I'm thinking differently");
	b.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	a.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	std::cout << "----- Deep Copy in copy assignment -----\n\n";

	Cat c;
	c = b;
	c.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	c.think("ccccccc");
	c.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	b.say();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	return 0;
}