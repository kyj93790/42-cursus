/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:54:55 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 22:42:00 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;

    while (1)
    {
        std::cin >> cmd;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (cmd.compare("ADD") == 0)
            phoneBook.add();
        else if (cmd.compare("SEARCH") == 0)
            phoneBook.search();
        else if (cmd.compare("EXIT") == 0)
            std::exit(EXIT_SUCCESS);
    }
}