/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:26:21 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 01:06:56 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(void)
{
	int N = 5;
	Zombie *zombies = zombieHorde(N, "anonymous");
	for (int i=0; i<N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}