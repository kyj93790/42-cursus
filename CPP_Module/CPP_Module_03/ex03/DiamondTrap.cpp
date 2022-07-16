/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:14:18 by yejin             #+#    #+#             */
/*   Updated: 2022/07/16 11:02:51 by yejin            ###   ########.fr       */
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

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(diamondtrap), ScavTrap(), FragTrap()
{
	std::cout << "[DiamondTrap] " << _name << " : Copy constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << _name << " : Destructor called\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] my name : " << _name << ", my ClapTrap name : " << ClapTrap::_name << '\n';
}