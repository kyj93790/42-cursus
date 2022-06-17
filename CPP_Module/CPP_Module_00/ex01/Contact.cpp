/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:34:33 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 22:12:54 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
    this->firstName = lastName;
}
void Contact::setNickname(std::string nickname)
{
    this->firstName = nickname;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->firstName = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->firstName = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return (this->firstName);
}
std::string Contact::getLastName() const
{
    return (this->firstName);
}
std::string Contact::getNickname() const
{
    return (this->nickname);
}
std::string Contact::getPhoneNumber() const
{
    return (this->phoneNumber);
}
std::string Contact::getDarkestSecret() const
{
    return (this->darkestSecret);
}