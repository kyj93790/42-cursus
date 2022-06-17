/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:07:37 by yejin             #+#    #+#             */
/*   Updated: 2022/06/15 15:42:58 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		std::string s;
		for (int i=1; i<argc; i++) {
			for (int j=0; argv[i][j] != '\0'; j++) {
				s += toupper(argv[i][j]);
			}
		}
		std::cout << s << '\n';
	}
	return (0);
}