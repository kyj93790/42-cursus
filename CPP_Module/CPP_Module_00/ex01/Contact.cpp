/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:34:33 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/27 17:23:35 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

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

void Contact::printFields(void)
{
    std::cout << "|";
    std::cout.width(10); std::cout << std::right << firstName << '|';
    std::cout.width(10); std::cout << std::right << lastName << '|';
    std::cout.width(10); std::cout << std::right << nickname << '|';
    std::cout.width(10); std::cout << std::right << phoneNumber << '|';
    std::cout.width(10); std::cout << std::right << darkestSecret << "|\n";
}