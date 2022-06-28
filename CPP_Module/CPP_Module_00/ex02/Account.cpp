/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:17:52 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/28 18:15:32 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

static void printTime()
{
	std::time_t t = std::time(NULL);
	if (t == (time_t)(-1))
	{
		std::cout << "ERROR : time()\n";
		exit(EXIT_FAILURE);
	}
	char timestamp[16];
	if (std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", localtime(&t)) == 0) {
		std::cout << "ERROR : time()\n";
		exit(EXIT_FAILURE);
	}
	std::cout << '[' << timestamp << ']' << ' ';
}

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	printTime();
	
}