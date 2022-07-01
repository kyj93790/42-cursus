/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:48:39 by yejikim           #+#    #+#             */
/*   Updated: 2022/07/01 12:06:59 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    this->numOfContact = 0;
}

PhoneBook::~PhoneBook()
{
    
}

static std::string inputInfo(std::string field)
{
    std::string s;

    while (1) {
        std::cout << "\t" << field << " : ";
        std::getline(std::cin, s);
        if (std::cin.eof() || std::cin.fail())
        {
            std::cout << "Error\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0) break;
        else std::cout << "\t\t" << field << " can not be empty field\n";
    }
    return (s);
}

void PhoneBook::add()
{
    std::string field[5];

    field[0] = inputInfo("First Name");
    field[1] = inputInfo("Last Name");
    field[2] = inputInfo("Nickname");
    field[3] = inputInfo("Phone Number");
    field[4] = inputInfo("Darkest Secret");
    contacts[numOfContact % 8].setFields(field);
    (numOfContact)++;
    std::cout << "Successfully add new contact !\n\n";
}

void PhoneBook::search()
{
    int num;
    
    num = numOfContact;
    if (numOfContact > 8)
        num = 8;
    std::cout << " ------------------------------------------------------\n";
    std::cout << "| FirstName|  LastName|  NickName|  PhoneNum|DarkSecret|\n";
    for (int i=0; i<num; i++) {
        contacts[i].printFields();
    }
    std::cout << " ------------------------------------------------------\n";
}

void PhoneBook::exit()
{
    std::cout << "EXIT !\n\n";
    std::exit(EXIT_SUCCESS);
}