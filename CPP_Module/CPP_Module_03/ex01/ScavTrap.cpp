/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:51:50 by yejin             #+#    #+#             */
/*   Updated: 2022/07/13 13:48:45 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("anonymous", 100, 50, 20)
{
	std::cout << "[ScavTrap] Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "[ScavTrap] Constructor with name called\n";
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap)
{
	std::cout << "[ScavTrap] Copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called\n";
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_attackDamage = scavtrap._attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap can't attack : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "ScavTrap can't attack : lack of energy\n";
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void ScavTrap::guardGate()
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap can't be in keeper mode : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "ScavTrap can't be in keeper mode : lack of energy\n";
	else
		std::cout << _name << ": I'm now in keeper mode\n";
}