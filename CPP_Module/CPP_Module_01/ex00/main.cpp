/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:26:21 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 00:48:53 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(void)
{
	Zombie *yejikim = newZombie("yejikim");
	yejikim->announce();
	Zombie *mcha = newZombie("mcha");
	mcha->announce();

	randomChump("yongjule");
	randomChump("jiskim");
	randomChump("ghan");

	delete yejikim;
	delete mcha;
	return (0);
}