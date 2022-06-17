/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:54:55 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 15:53:30 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;

    while (std::cin >> cmd)
    {
        if (cmd.compare("ADD") == 0)
            phoneBook.add();
        else if (cmd.compare("SEARCH") == 0)
            phoneBook.search();
        else if (cmd.compare("EXIT") == 0)
            exit(EXIT_SUCCESS);
    }
    std::cout << "Error: end of file\n";
    exit(EXIT_FAILURE);
}