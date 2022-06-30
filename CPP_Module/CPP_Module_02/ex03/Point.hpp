/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:39:01 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:41:29 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		~Point();
		Point& operator=(const Point& point);

		static Fixed product(Point const a, Point const b, Point const point);
		static bool bsp(Point const a, Point const b, Point const c, Point const point);
};

#endif