/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:56:22 by yejin             #+#    #+#             */
/*   Updated: 2022/07/13 14:52:00 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FrapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("anonymous", 100, 100, 30)
{
	std::cout << "[FragTrap] " << _name << " : Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap] " << _name << " : Constructor with name called\n";
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap)
{
	std::cout << "[FragTrap] " << _name << " : Copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << _name << " : Destructor called\n";
}

const FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_attackDamage = fragtrap._attackDamage;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "[FragTrap] " << _name << " can't attack : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "[FragTrap] " << _name << " can't attack : lack of energy\n";
	else {
		_energyPoints--;
		std::cout << "[FragTrap] " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys()
{
	if (_hitPoints == 0)
		std::cout << "[FragTrap] " << _name << " can't request high fives : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "[FragTrap] " << _name << " can't request high fives : lack of energy\n";
	else
		std::cout << "[FragTrap] " << _name << " : Let's high fives guys !\n";
}