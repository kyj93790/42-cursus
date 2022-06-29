/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:23:54 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 15:05:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Error : argument\n";
		return (0);
	}
	harl.complain(argv[1]);
	return (0);
}