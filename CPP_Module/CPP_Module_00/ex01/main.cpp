/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:54:55 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/16 20:10:38 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void	execute_add(PhoneBook phoneBook)
{
	// first name
	while (1)
	{
		
	}
	// last name
	while (1)
	{
		
	}
	// nickname
	while (1)
	{
		
	}
	// phone number
	while (1)
	{
		
	}
	// darkest secret
	while (1)
	{
		
	}
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string cmd;
	
	while (std::cin >> cmd)
	{
		if (cmd.compare("ADD") == 0) {
			execute_add(phoneBook);
		} else if (cmd.compare("SEARCH") == 0) {
			
		} else if (cmd.compare("EXIT") == 0) {
			
		}
	}
	
}