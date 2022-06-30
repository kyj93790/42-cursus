/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:11 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 23:53:25 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with name called\n";
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "Copy constructor called\n";
	(*this) = claptrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

const ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_attackDamage = claptrap._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap can't attack : discharged\n";
	else if (_energyPoints == 0)
		std::cout << "ClapTrap can't attack : lack of energy\n";
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap can't take damage : discharged\n";
	else {
		if (_hitPoints < amount) _hitPoints = 0;
		else _hitPoints -= amount;
		std::cout << "ClapTrap take damage. Total hit point is " << _hitPoints << "\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0) {
		std::cout << "ClapTrap can't be repaired : lack of energy\n";
	}
	else {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap is repaired. Total hit point is " << _hitPoints << "\n";
	}
}