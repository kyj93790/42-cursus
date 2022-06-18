/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:39:40 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/18 22:22:32 by yejikim          ###   ########.fr       */
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
    void search();
    void exit();
};
