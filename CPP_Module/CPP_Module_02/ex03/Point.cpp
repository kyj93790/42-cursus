/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:51:06 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:49:03 by yejin            ###   ########.fr       */
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