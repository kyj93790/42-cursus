/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/07/16 11:02:59 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap yejikim("yejikim");
	
	yejikim.whoAmI();
	yejikim.highFivesGuys();
	yejikim.attack("karina");
	yejikim.guardGate();
	std::cout << '\n';
	for (int i=0; i<3; i++) {
		yejikim.takeDamage(3);
		yejikim.beRepaired(1);
	}
	yejikim.guardGate();
	std::cout << '\n';
	return (0);
}