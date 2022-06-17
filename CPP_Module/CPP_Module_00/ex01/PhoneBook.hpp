/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:39:40 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/17 22:48:56 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
  private:
    int numOfContact;
    Contact contacts[8];

  public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void addField();
    void search();
    void exit();
};
