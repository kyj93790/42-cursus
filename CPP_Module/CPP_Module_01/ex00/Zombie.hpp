/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:28:05 by yejin             #+#    #+#             */
/*   Updated: 2022/06/29 00:34:37 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string name;
		void announce(void);
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif