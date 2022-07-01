/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:26:21 by yejin             #+#    #+#             */
/*   Updated: 2022/07/01 12:27:36 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(void)
{
	int N = 5;
	Zombie *zombies = zombieHorde(N, "friend");
	for (int i=0; i<N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}