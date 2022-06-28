/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:26:21 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 00:34:03 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(void)
{
	Zombie *yejikim = newZombie("yejikim");
	Zombie *mcha = newZombie("mcha");

	randomChump("yongjule");
	randomChump("jiskim");
	randomChump("ghan");

	delete yejikim;
	delete mcha;
	return (0);
}