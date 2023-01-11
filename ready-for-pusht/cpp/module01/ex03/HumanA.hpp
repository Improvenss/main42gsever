/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:30:52 by gsever            #+#    #+#             */
/*   Updated: 2023/01/03 12:55:04 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;// ref olarak aldigimiz icin yerdeki sopayi aldigimizi ve artik yerde olmadinigini dusunuyrouz.
	public:
		HumanA( std::string name, Weapon &weapon);
		~HumanA( void );
		void	attack( void );
};

#endif