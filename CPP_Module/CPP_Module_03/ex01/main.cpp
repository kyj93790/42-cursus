/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/07/13 13:49:10 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap yejikim("yejikim");
	
	yejikim.attack("winter");
	yejikim.guardGate();
	for (int i=0; i<5; i++) {
		yejikim.takeDamage(30);
		yejikim.beRepaired(1);
	}
	yejikim.guardGate();
	return (0);
}