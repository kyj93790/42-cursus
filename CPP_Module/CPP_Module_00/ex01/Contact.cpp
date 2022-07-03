/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:34:33 by yejikim           #+#    #+#             */
/*   Updated: 2022/07/03 19:58:53 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFields(std::string field[5])
{
    firstName = field[0];
    lastName = field[1];
    nickname = field[2];
    phoneNumber = field[3];
    darkestSecret = field[4];
}

static void printField(std::string field)
{
    std::string s;

    if (field.length() > 10)
    {
        s = field.substr(0, 9);
        s += '.';
    }
    else
        s = field;
    std::cout << std::setw(10) << std::right << s << '|';
}

void Contact::printDefaultFields(int idx)
{
    std::cout << "|";
    std::cout << std::setw(10) << std::right << idx << '|';
    printField(firstName);
    printField(lastName);
    printField(nickname);
    std::cout << "\n";
}

void Contact::printAllFields(void)
{
    std::cout << "First Name : " << firstName << '\n';
    std::cout << "Last Name : " << lastName << '\n';
    std::cout << "Nickname : " << nickname << '\n';
    std::cout << "Phone Number : " << phoneNumber << '\n';
    std::cout << "Darkest Secret : " << darkestSecret << '\n';
}