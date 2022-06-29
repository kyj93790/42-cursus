/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:27 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 04:18:04 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _num;
		static const int _fractionalBits;
	public:
		Fixed();
		Fixed(const int iNum);
		Fixed(const float fNum);
		Fixed(const Fixed &fixed);
		~Fixed();
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator=(const Fixed& fixed);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif