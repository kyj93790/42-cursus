/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 13:23:30 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	char temp[10];
	
	DiamondTrap yejikim("yejikim");
	std::cout << '\n';
	std::cin.getline(temp, 1);

	yejikim.whoAmI();
	yejikim.highFivesGuys();
	yejikim.attack("karina");
	yejikim.guardGate();
	std::cout << '\n';
	std::cin.getline(temp, 1);

	for (int i=0; i<3; i++) {
		yejikim.takeDamage(3);
		yejikim.beRepaired(1);
		std::cout << '\n';
		std::cin.getline(temp, 1);
	}
	yejikim.guardGate();
	std::cout << '\n';
	return (0);
}