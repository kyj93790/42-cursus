/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:37:32 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 01:03:25 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "zombieHorde: refused\n";
		return (NULL);
	}
	Zombie *zombies = new Zombie[N];
	for (int i=0; i<N; i++)
		zombies[i].setName(name);
	return (zombies);
}