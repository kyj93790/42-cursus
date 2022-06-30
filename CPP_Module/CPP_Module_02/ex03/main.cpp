/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:33 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 22:46:07 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a(5, 0);
	Point b(15, 0);
	Point c(10, 9);

	Point p1(8, 4);		// in
	Point p2(17, 4);	// out
	Point p3(15, 0);	// vertex
	Point p4(10, 0);	// edge


	std::cout << std::boolalpha << Point::bsp(a, b, c, p1) << '\n';
	std::cout << std::boolalpha << Point::bsp(a, b, c, p2) << '\n';
	std::cout << std::boolalpha << Point::bsp(a, b, c, p3) << '\n';
	std::cout << std::boolalpha << Point::bsp(a, b, c, p4) << '\n';
	return (0);
}