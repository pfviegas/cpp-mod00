/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:12:35 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/06 10:13:26 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::ADD()
{
	str		input[5] = {" ", " ", " ", " ", " "};
	str		text_input[5] = {" Insert first name: ", " Insert last name: ", " Insert nickame: ", " Insert phone number: ", " Insert secret: "};

	system("clear");
	if (index > 7)
		index = 0;
		
	if (contacts[index].Check_Empty())
		std::cout << YELLOW << "Contact limit reached!!!" << RESET << "\tOld contact will be overwritten\n\n";

	for (int i = 0; i < 5; i++)
	{
		while (true)
		{
			std::cout << GREEN << text_input[i] << RESET;
			getline(std::cin, input[i]);
			// verifica se o utilizador fez ctrl+d
			if (std::cin.eof())
				return;
			if ((input[i].find_first_not_of(" \t\n") == std::string::npos))
			{
				system("clear");
				for (int j = 0; j < 5; j++)
				{
					if ((input[j].find_first_not_of(" \t") == std::string::npos))
						break;
					std::cout << GREEN << text_input[j] << RESET << input[j] << std::endl;
				}
			}
			else
				break;
		}
		// ignora se foi introduzido apenas espacos, tab ou enter
	}

	contacts[index].Save_FirstName(input[0]);
	contacts[index].Save_LastName(input[1]);
	contacts[index].Save_Nickname(input[2]);
	contacts[index].Save_PhoneNum(input[3]);
	contacts[index].Save_Secret(input[4]);
	index++;
}

void PhoneBook::Wide_10Char(str str)
{
	if (str.length() <= 10)
	{
		std::cout << std::setw(10) << str;
		return ;
	}
	std::cout << std::setw(9) << str.substr(0, 9);
	std::cout << std::setw(1) << '.';
	return ;
}

void	PhoneBook::List_All()
{
	int	index = -1;

	system("clear");
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	std::cout << "|" << GREEN << "   Index  " << RESET << "|" << GREEN << "First Name" << RESET << "|" << GREEN << "Last Name " << RESET << "|" << GREEN << " NickName " << RESET << "|" << std::endl;
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	while (++index < 8 && contacts[index].Check_Empty())
	{
		std::cout << "|";
		std::cout << GREEN << std::setw(10) << index + 1 << RESET;
		std::cout << '|';
		Wide_10Char(contacts[index].Get_Data("First"));
		std::cout << '|';
		Wide_10Char(contacts[index].Get_Data("Last"));
		std::cout << '|';
		Wide_10Char(contacts[index].Get_Data("Nick"));
		std::cout << '|';
		std::cout << '\n';
		std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	}
}

void	PhoneBook::SEARCH()
{
	str	input = "0";
	int numericInput = 0;
	
	while (true)
	{
		List_All();
		if (!contacts[0].Check_Empty())
			return;
		std::cout << "\nType a number between " << GREEN << "1" << RESET << " and " << GREEN << "8" << RESET << " to select a contact or " << GREEN << "0" << RESET << " to return.\n\n$ ";
		getline(std::cin, input);
		// verifica se o utilizador fez ctrl+d
		if (std::cin.eof())
		{
			break;
		}
		if (input.compare("0") == 0)
			return;

		numericInput = std::atoi(input.c_str());

		if (numericInput > 0 && numericInput < 9)	
		{
			if (contacts[numericInput - 1].Check_Empty())
				contacts[numericInput - 1].Print_Contact();
			else
			{
				std::cout << YELLOW << "\nEmpty INDEX!!!" << RESET << std::endl;
				getline(std::cin, input);
			}	
		}
	}
}
