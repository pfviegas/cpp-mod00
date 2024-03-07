/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:25:47 by paulo             #+#    #+#             */
/*   Updated: 2024/03/05 15:11:35 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Contacts.hpp"

#define GREEN "\033[32;1m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

typedef std::string	str;

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
		void	List_All();
		void	Wide_10Char(str str);

	public:
		PhoneBook();
		~PhoneBook();
		void SEARCH();
		void ADD();
};

# endif