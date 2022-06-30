/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:49:07 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:51:13 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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