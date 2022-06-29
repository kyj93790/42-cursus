/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:49:47 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 21:12:54 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cout << "Error : argument\n";
		return (0);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// file open
	std::ifstream ifs;
	ifs.open(filename);
	if (ifs.fail()) {
		std::cout << "Error : fail to open file\n";
		return (0);
	}
	std::ofstream ofs;
	ofs.open(filename +  ".replace");
	if (ofs.fail()) {
		std::cout << "Error : fail to open file\n";
		return (0);
	}

	std::string str;	
	while (1) {
		getline(ifs, str);
		if (ifs.eof()) break ;
		if (ifs.fail() || ifs.bad()) {
			std::cout << "Error : read file\n";
			return (0);
		}
		size_t idx;
		while (1) {
			idx = str.find(s1);
			if (idx == std::string::npos) {
				ofs << str << '\n';
				break ;
			}
			str.erase(str.begin() + idx, str.begin() + idx + s1.length());
			str.insert(idx, s2);
		}
	}
	ifs.close();
	ofs.close();
	return (0);
}