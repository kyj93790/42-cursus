/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:30 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:02:33 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _num(0)
{
}

Fixed::Fixed(const int iNum)
{
	_num = (iNum * (1 << _fractionalBits));
}

Fixed::Fixed(const float fNum)
{
	_num = roundf(fNum * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& fixed)
{
	(*this) = fixed;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
	return ((float)_num / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_num / (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const
{
	return (_num);
}

void Fixed::setRawBits(int const raw)
{
	_num = raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	_num = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return (_num > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (_num < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (_num >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (_num <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (_num == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (_num != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(_num + fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(_num - fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed result(toFloat() * fixed.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed result(toFloat() / fixed.toFloat());
	return (result);
}

Fixed& Fixed::operator++()
{
	_num++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	_num--;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed temp(*this);
	_num++;
	return (temp);
}

const Fixed Fixed::operator--(int)
{
	const Fixed temp(*this);
	_num--;
	return (temp);
}

Fixed& Fixed:: min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2) return (f1);
	else return (f2);
}

const Fixed& Fixed:: min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2) return (f1);
	else return (f2);
}

Fixed& Fixed:: max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2) return (f1);
	else return (f2);
}

const Fixed& Fixed:: max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2) return (f1);
	else return (f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
