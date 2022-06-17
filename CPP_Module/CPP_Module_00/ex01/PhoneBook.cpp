/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:48:39 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 22:11:17 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->numOfContact = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add()
{
    contacts[this->numOfContact % 8].setFirstName();
    contacts[this->numOfContact % 8].setLastName();
    contacts[this->numOfContact % 8].setNickname();
    contacts[this->numOfContact % 8].setPhoneNumber();
    contacts[this->numOfContact % 8].setDarkestSecret();
    (this->numOfContact)++;
}
