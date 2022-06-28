/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:02:04 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 02:45:13 by yejin            ###   ########.fr       */
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
	std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}