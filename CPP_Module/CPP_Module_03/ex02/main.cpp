/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/07/13 14:52:09 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FrapTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap yejikim("yejikim");
	FragTrap karina("karina");
	
	yejikim.attack("winter");
	yejikim.guardGate();
	for (int i=0; i<5; i++) {
		yejikim.takeDamage(30);
		yejikim.beRepaired(1);
	}
	yejikim.guardGate();
	std::cout << '\n';
	
	karina.attack("winter");
	karina.highFivesGuys();
	for (int i=0; i<5; i++) {
		karina.takeDamage(30);
		karina.beRepaired(1);
	}
	karina.highFivesGuys();
	return (0);
}