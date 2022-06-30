/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:36:38 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 23:40:42 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap yejikim("yejikim");
	
	yejikim.attack("mcha");
	for (int i=0; i<5; i++) {
		yejikim.takeDamage(3);
		yejikim.beRepaired(1);
	}
	return (0);
}