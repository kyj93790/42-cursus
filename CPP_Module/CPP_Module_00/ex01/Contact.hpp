/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:51 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/27 17:16:13 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
  private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

  public:
    Contact();
    ~Contact();
    void  setFields(std::string field[5]);
    void  printFields(void);
};