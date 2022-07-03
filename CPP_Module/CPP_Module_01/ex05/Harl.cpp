/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:59:19 by yejin             #+#    #+#             */
/*   Updated: 2022/07/03 17:42:37 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	fp[0] = &Harl::debug;
	fp[1] = &Harl::info;
	fp[2] = &Harl::warning;
	fp[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!\n\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\nthink I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
	int lv = (level == "DEBUG") * 1 \
				+ (level == "INFO") * 2 \
				+ (level == "WARNING") * 3 \
				+ (level == "ERROR") * 4;
	if (lv == 0) {
		std::cout << "Error: invalid complain\n";
		return ;
	}
	(this->*fp[lv - 1])();
}