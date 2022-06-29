/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:38:27 by yejin             #+#    #+#             */
/*   Updated: 2022/06/30 01:20:25 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int _num;
		static const int _fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed& operator=(const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif