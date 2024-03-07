/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:09:42 by paulo             #+#    #+#             */
/*   Updated: 2024/03/05 16:51:19 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int		main()
{
	PhoneBook	phonebook;
	str			option;

	while (option.compare("EXIT") != 0)
	{
		system("clear");
		std::cout << "         Please type:\n" << std::endl;
		std::cout << GREEN << " ADD" << RESET << "\tto add a contact." << std::endl;
		std::cout << GREEN << " SEARCH" << RESET << "\tto search a contact." << std::endl;
		std::cout << GREEN << " EXIT" << RESET << "\tto quit.\n\n$ ";
		getline(std::cin, option);
		// verifica se o utilizador fez ctrl+d
		if (std::cin.eof())
			break;
		if (!option.compare("ADD"))
			phonebook.ADD();
		if (!option.compare("SEARCH"))
			phonebook.SEARCH();
		std::cin.clear();
	}
	std::cout << std::endl;
}
