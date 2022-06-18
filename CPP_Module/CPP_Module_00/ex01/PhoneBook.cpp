/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:48:39 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/18 22:29:51 by yejikim          ###   ########.fr       */
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

static string inputInfo(std::string field)
{
    std::string s;

    std::cout << "\t" << field << " : ";
    std::cin >> s;
    if (std::cin.eof())
    {
        std::cout << "Error: end of file\n";
        std::exit(EXIT_FAILURE);
    }
}

static void addFirstName(std::string s)
{
    while (1)
    {
        std::cout << "\t" << field << " : "; 
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << field << " can not be empty field\n";
    }
}

void PhoneBook::add()
{
    std::string s;

    while (1) {
        s = inputInfo("First Name");
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << field << " can not be empty field\n";
    }
     while (1) {
        s = inputInfo("Last Name");
        if (s.length() > 0)
            contacts[numOfContact % 8].setLastName(s);
        else
            std::cout << field << " can not be empty field\n";
    }
    addField("Nickname");
    addField("Phone Number");
    addField("Darkest Secret");
    (numOfContact)++;
}
