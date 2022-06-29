/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:30 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 04:22:18 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int iNum)
{
	std::cout << "Int constructor called\n";
	_num = (iNum * (1 << _fractionalBits));
}

Fixed::Fixed(const float fNum)
{
	std::cout << "Float constructor called\n";
	_num = roundf(fNum * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	(*this) = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const
{
	return ((float)_num / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_num / (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	_num = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (_num);
}

void Fixed::setRawBits(int const raw)
{
	_num = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}