/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:51:06 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:43:51 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) :_x(x), _y(y)
{
}

Point::Point(const Point& point)
{
	(*this) = point;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& point)
{
	_x = point._x;
	_y = point._y;
	return (*this);
}

Fixed Point::product(Point const a, Point const b, Point const point)
{
	return ((a._x - point._x) * (b._y - point._y) - (a._y - point._y) * (b._x - point._x));
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed pa = product(a, b, point);
	Fixed pb = product(b, c, point);
	Fixed pc = product(c, a, point);

	if (pa.getRawBits() > 0 && pb.getRawBits() > 0 && pc.getRawBits() > 0) return (true);
	else if (pa.getRawBits() < 0 && pb.getRawBits() < 0 && pc.getRawBits() < 0) return (true);
	return (false);
}