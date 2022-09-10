/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:14:18 by yejin             #+#    #+#             */
/*   Updated: 2022/09/10 17:25:35 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("anonymous_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "[DiamondTrap] " << _name << " : Default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "[DiamondTrap] " << _name << " : Constructor with name called\n";
	std::cout << "Set hitPoints : " << _hitPoints << '\n';
	std::cout << "Set energyPoints : " << _energyPoints << '\n';
	std::cout << "Set attackDamage : " << _attackDamage << '\n';
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "[DiamondTrap] " << _name << " : Copy constructor called\n";
	(*this) = diamondtrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << _name << " : Destructor called\n";
}

const DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
	ClapTrap::_name = diamondtrap.ClapTrap::_name;
	_name = diamondtrap._name;
	_hitPoints = diamondtrap._hitPoints;
	_energyPoints = diamondtrap._energyPoints;
	_attackDamage = diamondtrap._attackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] my name : " << _name << ", my ClapTrap name : " << ClapTrap::_name << '\n';
}