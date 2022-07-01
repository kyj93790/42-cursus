/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:02:04 by yejin             #+#    #+#             */
/*   Updated: 2022/07/01 12:33:43 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : _name("anonymous"), _weapon(NULL)
{
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void) const
{
	if (_weapon == NULL) std::cout << _name << "attacks with there hand\n";
	else std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}