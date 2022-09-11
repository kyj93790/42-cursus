/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/09/11 13:29:20 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	char temp[10];
	ClapTrap yejikim("yejikim");
	std::cout << '\n';
	std::cin.getline(temp, 1);
	
	yejikim.attack("karina");
	for (int i=0; i<5; i++) {
		yejikim.takeDamage(3);
		yejikim.beRepaired(1);
		std::cout << '\n';
		std::cin.getline(temp, 1);
	}
	return (0);
}