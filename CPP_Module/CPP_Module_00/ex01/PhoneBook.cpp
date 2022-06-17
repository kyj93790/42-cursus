/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:48:39 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 22:49:00 by yejikim          ###   ########.fr       */
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

void PhoneBook::addField(std::string field)
{
    string s;

    while (1)
    {
        std::cout << "\tFirst Name : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << "First Name can not be empty field\n";
    }
}

void PhoneBook::add()
{
    std::string s;

    while (1)
    {
        std::cout << "\tFirst Name : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << "First Name can not be empty field\n";
    }
    while (1)
    {
        std::cout << "\tLast Name : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setLastName(s);
        else
            std::cout << "Last Name can not be empty field\n";
    }
    while (1)
    {
        std::cout << "\tNickname : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setNickname(s);
        else
            std::cout << "Nickname can not be empty field\n";
    }
    while (1)
    {
        std::cout << "\tPhone Number : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << "Phone Number can not be empty field\n";
    }
    while (1)
    {
        std::cout << "\tFirst Name : ";
        std::cin >> s;
        if (std::cin.eof())
        {
            std::cout << "Error: end of file\n";
            std::exit(EXIT_FAILURE);
        }
        if (s.length() > 0)
            contacts[numOfContact % 8].setFirstName(s);
        else
            std::cout << "First Name can not be empty field\n";
    }
    (numOfContact)++;
}
