/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:59:19 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 14:50:56 by yejin            ###   ########.fr       */
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
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "WARNING : think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	int lv = (level == "DEBUG") * 1 \
				+ (level == "INFO") * 2 \
				+ (level == "WARNING") * 3 \
				+ (level == "ERROR") * 4;
	switch(lv)
	{
		case 1 :
			(this->*fp[0])();
			break ;
		case 2 :
			(this->*fp[1])();
			break ;
		case 3 :
			(this->*fp[2])();
			break ;
		case 4 :
			(this->*fp[3])();
			break ;
	}
}